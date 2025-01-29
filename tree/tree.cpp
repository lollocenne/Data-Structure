#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    vector<Node*> children;
    
    Node(int value) : data(value) {}
};

class Tree {
private:
    Node* root;
    
public:
    Tree(int value) {
        root = new Node(value);
    }
    
    Node* getRoot() {
        return root;
    }
    
    // Inserts a node under a specified parent node
    // Time complexity: O(1) if parent is known
    void insert(Node* parent, int value) {
        if (parent) {
            parent->children.push_back(new Node(value));
        }
    }
    
    // Searches for a node in the tree 
    // Time complexity: O(n)
    Node* search(Node* node, int value) {
        if (!node) return nullptr;
        if (node->data == value) return node;
        for (Node* child : node->children) {
            Node* found = search(child, value);
            if (found) return found;
        }
        return nullptr;
    }
    
    // Prints the tree in a preorder traversal
    // Time complexity:  O(n)
    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        for (Node* child : node->children) {
            preorder(child);
        }
    }
    
    void printTree() {
        preorder(root);
        cout << endl;
    }
};

int main() {
    Tree tree(1);
    Node* root = tree.getRoot();
    
    tree.insert(root, 2);
    tree.insert(root, 3);
    tree.insert(root, 4);
    
    Node* node2 = tree.search(root, 2);
    tree.insert(node2, 5);
    tree.insert(node2, 6);
    
    Node* node3 = tree.search(root, 3);
    tree.insert(node3, 7);
    
    cout << "Tree preorder traversal: ";
    tree.printTree();
    
    return 0;
}