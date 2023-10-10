#include <iostream>
#include <cstdlib> // For abs()
using namespace std;

// Định nghĩa lớp Node để biểu diễn các nút trong cây
class node {
public:
    int item;       // Dữ liệu chứa trong nút
    node* left;     // Con trỏ đến nút con bên trái
    node* right;    // Con trỏ đến nút con bên phải
};

// Hàm tạo một nút mới với giá trị cho trước
node* newNode(int item) {
    node* Node = new node();
    Node->item = item;
    Node->left = NULL;
    Node->right = NULL;
    return (Node);
}

// Hàm kiểm tra cân bằng chiều cao của cây
bool checkHeightBalance(node* root, int* height) {
    // Khai báo biến để lưu chiều cao của cây con bên trái và bên phải
    int leftHeight = 0, rightHeight = 0;

    // Khai báo biến để lưu kết quả từ các cây con bên trái và bên phải
    int l = 0, r = 0;

    // Kiểm tra trường hợp cây rỗng
    if (root == NULL) {
        *height = 0;
        return true;
    }

    // Đệ quy kiểm tra cân bằng cho cây con bên trái và bên phải
    l = checkHeightBalance(root->left, &leftHeight);
    r = checkHeightBalance(root->right, &rightHeight);

    // Tính chiều cao của cây tại nút hiện tại
    *height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

    // Kiểm tra cân bằng chiều cao và trả về kết quả
    if (abs(leftHeight - rightHeight) >= 2)
        return false;
    else
        return l && r;
}

int main() {
    int height = 0;

    // Tạo cây nhị phân mẫu
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    // Kiểm tra cân bằng chiều cao của cây
    if (checkHeightBalance(root, &height))
        cout << "The tree is balanced" << endl;
    else
        cout << "The tree is not balanced" << endl;

    return 0;
}
