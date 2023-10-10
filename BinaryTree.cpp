#include <iostream>

using namespace std;

// Định nghĩa lớp Node để biểu diễn các nút trong cây
class Node {
public:
    int data; // Dữ liệu chứa trong nút
    Node* left; // Con trỏ đến nút con bên trái
    Node* right; // Con trỏ đến nút con bên phải

    // Hàm khởi tạo cho Node
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Hàm để thêm một nút mới vào cây
Node* insert(Node* root, int value) {
    // Nếu cây không có nút nào, tạo một nút mới làm gốc
    if (root == nullptr) {
        return new Node(value);
    } else {
        // Nếu giá trị nhỏ hơn dữ liệu gốc, thêm vào cây con bên trái
        if (value < root->data) {
            root->left = insert(root->left, value);
        } else {
            // Ngược lại, thêm vào cây con bên phải
            root->right = insert(root->right, value);
        }
        return root;
    }
}

int main() {
    Node* root = nullptr; // Khởi tạo gốc của cây
    int n; // Số lượng nút trong cây

    cout << "Nhap so luong nut cua cay: ";
    cin >> n;

    // Nhập giá trị cho từng nút và thêm vào cây
    for (int i = 0; i < n; i++) {
        int value;
        cout << "Nhap gia tri cho nut thu " << (i + 1) << ": ";
        cin >> value;
        root = insert(root, value); // Thêm nút vào cây
    }

    // Bây giờ cây đã được tạo thành công

    return 0;
}
