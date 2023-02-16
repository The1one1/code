#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int a = 5, z =8;
    int *p = &a;
    int *q = p;
    cout << *p <<" "<< *q<<endl;
    p = &z;
    cout << *p <<" "<< *q<<endl;
}
















// class Solution
// {
// public:
//     ListNode *deleteDuplicates(ListNode *head)
//     {
//         if (head == nullptr)
//             return head;

//         ListNode *pre = head, *curr = head, *next = head;

//         while (curr != nullptr)
//         {
//             next = curr->next;
//             if (curr -> next != nullptr and curr -> val == next -> val)
//             {
//                 while(curr->next != nullptr and curr->val == next->val){
//                     curr = curr->next;
//                     next = curr;
//                 }
//                 pre = next;
//             }
//             else
//                 pre = pre->next;
            
//             curr = curr->next;
//         }
//         return head;
//     }
// };


// class Solution
// {
// public:
//     ListNode *deleteDuplicates(ListNode *head)
//     {

//         ListNode *dummy = new ListNode(0, head);
//         ListNode *prev = dummy;

//         while (head != NULL)
//         {
//             if (head->next != NULL && head->val == head->next->val)
//             {
//                 while (head->next != NULL && head->val == head->next->val)
//                     head = head->next;

//                 prev->next = head->next;
//             }
//             else
//                 prev = prev->next;

//             head = head->next;
//         }
//         return dummy->next;
//     }
// };