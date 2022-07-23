#include <iostream>
#include "listnode.cpp"

using namespace std;

void traverse(ListNode* head){
    if (head == NULL) {
        cout << endl;
        return;
    }
    cout << head->val << " ";
    traverse(head->next);
}

int main(){
    int nums[] = {1,3,2,4,6,8,7,5};
    ListNode* head = new ListNode(nums, 8);
    traverse(head);

    return 0;
}
