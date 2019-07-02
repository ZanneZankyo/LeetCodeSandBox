/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (35.91%)
 * Total Accepted:    275.7K
 * Total Submissions: 767.3K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 * 
 * 
 * push(x) -- Push element x onto stack.
 * 
 * 
 * pop() -- Removes the element on top of the stack.
 * 
 * 
 * top() -- Get the top element.
 * 
 * 
 * getMin() -- Retrieve the minimum element in the stack.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 * 
 * 
 */
class MinStack {
public:
    /** initialize your data structure here. */

    int m_min = 0x7FFFFFFF;
    vector<int> m_vec;

    MinStack() {
        
    }
    
    void push(int x) {
        m_vec.push_back(x);
        if(x < m_min)
            m_min = x;
    }
    
    void pop() {
        bool needUpdate = m_vec[m_vec.size()-1] == m_min;
        m_vec.pop_back();
        if(needUpdate)
            updateMin();
    }
    
    int top() {
        return m_vec[m_vec.size() - 1];
    }
    
    int getMin() {
        return m_min;
    }
private:
    void updateMin() {
        m_min = 0x7FFFFFFF;
        for(int n : m_vec) {
            m_min = n < m_min ? n : m_min;
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

