class MinStack {
public:
    stack<int> values;
    stack<int> mins;
MinStack() {    
    }
    void push(int val) {
        values.push(val);
        if (mins.empty() || val <= mins.top()) {
            mins.push(val);
        }
    }
    void pop() {
        if (values.top() == mins.top()) {
            mins.pop();
        }
        values.pop();
    }
    int top() {
        return values.top();
    }
    
    int getMin() {
        return mins.top();
    }
};