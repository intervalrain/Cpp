#include <iostream>
#include <vector>

using namespace std;

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
        ListNode* nextNode = new ListNode(nums[n-1]);
        for (int i = n-2; i >= 0; i--){
            ListNode* curr = new ListNode(nums[i], nextNode);
            nextNode = curr;
        }
        this->val = nextNode->val;
        this->next = nextNode->next;
    }
    void print(){
        ListNode* curr = this;
        for (; curr->next != NULL; curr = curr->next){
            cout << curr->val << "->";
        }
        cout << curr->val << endl;
    }
};
