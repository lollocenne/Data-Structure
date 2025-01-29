#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    Node* root;
    
    BinarySearchTree(int value) {
        root = new Node(value);
    }
    
    // Inserts a value
    // Time Complexity: O(log n) on average, O(n) in the worst case
    void insert(int value) {
        Node* current = root;
        Node* parent = nullptr;
        while (current) {
            parent = current;
            if (value < current->data) current = current->left;
            else current = current->right;
        }
        if (value < parent->data) parent->left = new Node(value);
        else parent->right = new Node(value);
    }
    
    // Searches a value
    // Time Complexity: O(log n) on average, O(n) in the worst case
    bool search(int value) {
        Node* current = root;
        while (current) {
            if (current->data == value) return true;
            current = (value < current->data) ? current->left : current->right;
        }
        return false;
    }
    
    // Performs a preorder traversal
    // Time Complexity: O(n)
    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
};

int main() {
    BinarySearchTree bst(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(18);
    
    cout << "BST preorder traversal: ";
    bst.preorder(bst.root);
    cout << endl;
    
    cout << "Search 7: " << (bst.search(7) ? "Found" : "Not Found") << endl;
    cout << "Search 20: " << (bst.search(20) ? "Found" : "Not Found") << endl;
    
    return 0;
}