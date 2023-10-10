#include <iostream>
#include <string>

using namespace std;

// Lớp Node để đại diện cho mỗi nút trong cây quyết định
class Node {
public:
    string question; // Câu hỏi hoặc lời khuyên liên quan đến nút
    bool isLeaf;     // Biến kiểm tra xem nút có phải là lá hay không
    Node* yesNode;   // Con trỏ đến nút con cho trả lời "yes"
    Node* noNode;    // Con trỏ đến nút con cho trả lời "no"

    // Hàm khởi tạo Node với một câu hỏi hoặc lời khuyên và kiểm tra xem nó có phải là lá không
    Node(string q, bool leaf = false) {
        question = q;
        isLeaf = leaf;
        yesNode = nullptr;
        noNode = nullptr;
    }
};

// Hàm để tương tác với cây quyết định và trả lời các câu hỏi
void traverseTree(Node* root) {
    while (root != nullptr && !root->isLeaf) {
        cout << root->question << "\n";
        string answer;
        cin >> answer;

        if (answer == "yes") {
            root = root->yesNode; // Di chuyển đến nút con "yes" nếu trả lời "yes"
        } else if (answer == "no") {
            root = root->noNode;  // Di chuyển đến nút con "no" nếu trả lời "no"
        } else {
            cout << "Please answer with 'yes' or 'no'." << endl; // Thông báo lỗi nếu trả lời không hợp lệ
        }
    }

    cout << "DECISION: " << root->question << endl; // In ra kết quả cuối cùng
}

int main() {
    // Tạo cây quyết định với câu hỏi và quyết định
    Node* root = new Node("Is the picture clear?");
    root->yesNode = new Node("Is there sound?");
    root->noNode = new Node("Is the screen blank?");
    root->yesNode->yesNode = new Node("Error: Please try troubleshooting again.", true);
    root->yesNode->noNode = new Node("Check mute button.", true);
    root->noNode->yesNode = new Node("Is there sound?");
    root->noNode->noNode = new Node("Check power cord.", true);
    root->noNode->yesNode->yesNode = new Node("Error: Please try troubleshooting again.", true);
    root->noNode->yesNode->noNode = new Node("Check audio cable.", true);

    cout << "QUESTION: " << root->question << endl;

    // Gọi hàm để tương tác với cây quyết định
    traverseTree(root);

    return 0;
}
