#include <iostream>
#include "listnode.cpp"


using namespace std;

int main(){

    int nums[] = {1,2,3,4,5,6,7,8,9,0};

    ListNode* head = new ListNode(nums, 10);
    for (ListNode* curr = head; curr != NULL; curr = curr->next){
        cout << curr->val << " ";
    }
    cout << endl;

    return 0;
}
