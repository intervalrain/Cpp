#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2, 0);
    }
    ListNode* add(ListNode* l1, ListNode* l2, int cin){
        ListNode* node = new ListNode(l1->val + l2->val + cin);
        cin = node->val / 10;
        node->val %= 10;
        if (l1->next || l2->next || cin != 0){
            node->next = add((l1->next == NULL ? new ListNode(0) : l1->next),
                             (l2->next == NULL ? new ListNode(0) : l2->next),
                             cin);
        }
        return node;
    }
    // iteration
    // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //     ListNode* dummy = new ListNode(-1);
    //     ListNode* curr = dummy;
    //     int cin = 0;
    //     while (l1 || l2 || cin > 0) {
    //         int tmp = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + cin;
    //         cin = tmp / 10;
    //         curr->next = new ListNode(tmp % 10);
            
    //         if (l1) l1 = l1->next;
    //         if (l2) l2 = l2->next;
    //         curr = curr->next;
    //     }
    //     return dummy->next;
    // }
};
// @lc code=end

