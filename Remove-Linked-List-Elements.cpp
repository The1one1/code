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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *preNode = nullptr, tempNOde = head;

        while(head->val == val){
            preNode = head;
            tempNode = head = head->next;
            delete(preNode);
        }

        while(tempNode -> next != nullptr){
            if(tempNode -> val == val){
                preNode = tempNode;
                tempNode = tempNode -> next;
                delete(preNode);
            }
        }
        return head;
    }
};