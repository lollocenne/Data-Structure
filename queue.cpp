#include <iostream>
#include <list>
using namespace std;

class Queue {
private:
    list<int> data;
    size_t size = 0;
    
public:
    // Adds a value to the queue
    // Time complexity: O(1)
    void enqueue(int value) {
        data.push_back(value);
        size++;
    }
    
    // Removes and returns the front element of the queue
    // Time complexity: O(1)
    int dequeue() {
        if (data.empty()) {
            throw runtime_error("The queue is empty");
        }
        int front = data.front();
        data.pop_front();
        size--;
        return front;
    }
    
    // Returns the length of the queue
    // Time complexity: O(1)
    size_t length() const {
        return size;
    }
    
    // Checks if the queue is empty
    // Time complexity: O(1)
    bool isEmpty() const {
        return size == 0;
    }
};

int main() {
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    cout<<"Length: "<<queue.length()<<endl;
    cout<<"Removed element: "<<queue.dequeue()<<endl;
    
    return 0;
}
