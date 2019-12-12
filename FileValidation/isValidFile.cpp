/****************************************************
* @file                isValidFile.cpp
* @brief               Implmentation for isValidFile
* @created             12/12/2019
* @author              Amogh Kudari
*****************************************************/

#include <iostream>
#include <fstream>

#if __cplusplus >= 201703L // C++ 17 support
  #ifndef __has_include
    static_assert(false, "__has_include not supported");
  #else
    #if __has_include(<filesystem>)
      #include <filesystem>
      namespace fs = std::filesystem;
    #elif __has_include(<experimental/filesystem>)
      #include <experimental/filesystem>
      namespace fs = std::experimental::filesystem;
    #endif
  #endif
#else
  #include <sys/stat.h>
#endif

/**
 * @brief Check if valid file
 * @return valid or not
 */
bool IsValidFile(const char* path)
{
#if __cplusplus >= 201703L // C++ 17 support
  std::cout << "C++ 17 supported\n";
  fs::path file_path= path;
  std::error_code ec;
  if(!fs::is_regular_file(file_path, ec)) {
    std::cout << "Error: Not a regular file\n";
    return false;
  }
  std::ifstream ifs_file(path);
  if(!ifs_file.good() || !ifs_file.is_open()) {
    return false;
  }
  return true;
#else
  std::cout << "C++ 98 supported\n";
  FILE* fp = fopen(path,"r");
  struct stat file_status;
  int file_id = fileno(fp);
  if(-1 == file_id) {
    std::cout << "Error: Invalid file\n";
    return false;
  }
  int status = fstat(file_id, &file_status);
  fclose(fp);
  if(-1 == status) {
    std::cout << "Error: Invalid file\n";
    return false;
  }
  if(!S_ISREG(file_status.st_mode)) {
    std::cout << "Error: Not a regular file\n";
    return false;
  }
  return true;
#endif
}
