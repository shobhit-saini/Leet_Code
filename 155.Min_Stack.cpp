/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

Methods pop, top and getMin operations will always be called on non-empty stacks.
*/
class MinStack {
public:
    stack<int> s1, min_stack;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        
        s1.push(x);
        if( min_stack.empty() )
        {
            min_stack.push(x);
        }
        else if( min_stack.top() >= x )
        {
            min_stack.push(x);
        }
    }
    
    void pop() {
        
        int a;
        a = s1.top();
        if( min_stack.top() == a )
        {
            min_stack.pop();
        }
        s1.pop();
    }
    
    int top() {
        
        return s1.top();
    }
    
    int getMin() {
        
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
