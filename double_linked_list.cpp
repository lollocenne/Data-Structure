#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoubleLinkedList {
public:
    Node* head;
    Node* tail;
    int size;
    
    DoubleLinkedList() : size(0), head(nullptr), tail(nullptr) {}
    
    // Add a new head
    void addHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        if (size == 0) {
            tail = newNode;
        }
        size++;
    }
    
    void addTail(int value) {
        Node* newNode = new Node(value);
        tail->next = newNode;
        if (size == 0) {
            head = newNode;
        }
        size++;
    }
    
    void insertAt(int index, int value) {
        if (index < 0 || index > size) {
            cout << "Index out of range" << endl;
            return;
        }
        
        if (index == 0) {
            addHead(value);
            return;
        }
        
        if (index == size) {
            addTail(value);
            return;
        }
        
        Node* newNode = new Node(value);
        Node* currentNode;
        // Decide whether to start from the head or the tail
        if (index <= size / 2) {
            currentNode = head;
            for (int i = 0; i < index - 1; i++) {
                currentNode = currentNode->next;
            }
        } else {
            currentNode = tail;
            for (int i = size - 1; i > index; i--) {
                currentNode = currentNode->prev;
            }
        }
        
        newNode->next = currentNode->next;
        newNode->prev = currentNode;
        if (currentNode->next != nullptr) {
            currentNode->next->prev = newNode;
        }
        currentNode->next = newNode;
        size++;
    }
    
    // Delete the head
    // Time complexity: O(1)
    void deleteHead() {
        if (head == nullptr) {return;}
        Node* temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        } else {
            head->prev = nullptr;
        }
        delete temp;
        size--;
    }
    
    // Delete the tail
    // Time complexity: O(1)
    void deleteTail() {
        if (tail == nullptr) {return;}
        Node* temp = tail;
        tail = tail->prev;
        if (tail == nullptr) {
            head = nullptr;
        } else {
            tail->next = nullptr;
        }
        delete temp;
        size--;
    }
    
    // Delete a node to a specific index
    // Time complexity: O(n)
    void deleteAt(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        if (index == 0) {
            deleteHead();
            return;
        }
        if (index == size - 1) {
            deleteTail();
            return;
        }
        
        Node* currentNode;
        // Decide whether to start from the head or the tail
        if (index <= size / 2) {
            currentNode = head;
            for (int i = 0; i < index; i++) {
                currentNode = currentNode->next;
            }
        } else {
            currentNode = tail;
            for (int i = size - 1; i > index; i--) {
                currentNode = currentNode->prev;
            }
        }
        currentNode->prev->next = currentNode->next;
        currentNode->next->prev = currentNode->prev;
        delete currentNode;
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
    
    ~DoubleLinkedList() {
        Node* currentNode = head;
        while (currentNode != nullptr) {
            Node* next = currentNode->next;
            delete currentNode;
            currentNode = next;
        }
    }
};


int main() {
    DoubleLinkedList list;
    list.addHead(10);
    list.addHead(20);
    list.insertAt(1, 15);
    list.addTail(5);
    list.printList();
    list.reverse();
    list.printList();
    cout<<"Length: "<<list.length()<<endl;
    
    return 0;
}