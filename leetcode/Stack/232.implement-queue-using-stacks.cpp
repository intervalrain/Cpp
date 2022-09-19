#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue {
private:
    stack<int> sti;
    stack<int> sto;
public:
    MyQueue() {}
    
    void push(int x) {
        sti.push(x);
    }
    
    int pop() {
        int res = peek();
        sto.pop();
        return res;
    }
    
    int peek() {
        if (sto.empty()){
            while (!sti.empty()){
                sto.push(sti.top());
                sti.pop();
            }
        }
        int res = sto.top();
        return res;        
    }
    
    bool empty() {
        return sti.empty() && sto.empty();
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
// @lc code=end

