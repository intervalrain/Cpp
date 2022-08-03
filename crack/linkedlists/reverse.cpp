#include <iostream>
#include <vector>
#include "listnode.cpp"

/**
 * reverse a linked list
 */

ListNode* reverseIterative(ListNode* head){
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr;
    while (curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}


ListNode* reverseRecursive(ListNode* head){
    if (!head || !head->next) return head;
    ListNode* last = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return last;
}

int main(){
    int n;
    cout << "n = ";
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    ListNode* node = new ListNode(nums);
    node->print();

    ListNode* res = reverseIterative(node);
    res->print();

    ListNode* res2 = reverseRecursive(res);
    res2->print();

    return 0;
}
