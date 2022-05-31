#include <iostream>
#include "BST.h"
using std::cout;
using std::endl;

int main() {
  BST root;
  /*root.insert(4);
  root.insert(2);
  root.insert(6);
  root.insert(1);
  root.insert(3);
  root.insert(5);
  root.insert(7);*/

  root.print();
  cout << endl << "Root Height: " <<  root.height() << endl;

  BST copy(root);
  //copy.insert(9);

  copy.print();
  cout << endl << "Copy Height:  " << copy.height() << endl;
}

//Other code that works but hated it 
/*if(original != nullptr)
  {
    cout << "call" << endl;
    copy = new TreeNode(original->data);
    cout << original->data << " " << copy->data << endl;
    copyBST(original->left, copy->left);
    copyBST(original->right, copy->right);
  }*/

  /*if(original->left != nullptr)
  {
    copy->left = new TreeNode(original->left->data);
    copyBST(original->left, copy->left);
  }
  if(original->right != nullptr)
  {
    copy->right = new TreeNode(original->right->data);
    copyBST(original->right, copy->right);
  }*/