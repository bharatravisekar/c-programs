#include "i_to_a.h"
#include "a_to_i.h"
#include "reverse.h"
#include "templates.h"
#include "doubly_linked_list.h"
#include "binary_search_tree.h"
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
    add_dll_node(3);
    add_dll_node(8);
    add_dll_node(9);
    add_dll_node(1);
    add_dll_node(4);
    add_dll_node(6);
    pop_dll_node();
    pop_dll_node();
    print_dll();
  } else if (strcmp(args[1], "5") == 0) {
    test();
  } else if (strcmp(args[1], "6") == 0) {
    insert_into_bstree(6);
    insert_into_bstree(2);
    insert_into_bstree(8);
    insert_into_bstree(4);
    insert_into_bstree(1);
    insert_into_bstree(0);
    insert_into_bstree(9);
    print_in_order_bstree();
    print_pre_order_bstree();
    print_post_order_bstree();
  } else {
    cout << "Unknown option" << endl;
  }
}

