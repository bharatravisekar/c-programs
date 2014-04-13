#include <iostream>
#include <string>

/*
 * @author Bharat Ravisekar (rbharat@gmail.com)
 * */

/* A DLLNode */

using namespace std;

class DLLNode {
  public: 
  int val;
  DLLNode* prev;
  DLLNode* next;

  DLLNode();
  DLLNode(int _val, DLLNode* _prev, DLLNode* _next);
};

/* Constructor */
DLLNode::DLLNode() {
  DLLNode(val, NULL, NULL);
}

DLLNode::DLLNode(int _val, DLLNode* _prev, DLLNode* _next) {
  this->val = _val;
  this->prev = _prev;
  this->next = _next;
}

typedef DLLNode* DLLNodePtr;

DLLNodePtr head = NULL;
DLLNodePtr tail = NULL;

void add_dll_node(int value) {
  DLLNodePtr nodePtr = new DLLNode();
  nodePtr->val = value;
    
  if (head == NULL) {
    head = nodePtr;
  } else {
    tail->next = nodePtr;
    nodePtr->prev = tail;
  }

  tail = nodePtr;
  cout << "Added element: " << value << endl;
}

int pop_dll_node() {
  if (head == NULL) {
    return -1;
  } else {
    int value = head->val;
    DLLNodePtr oldHead = head;
    head = head->next;
    delete(oldHead);

    cout << "Popped element: " << value << endl;
    return value;
  }
}

void print_dll() {
  DLLNodePtr temp = head;
  cout << "Linked list: ";
  while(temp != NULL) {
    cout << temp->val << " ";
    temp = temp->next;
  }

  cout << endl;
}

