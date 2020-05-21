/Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.*

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
    void reorderList(ListNode* head) {
        
        stack<ListNode*>s;
        if( head == NULL )
            return;
        ListNode* ptr = head->next, *qtr;
        int len = 1, i = 0, val;
        while( ptr != NULL )
        {
            s.push(ptr);
            ptr = ptr -> next;
            len++;
        }
        ptr = head;
        while( i < (len/2) )
        {
            ptr = ptr->next;
            i++;
        }
        ptr -> next = NULL;
        val = len/2;
        if( len % 2 == 0 )
            val--;
        
        ptr = head;
        i = 0;
        while( i < val )
        {
            qtr = ptr->next;
            ptr -> next = s.top();
            s.pop();
            ptr = ptr->next;
            ptr->next = qtr;
            ptr = qtr;
            i++;
        } 
    }
};
