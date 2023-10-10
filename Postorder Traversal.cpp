#include <iostream>

// �?nh nghia l?p Node d? bi?u di?n c�c n�t trong c�y
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


// H�m th?c hi?n postorder traversal c?a c�y nh? ph�n
void postorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    // Duy?t subtree b�n tr�i
    postorderTraversal(root->left);

    // Duy?t subtree b�n ph?i
    postorderTraversal(root->right);

    // Truy c?p n�t hi?n t?i
    std::cout << root->data << " ";
}
int main (){
    //T?o c�y nh? ph�n m?u
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
