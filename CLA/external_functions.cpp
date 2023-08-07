// Check for external functions for use within ADL file.
#ifndef EXTERNAL_FUNC_CPP
#define EXTERNAL_FUNC_CPP

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

namespace adl {

  std::string toupper(std::string s) {
    for(int i = 0; i < s.size(); i++) {
      s[i] = std::toupper(s[i]);
    }
    return s;
  }

  std::string tolower(std::string s) {
    for(int i = 0; i < s.size(); i++) {
      s[i] = std::tolower(s[i]);
    }
    return s;
  }

  int check_function_table(std::string id) {
    std::ifstream fin("CLA/ext_lib.txt");
    if(!fin.good()) {
      // std::cerr << "ERROR: FILE NOT FOUND.\n";
    }
    std::string input;

    while(fin >> input) {
      if(id == input) {
        std::cout << "function " << id << " is REGISTERED\n";
        fin.close();
        return 0;
      }
    }
    std::cout << "ERROR: external function " << id << " is not found\n";
    fin.close();
    return 1;
  }

  int check_property_table(std::string id) {
    std::ifstream fin("CLA/property_vars.txt");
    if(!fin.good()) {
      // std::cerr << "ERROR: FILE NOT FOUND.\n";
    }
    std::string input;
    id = toupper(id);

    while(fin >> input) {
      input = toupper(input);
      if(id == input) {
        // std::cerr << id << " is a PROPERTY\n";
        fin.close();
        return 0;
      }
    }
    // std::cerr << id << " is not a property\n";
    fin.close();
    return 1;
  }

  int check_object_table(std::string id) {
//    std::string path = ""  // Need to find the dir that the libraries are in.
    std::ifstream fin("CLA/ext_objs.txt");
    if(!fin.good()) {
      // std::cerr << "ERROR: FILE NOT FOUND.\n";
    }
    std::string input;
    id = toupper(id);

    while(fin >> input) {
      input = toupper(input);
      if(id == input) {
        // std::cerr << id << " is a predefined OBJECT\n";
        fin.close();
        return 0;
      }
    }
    // std::cerr << id << " is not a predefined OBJECT\n";
    fin.close();
    return 1;
  }
} // end namespace adl
#endif
