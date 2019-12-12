/****************************************************
* @file                FileValidation_Application.cpp
* @brief               Driver for isValidFile
* @created             12/12/2019
* @author              Amogh Kudari
*****************************************************/

#include "isValidFile.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
  if(argc < 2) {
    std::cout << "Please enter file to be checked for and try again!!!\n";
    exit(0);
  }
  std::cout << "File Name: " << argv[1] << "\n";
  bool isvalid = IsValidFile(argv[1]);
  if(isvalid)
    std::cout << "Valid File\n";
  else
    std::cout << "InValid File\n";
}