class MyStack {
private:
    queue<int> mq, aq;
public:
    /** Initialize your data structure here. */
    MyStack() {
        mq = queue<int>();
        aq = queue<int> ();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        while(!mq.empty()){
            aq.push(mq.front());
            mq.pop();
        }   
        mq.push(x);
        while(!aq.empty()){
            mq.push(aq.front());
            aq.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = mq.front();
        mq.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return mq.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return mq.empty();   
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */