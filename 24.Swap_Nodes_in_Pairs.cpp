/*
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

 

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
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
    ListNode* Reverse( ListNode* p, ListNode* q, ListNode* r )
    {
            q -> next = p;
            if( r == NULL || r -> next == NULL )
            {
                p -> next = r;
                return q;
            }
            p -> next = Reverse( r, r->next, r->next->next );
            return q;
    }
    ListNode* swapPairs(ListNode* head) {
        
        ListNode* newhead, *p, *q, *r;
        if( head == NULL || head -> next == NULL )
            return head;
        p = head;
        q = p -> next;
        newhead = q;
        r = q -> next;
        Reverse( p, q, r );
        return newhead;
    }
};
