/*
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
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
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode* temp = new ListNode(0), *p = temp;
        while( l1 != NULL && l2 != NULL )
        {
            if( l1->val < l2->val )
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if( l1 != NULL )
            p->next = l1;
        if( l2 != NULL )
            p->next = l2;
        return temp->next;
    }
    ListNode* sortList(ListNode* head) {
        ListNode* slow = head, *fast = head, *prev = head;
        if( head == NULL || head->next == NULL )
            return head;
        while( fast != NULL && fast->next != NULL )
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        return merge(l1, l2);
    }
};
