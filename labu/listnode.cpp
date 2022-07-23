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
};
