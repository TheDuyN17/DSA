#include <iostream>

// Ð?nh nghia l?p Node d? bi?u di?n các nút trong cây
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};


// Hàm th?c hi?n postorder traversal c?a cây nh? phân
void postorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    // Duy?t subtree bên trái
    postorderTraversal(root->left);

    // Duy?t subtree bên ph?i
    postorderTraversal(root->right);

    // Truy c?p nút hi?n t?i
    std::cout << root->data << " ";
}
int main (){
    //T?o cây nh? phân m?u
  Node *root = new Node (6);
  root->left = new Node (2);
  root->right = new Node (7);
  root->left->left = new Node (1);
  root->left->right = new Node (4);
  root->left->right->left = new Node (3);
  root->left->right->right = new Node (5);
  root->right->right = new Node (9);
  root->right->right->left = new Node (8);
  // Bi?u di?n Postorder Traversal
  std::cout << "Postorder traversal: ";
  postorderTraversal(root);
  std::cout << std::endl;

  return 0;
}
