#include <iostream>

using namespace std;

// Định nghĩa lớp Node để biểu diễn các nút trong cây
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

// Hàm để thêm một nút mới vào cây
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    } else {
        if (value < root->data) {
            root->left = insert(root->left, value);
        } else {
            root->right = insert(root->right, value);
        }
        return root;
    }
}

// Hàm để tính độ sâu của cây bằng đệ quy
int calculateDepth(Node* root) {
    if (root == nullptr) {
        return 0;
    } else {
        int leftDepth = calculateDepth(root->left);
        int rightDepth = calculateDepth(root->right);
        return max(leftDepth, rightDepth) + 1;
    }
}

int main() {
    Node* root = nullptr;
    int n;

    cout << "Nhap so luong nut cua cay: ";
    cin >> n;

    // Nhập giá trị cho từng nút và thêm vào cây
    for (int i = 0; i < n; i++) {
        int value;
        cout << "Nhap gia tri cho nut thu " << (i + 1) << ": ";
        cin >> value;
        root = insert(root, value);
    }

    // Tính độ sâu của cây
    int depth = calculateDepth(root);

    // In ra kết quả độ sâu
    cout << "Do sau cua cay la: " << depth << endl;

    return 0;
}
