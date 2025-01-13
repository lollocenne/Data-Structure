#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    int size;
    
    LinkedList() : size(0), head(nullptr) {}
    
    // Add a new head
    // Time complexity: O(1)
    void addHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        size++;
    }
    
    // Insert a new node to a specific index
    // Time complexity: O(n)
    void insertAt(int index, int value) {
        if (index < 0 || index > size) {
            cout<<"Index out of range"<<endl;
            return;
        }
        if (index == 0) {
            addHead(value);
            return;
        }
        
        Node* newNode = new Node(value);
        Node* currentNode = head;
        for (int i = 0; i < index - 1; i++) {
            currentNode = currentNode->next;
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
        size++;
    }
    
    // Delete the head
    // Time complexity: O(1)
    void deleteHead() {
        if (head == nullptr) {return;}
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }
    
    // Delete a node to a specific index
    // Time complexity: O(n)
    void deleteAt(int index) {
        if (index < 0 || index >= size) {
            cout<<"Index out of range"<<endl;
            return;
        }
        if (index == 0) {
            deleteHead();
            return;
        }
        
        Node* currentNode = head;
        for (int i = 0; i < index - 1; i++) {
            currentNode = currentNode->next;
        }
        Node* nodeToDelete = currentNode->next;
        currentNode->next = nodeToDelete->next;
        delete nodeToDelete;
        size--;
    }
    
    // Revrse the list
    // Time complexity: O(n)
    void reverse() {
        Node* prev = nullptr;
        Node* next = nullptr;
        Node* currentNode = head;
        while (currentNode != nullptr) {
            next = currentNode->next;   // Temporary remember the next node
            currentNode->next = prev;   // Reverse the pointer
            prev = currentNode;         // Move prev forward
            currentNode = next;         // Move currentNode forward
        }
        head = prev;
    }
    
    // Return list length
    // Time complexity: O(1)
    int length() const {
        return size;
    }
    
    // Return the list as a vector
    // Time complexity: O(n)
    vector<int> toArray() const {
        vector<int> res;
        Node* currentNode = head;
        while (currentNode != nullptr) {
            res.push_back(currentNode->data);
            currentNode = currentNode->next;
        }
        return res;
    }
    
    // Show the list
    // Time complexity: O(n)
    void printList() const {
        Node* currentNode = head;
        while (currentNode != nullptr) {
            cout<<currentNode->data;
            if (currentNode->next != nullptr) {
                cout<<" -> ";
            }
            currentNode = currentNode->next;
        }
        cout<<endl;
    }
    
    ~LinkedList() {
        Node* currentNode = head;
        while (currentNode != nullptr) {
            Node* next = currentNode->next;
            delete currentNode;
            currentNode = next;
        }
    }
};


int main() {
    LinkedList list;
    list.addHead(10);
    list.addHead(20);
    list.addHead(30);
    list.insertAt(1, 15);
    list.deleteAt(2);
    list.printList();
    list.reverse();
    list.printList();
    cout<<"Length: "<<list.length()<<endl;
    
    return 0;
}