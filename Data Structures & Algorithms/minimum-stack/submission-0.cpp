#include <stack>

class MinStack {
public:

    std::stack<int> store;
    std::stack<int> min;


    MinStack() {
        
    }
    
    // Not an array or 
    void push(int val) {
        store.push(val);
        if (min.empty() || min.top() >= val) {
            min.push(val);
        } else {
            min.push(min.top());
        }
    }
    
    void pop() {
        store.pop();
        min.pop();
    }
    
    int top() {
        return store.top();
    }
    
    int getMin() {
        return min.top();
    }
};
