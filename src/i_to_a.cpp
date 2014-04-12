#include <iostream>
#include <string>
#include "i_to_a.h"
#include "reverse.h"

using namespace std;

string i_to_a(int i)
{
  string result = "";

  while(i != 0) {
    result.append(to_string(i % 10));
    i = i / 10;
  }

  return reverse(result);
}

