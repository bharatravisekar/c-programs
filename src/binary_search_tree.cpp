#include <iostream>

using namespace std;

class BTNode {
  public:
  int val;
  BTNode* parent;
  BTNode* left;
  BTNode* right;

  BTNode();
  BTNode(int _val, BTNode* _parent, BTNode* _left, BTNode* _right);
};

BTNode::BTNode(int _val, BTNode* _parent, BTNode* _left, BTNode* _right) {
  this->val = _val;
  this->parent = _parent;
  this->left = _left;
  this->right = _right;
}

BTNode::BTNode() {
  BTNode(-1, NULL, NULL, NULL);
}

typedef BTNode* BTNodePtr;

BTNodePtr root = NULL;

void insert_into_bstree_recur_int(BTNodePtr newNode, BTNodePtr tempParent) {
  if (newNode->val <= tempParent->val) {
    if (tempParent->left == NULL) {
      tempParent->left = newNode;
      newNode->parent = tempParent;
    } else {
      insert_into_bstree_recur_int(newNode, tempParent->left);
    }
  } else {
    if (tempParent->right == NULL) {
      tempParent->right = newNode;
      newNode->parent = tempParent;
    } else {
      insert_into_bstree_recur_int(newNode, tempParent->right);
    }
  }
}

void insert_into_bstree_recur(int val) {
  BTNodePtr newNode = new BTNode(val, NULL, NULL, NULL);
  if (root == NULL) {
    root = newNode;
  } else {
    insert_into_bstree_recur_int(newNode, root);
  }
}

void insert_into_bstree(int val) {
  cout << "Inserting " << val << endl;
  BTNodePtr newNode = new BTNode(val, NULL, NULL, NULL);
  if (root == NULL) {
    root = newNode;
  } else {
    BTNodePtr tempParent = root;
    while (tempParent != NULL) {
      if (val <= tempParent->val) {
        if (tempParent->left == NULL) {
          tempParent->left = newNode;
          newNode->parent = tempParent;
          break;
        } else {
          tempParent = tempParent->left;
        }
      } else {
        if (tempParent->right == NULL) {
          tempParent->right = newNode;
          newNode->parent = tempParent;
          break;
        } else {
          tempParent = tempParent->right;
        }
      }
    }
    newNode->parent = tempParent;
   }
}

void print_in_order_bst_int(BTNodePtr nodePtr) {
  if(nodePtr != NULL) {
    print_in_order_bst_int(nodePtr->left);
    cout << nodePtr->val << " ";
    print_in_order_bst_int(nodePtr->right);
  } 
}

void print_in_order_bstree() {
  cout << "In-order traversal: " << endl;
  print_in_order_bst_int(root);
  cout << endl;
}

void print_pre_order_bst_int(BTNodePtr nodePtr) {
  if(nodePtr != NULL) {
    cout << nodePtr->val << " ";
    print_pre_order_bst_int(nodePtr->left);
    print_pre_order_bst_int(nodePtr->right);
  } 
}

void print_pre_order_bstree() {
  cout << "Pre-order traversal: " << endl;
  print_pre_order_bst_int(root);
  cout << endl;
}


void print_post_order_bst_int(BTNodePtr nodePtr) {
  if(nodePtr != NULL) {
    print_post_order_bst_int(nodePtr->left);
    print_post_order_bst_int(nodePtr->right);
    cout << nodePtr->val << " ";
  } 
}

void print_post_order_bstree() {
  cout << "Post-order traversal: " << endl;
  print_post_order_bst_int(root);
  cout << endl;
}

