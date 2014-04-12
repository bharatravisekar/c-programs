#include <iostream>
#include "a_to_i.h"
#include <string>

using namespace std;

int a_to_i(string str) {
  int result = 0;

  for(int i = 0; i < str.length(); i++) {
    result = (result * 10) + (str[i] - '0');
  }

  return result;
}

