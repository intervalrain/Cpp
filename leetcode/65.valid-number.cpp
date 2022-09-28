#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] valid number
 */

// @lc code=start
/**
 * @brief: DFA - Deterministic Finite Automaton
 * states
 * 0: initial
 * 1: only dot   [.]
 * 2: number     [0-9]
 * 3: sign       [+|-]
 * 4: dot number [.][0-9]
 * 5: e          [E|e]
 * 6: e sign     [E|e][+|-]
 * 7: e number   [E|e][0-9]
 * 8: end
 * 9: fail
 * 
 * inputs
 * 0: others     [*]
 * 1: space      [ ]
 * 2: dot        [.]
 * 3: nubmers    [0-9]
 * 4: sign       [+|-]
 * 5: e          [E|e]
 */
class State {
private:
    int state;
    vector<vector<int>> transitions;
    int getInput(char c){
        if (c == ' ') return 1;
        if (c == '.') return 2;
        if (c >= '0' && c <= '9') return 3;
        if (c == '+' || c == '-') return 4;
        if (c == 'e' || c == 'E') return 5;
        return 0;
    }
public:
    State(){
        this->state = 0;
        transitions = {
            {9,0,1,2,3,9},
            {9,9,9,4,9,9},
            {9,8,4,2,9,5},
            {9,9,1,2,9,9},
            {9,8,9,4,9,5},
            {9,9,9,7,6,9},
            {9,9,9,7,9,9},
            {9,8,9,7,9,9},
            {9,8,9,9,9,9},
            {9,9,9,9,9,9}
        };
    }
    bool result(){
        return state == 2 || state == 4 || state == 7 || state == 8;
    }
    void set(char c){
        this->state = transitions[this->state][getInput(c)];
    }
};
class Solution {
public:
    bool isNumber(string s) {
        int n = s.length();
        State st;
        for (int i = 0; i < n; i++){
            st.set(s[i]);
        }
        return st.result();
    }
};
// @lc code=end

