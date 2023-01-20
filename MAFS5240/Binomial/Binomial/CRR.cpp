// #include "CRR.h"
#include <iostream>
#include <math.h>

#define	SUCCESS	0
#define	FAILURE	-1

enum	CALL_PUT	{Call, Put};
enum	AMER_EURO	{European, American};

#define OPTION_MULTIPLIER(x)	((x) == Call ? 1.0 : -1.0)
#define MAX(a,b) (((a) > (b)) ? (a) : (b))


using namespace std;

int CRRBinomialTree(
	CALL_PUT	callOrPut,				/* (I) put or call flag (use Call or Put) */
	AMER_EURO	amerOrEuro,				/* (I) option type (use European, American) */
	double		spotPrice,				/* (I) spot price of underlying */
	double		strike,					/* (I) strike price of option */
	double		maturity,				/* (I) maturity of option in years */
	double		vol,					/* (I) annual volatility of underlying */
	double		rate,					/* (I) annual continuous compounded discount rate */
	int			nStep,					/* (I) number of steps in tree */
	double		*value)					/* (O) option value */
/*-----------------------------------------------------------------------------
** FUNCTION:	CRRBinomialTree.
**
** DESCRIPTION:	Calculates the price of an option using the Cox, Ross and Rubinstein
**				binomial tree model.
**
** RETURNS:		SUCCESS and the premium, otherwise FAILURE.                                  
**
**---------------------------------------------------------------------------*/
{

	if (nStep <= 0)
	{
		cout << "CRRBinomialTree: Negative number of steps." << endl;
		return FAILURE;
	}            
	
	if (spotPrice <= 0.0 || strike <= 0.0 || maturity < 0.0 || vol < 0.0 || rate < 0.0)
	{
		cout << "CRRBinomialTree: Invalid input detected." << endl;
		return FAILURE;
	}

	const double delta_t = maturity / nStep;
	const double u = exp(vol * sqrt(delta_t));
	const double d = 1 / u;
	const double p = (exp(rate * delta_t) - d) / (u - d);
	
	const size_t price_size = nStep + 1;
	double *stock_price = new double[price_size];
	double *option_price = new double[price_size];

	for (int curr_step=nStep; curr_step>=0; --curr_step) {

		for (size_t i=0; i!=curr_step+1; ++i) {

			stock_price[i] = spotPrice * pow(u, (nStep - i)) * pow(d, i);

			if (curr_step == nStep) {
				if (callOrPut == Call)
					option_price[i] = MAX(stock_price[i] - strike, 0);
				else if (callOrPut == Put)
					option_price[i] = MAX(strike - stock_price[i], 0);
			}
			else {

				option_price[i] = exp(- rate * delta_t) * (p*(option_price[i]) + (1-p)*(option_price[i+1]));
				
				if (amerOrEuro == American) {
					double int_val;
					if (callOrPut == Call)
						int_val = MAX(stock_price[i] - strike, 0);
					else if (callOrPut == Put)
						int_val = MAX(strike - stock_price[i], 0);
					option_price[i] = MAX(option_price[i], int_val);
				}
			}
		}
	}

	*value = option_price[0];

	delete [] stock_price;
	stock_price = 0;
	delete [] option_price;
	option_price = 0;

	return SUCCESS;
}

int main() {
	double value = 0;
	CRRBinomialTree(Call, European, 100, 100, 1, 0.2, 0.03, 3, &value);
	cout << value << endl;

};