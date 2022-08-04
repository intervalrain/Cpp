#include <iostream>
#include <stack>

/**
 * How would you design a stack which, in addition to push and pop,
 * has a function, which returns the minimum element?
 * Push, pop and min should all operate in O(1) time.
 *
 * example:
 *   push(5);  {5}       // {5}
 *   push(6);  {6,5}     // {5,5}
 *   push(3);  {3,6,5}   // {3,5,5}
 *   push(7);  {7,3,6,5} // {3,3,5,5}
 *   pop();    {3,6,5}  return 3
 *   pop();    {6,5}    return 5
 *
 */

using namespace std;

class minStack{
private:
    stack<int> stmin;
    stack<int> st;
public:
    void push(int val){
        st.push(val);
        if (stmin.empty()){
            stmin.push(val);
        } else {
            stmin.push(::min(stmin.top(), val));
        }
    }
    int pop(){
        int res = st.top();
        st.pop();
        stmin.pop();
        return res;
    }
    int min(){
        return stmin.top();
    }

};


int main(){
    minStack* st = new minStack();
    st->push(5);
    st->push(6);
    st->push(3);
    st->push(7);
    cout << st->pop() << endl;
    cout << st->min() << endl;
    cout << st->pop() << endl;
    cout << st->min() << endl;

    return 0;
}
