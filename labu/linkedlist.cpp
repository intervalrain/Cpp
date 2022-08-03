#include <iostream>

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int num, ListNode* next){
        this->val = num;
        this->next = next;
    }
    ListNode(int num){
        this->val = num;
    }
    ListNode(int* nums, int n){
        ListNode* nextNode = new ListNode(nums[n-1]);
        for (int i = n-2; i >= 0; i--){
            ListNode* curr = new ListNode(nums[i], nextNode);
            nextNode = curr;
        }
        this->val = nextNode->val;
        this->next = nextNode->next;
    }
    ListNode(vector<int> nums){
        int n = nums.size();
        ListNode* next Node = new ListNode(nums[n-1]);
        for (int i = n-2; i >= 0; i--){
            ListNode* curr = new ListNode(nums[i], nextNode);
            nextNode = curr;
        }
        this->val = nextNode->val;
        this->next = nextNode->next;
    }
};

/**
 * @brief The classic problems of linked list
 * 1. Linked list cycle (return boolean)
 * 2. Linked list cycle II (return intersection)
 * 3. Intersection of two linked list
 * 4. Remove Nth node from end of the list
 * 5. Merge two sorted list
 * 6. Merge k sorted list
 * 7. Partition list
 * 8. Middle of the linked list
 */

// 1. linked list cycle
bool hasCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow){
            return true;
        }
    }
    return false;
}

// 2. linked list cycle II
ListNode *detectCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) break;
    }
    if (fast == NULL || fast->next == NULL){
        return NULL;
    }
    slow = head;
    while (slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

// 3. Intersection of two linked list
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* p1 = headA;
    ListNode* p2 = headB;
    while (p1 != p2){
        p1 = p1 == NULL ? headB : p1->next;
        p2 = p2 == NULL ? headA : p2->next;
    }
    return p1;
}

// 4. Remove Nth node from end of the list
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;

    // find (n+1)th node from end
    ListNode* fast = dummy->next;
    ListNode* slow = dummy;
    while (n--) fast = fast->next;
    while (fast){
        fast = fast->next;
        slow = slow->next;
    }


    slow->next = slow->next->next;
    return dummy->next;
}