#include<iostream>
using namespace std;

template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
};

void inOrder(BinaryTreeNode<int>* root , int & count) {
    if (root == nullptr) {
        return;
    }

    inOrder(root->left, count);
   if(root->left == nullptr && root->right == nullptr){
       count ++;
   }
    inOrder(root->right, count);
}

int noOfLeafNodes(BinaryTreeNode<int> *root){
    int count = 0;
    inOrder(root,count);
    return count;
}

int main() {
  // Create a sample binary tree
  BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
  root->left = new BinaryTreeNode<int>(2);
  root->right = new BinaryTreeNode<int>(3);
  root->left->left = new BinaryTreeNode<int>(4);
  root->left->right = new BinaryTreeNode<int>(5);

  // Call the noOfLeafNodes function
  int leafCount = noOfLeafNodes(root);

  // Expected output: 3 (Leaf nodes are 4, 5, and 3)
  if (leafCount == 3) {
    cout << "Test case passed!" << endl;
  } else {
    cout << "Test case failed. Expected 3 leaf nodes, got " << leafCount << endl;
  }
}
