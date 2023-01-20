// Building the DLL
// 1. Header with exported structures
// int __declspec(dllexport) test_func(int a);
// Use "__declspec(dllexport)" to export functions or classes to DLL
// 2. C++ source files implementing exported functions
// 3. Compiler produces .obj file for each .cpp file
// 4. Liner combines .obj module producing DLL
// 5. Linker also produces .lib file

// Building the EXE
// 6. Header with inported structures
// 7. C++ source files referencing imported functions
// 8. Compiler produces .obj file for each .cpp file
// 9. Linker combines .obj modules resolving references to imported functions
//    useing .lib to produce .exe (containing import list of DLLs)

// Running the application
// 10. Loader creates address space for the .exe
// 11. Loader loads required DLLs into address space

// Unit Test
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTest {
    TEST_CLASS(UnitTest1) {
        public:
        TEST_METHOD(FINDMAX) {
            int a[] = {1, 23, 4, 5, 10};
            Assert::IsTrue(Max(a, 5) == 23);
        }
    }
}