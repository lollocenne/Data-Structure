#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
public:
    Node* head;
    int size;
    
    LinkedList() : size(0), head(nullptr) {}
    
    // Add a new head
    void addHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        size++;
    }
    
    // Insert a new node to a specific index
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
    
    // Return list length
    int length() const {
        return size;
    }
    
    // Show the list
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
    list.printList();
    cout<<"Length: "<<list.length()<<endl;
    
    return 0;
}