#include "i_to_a.h"
#include "a_to_i.h"
#include "reverse.h"
#include "linked_list.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* args[]) {
  cout << "Parameters: ";
  for (int i = 0; i < argc; i++) {
    cout << args[i] << " ";
  }
  cout << "\n";

  if (argc == 1) {
    cout << "Please provide an option" << endl;
    return 1;
  }


  if (strcmp(args[1], "1") == 0) {
    cout << reverse(args[2]) << endl;
  } else if (strcmp(args[1], "2") == 0) {
    cout << a_to_i(args[2]) << endl;
  } else if (strcmp(args[1], "3") == 0) {
    cout << i_to_a(a_to_i(args[2])) << endl;
  } else if (strcmp(args[1], "4") == 0) {
    add(3);
    add(8);
    add(9);
    add(1);
    add(4);
    add(6);
    pop();
    pop();
    print();
  } else {
    cout << "Unknown option" << endl;
  }
}

