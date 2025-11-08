#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> s1, s2;  // Two stacks

    MyQueue() {
        // Constructor initializes empty stacks
    }
    
    void push(int x) {
        // Push element onto stack s1
        s1.push(x);
    }
    
    int pop() {
        // If s2 is empty, move all elements from s1 to s2
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int frontElement = s2.top();
        s2.pop();
        return frontElement;
    }
    
    int peek() {
        // If s2 is empty, move all elements from s1 to s2
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
