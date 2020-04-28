/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* slow = head , * fast = head ;
        int len = 1 ,t_len , pos ;
        while( fast != NULL && fast -> next != NULL )
        {
            len++;
            slow = slow -> next ; 
            fast = fast -> next -> next ;
        }
        if( fast == NULL )
            t_len = 2*len - 2 ;
        else
            t_len = 2*len - 1 ;
        pos = t_len - n  + 1 ;
        if(pos == 1)
            return head -> next ;
        if( pos < len || pos == len )
            slow = head ;
        else if( pos > len )
        {
            pos = pos - len ;
            pos++ ;
        }

        while(  --pos > 1  )
        {
            slow = slow -> next ;
        }
        slow -> next = slow -> next -> next ;
        return head ;
    }
};
