#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Stack {
private:
    vector<int> data;
    size_t size = 0;
    
public:
    // Add a value to the top
    // Time complexity: O(1)
    void push(int value) {
        data.push_back(value);
        size++;
    }
    
    // Remove the top value and returns it
    // Time complexity: O(1)
    int pop() {
        if (isEmpty()) {
            throw underflow_error("The stack is empty");
        }
        int topValue = data.back();
        data.pop_back();
        size--;
        return topValue;
    }
    
    // Return `true` if the stack is empty
    // Time complexity: O(1)
    bool isEmpty() const {
        return size == 0;
    }
    
    // Return stack length
    // Time complexity: O(1)
    size_t length() const {
        return size;
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << stack.pop() << endl;
    stack.push(40);
    cout << stack.pop() << endl;
    cout << "Length: " << stack.length() << endl;
    
    return 0;
}
