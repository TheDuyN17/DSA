#include<iostream>

using namespace std;

struct node {
    string s;
    node* left;
    node* right;
    node(string _s);
    void addLeft(node* n);
    void addRight(node* n);
};

node::node(string _s) {
    s = _s;
    left = nullptr;
    right = nullptr;
}

void node::addLeft(node* n) {
    left = n;
}

void node::addRight(node* n) {
    right = n;
}


void printArithmetic(node* head) {
	if (head->left != nullptr) {
		cout << "( ";
		printArithmetic(head->left);
	}
	cout << head->s << " ";
	if (head->right != nullptr) {
		printArithmetic(head->right);
		cout << ") ";
	}
}

int main() {
    node* head = new node("*");  // Multiplication operator
    node* leftAddition = new node("+");  // Addition operator
    node* rightSubtraction = new node("-");  // Subtraction operator
    
    // Left side of the addition
    node* leftOperand1 = new node("2");
    node* leftOperand2 = new node("3");
    leftAddition->addLeft(leftOperand1);
    leftAddition->addRight(leftOperand2);
    
    // Right side of the subtraction
    node* rightOperand1 = new node("4");
    node* rightOperand2 = new node("1");
    rightSubtraction->addLeft(rightOperand1);
    rightSubtraction->addRight(rightOperand2);
    
    // Connect the main tree
    head->addLeft(leftAddition);
    head->addRight(rightSubtraction);

    // Print the arithmetic expression
    printArithmetic(head);


}
