#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        bool flagA = true;
        bool flagB = true;
        while (a && b){
            if (a == b) return a;
            a = a->next;
            b = b->next;
            if (!a && flagA){
                a = headB;
                flagA = false;
            } 
            if (!b && flagB){
                b = headA;
                flagB = false;
            } 
        }
        return NULL;
    }
};
// @lc code=end

