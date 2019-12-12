# FileValidation - Simple C++17/98 Application to check if file is Valid.
This is a simple C++17/98 application to validate a file for it's existence and validity.
Provisions have been made to incorporate C++ 17 filesystem API's as well as C++ 98's FILE stream.

The function isValidFile validates the file and returns true if file is valid
FnName      <isValidFile>
InputParam  <const char *>  => File Name with path
ReturnValue <bool> => true if file is valid else false.

Compile and Execute
1. Make build directory and cd to it
2. Use -DCOMPILER_OPTION to specify if using C++ 17 Compatible compiler by
   cmake -DCOMPILER_OPTION='-std=c++17' ..
   OR
   Give empty -DCOMPILER_OPTION to use C++ 98 compiler
   cmake ..
3. Execute FileValidator application by
   ./FileValidator <path to file>
