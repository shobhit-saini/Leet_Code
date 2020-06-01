/*
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/
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
        
        ListNode* temp1 = head, *temp2 = head;
        if( head == NULL )
            return head;
        while( temp2 != NULL && temp2->val == val )
        {
            temp2 = temp2->next;
        }
        head = temp2;
        if( head == NULL )
            return NULL;
        temp1 = temp2->next;
        while( temp1 != NULL )
        {
            if( temp1 -> val == val )
            {
                temp2->next = temp1->next;
                temp1 = temp2->next;
            }
            else
            {
                temp2 = temp2->next;
                temp1 = temp1->next; 
            }
        }
        return head;
    }
};
