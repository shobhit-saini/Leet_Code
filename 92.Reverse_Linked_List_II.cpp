/*
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        ListNode* p = head, *q = head, *r = head, *s = head, *head1, *prev, *newhead;
        int i = 1, flag = 0, flag1 = 0;
        while( i < m-1 )
        {
            s = s->next;
            i++;
        }
        if( m == 1 )
        {
            prev = NULL;
            r = s;
            flag = 1;
        }
        else
        {
            prev = s;
            r = s->next;
            i++;
        }
        p = NULL;
        q = NULL;
        head1 = r;
        while( i <= n )
        {
            q = r;
            r = r->next;
            q->next = p;
            p = q;
            i++;
        }
        if( flag == 1 )
        {
            newhead = p;
        }
        else
        {
            prev->next = p;
            newhead = head;
        }
        head1->next = r;
        return newhead;
    }
};
