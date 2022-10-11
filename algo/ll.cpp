#include <iostream>
#include <vector>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(){}
    ListNode(int _val):val(_val){}
    ListNode(int _val, ListNode* _next):val(_val), next(_next){}
};

ListNode* build(vector<int>& nums){
    ListNode* head = new ListNode(nums[0]);
    ListNode** curr = &head;
    for (int i = 1; i < nums.size(); i++){
        (*curr)->next = new ListNode(nums[i]);
        curr = &(*curr)->next;
    }


//    ListNode* dummy = new ListNode(-1);
//    ListNode* prev = dummy;
//    ListNode* curr;

//    for (int i = 0; i < nums.size(); i++){
//        curr = new ListNode(nums[i]);
//        prev->next = curr;
//        prev = curr;
//        curr = curr->next;
//    }
//    ListNode* head = dummy->next;
//    delete(dummy);

    return head;
}

void traverse(ListNode* head){
    for (ListNode* curr = head; curr != NULL; curr = curr->next){
        cout << curr->val << " ";
    }
}

int at(ListNode* head, int n){
    ListNode* curr = head;
    while(n--){
        curr = curr->next;
    }
    return curr->val;
}

void update(ListNode* head, int n, int val){
    ListNode* curr = head;
    while (n--){
        curr = curr->next;
    }
    curr->val = val;
}

ListNode* insert(ListNode* head, int n, int val){
    ListNode* dummy = new ListNode(-1, head);
    ListNode* curr = dummy;
    while (curr && n--){
        curr = curr->next;
    }
    ListNode* tmp = curr->next;
    curr->next = new ListNode(val);
    curr->next->next = tmp;
    head = dummy->next;
    return head;
}

ListNode* iinsert(ListNode* head, int n, int val){
    if (!head) return NULL;
    if (n == 0){
        ListNode* newHead = new ListNode(val, head);
        head = newHead;
        return head;
    }
    ListNode* curr = head;
    while (--n){
        curr = curr->next;
    }
    ListNode* tmp = curr->next;
    curr->next = new ListNode(val);
    curr->next->next = tmp;
    return head;
}

void remove(ListNode* head, int target){
    ListNode* prev = NULL;
    ListNode* curr = head;
    while (curr && curr->val != target){
        prev = curr;
        curr = curr->next;
    }
    if (!prev)
        head = head->next;
    else
        prev->next = prev->next->next;
}
void rremove(ListNode* head, int target){
    ListNode** curr = &head;
    while ((*curr) && (*curr)->val != target){
        curr = &(*curr)->next;
    }
    if (!(*curr)) return;
    *curr = (*curr)->next;
}

void removeAll(ListNode* head, int target){
    ListNode* dummy = new ListNode(-1, head);
    ListNode* curr = dummy;
    while (curr && curr->next){
        if (curr->next->val == target){
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }
}

int removeAll2(ListNode* head, int target){
    int tmp;
    if(head->next) {
        tmp = removeAll2(head->next, target);
    }
    if (tmp == target){
        head->next = head->next->next;
    }
    return head->val;
}

void removeAll3(ListNode* head, int target){
    if (!head) return;
    while (head && head->val == target){
        if (head->next){
            head->val = head->next->val;
            head->next = head->next->next;
        } else {
            head = NULL;
        }
    }
    removeAll3(head->next, target);
}

ListNode* reverse(ListNode* head){
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = NULL;
    while (curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

ListNode* successor;
ListNode* reverseN(ListNode* head, int n){
    if (n == 1){
        successor = head->next;
        return head;
    }
    ListNode* last = reverseN(head->next, n-1);
    head->next->next = head;
    head->next = successor;
    return last;
}

ListNode* reverseKGroup(ListNode* head, int k){
    ListNode* successor = head;
    int cnt = 0;
    while (successor && cnt < k){
        successor = successor->next;
        cnt++;
    }
    if (cnt == k){
        successor = reverseKGroup(successor, k);
        head = reverseN(head, k);
        head->next = successor;
    }
    return head;
}

int main(){
    vector<int> nums = {1,2,3,4,5,6,7,8};
    ListNode* head = build(nums);
    reverseN(head, 3);
    // reverseKGroup(head, 3);
    traverse(head);

    return 0;
}
