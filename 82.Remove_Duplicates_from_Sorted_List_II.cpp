/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Return the linked list sorted as well.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if( head == NULL || head -> next == NULL )
            return head;
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        int flag = 0;
        ListNode* p = dummy, *q = head;
        
        while(  q != NULL && q -> next != NULL )
        {
            flag = 0;
            while( q -> next != NULL && q -> val == q -> next -> val )
            {
                flag = 1;
                q = q->next;
            }
            if( flag == 1 )
            {
                p -> next = q -> next;
                q = q -> next;
            }
            else
            {
                q = q -> next;
                p = p -> next;
            }
        }
        return dummy -> next;
    }
};
