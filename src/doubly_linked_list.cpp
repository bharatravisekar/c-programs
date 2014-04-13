#include <iostream>
#include <string>

/*
 * @author Bharat Ravisekar (rbharat@gmail.com)
 * */

/* A Node */

using namespace std;

class Node {
  public: 
  int val;
  Node* prev;
  Node* next;

  Node();
  Node(int _val, Node* _prev, Node* _next);
};

/* Constructor */
Node::Node() {
  Node(val, NULL, NULL);
}

Node::Node(int _val, Node* _prev, Node* _next) {
  this->val = _val;
  this->prev = _prev;
  this->next = _next;
}

typedef Node* NodePtr;

NodePtr head = NULL;
NodePtr tail = NULL;

void add_dll_node(int value) {
  NodePtr nodePtr = new Node();
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
    NodePtr oldHead = head;
    head = head->next;
    delete(oldHead);

    cout << "Popped element: " << value << endl;
    return value;
  }
}

void print_dll() {
  NodePtr temp = head;
  cout << "Linked list: ";
  while(temp != NULL) {
    cout << temp->val << " ";
    temp = temp->next;
  }

  cout << endl;
}

