/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ptr = l1, *qtr = l2, *start, *temp, *temp1;
        int flag = 0;
        if(ptr == NULL && qtr == NULL)
            return ptr;
        else if(ptr != NULL && qtr == NULL)
            return ptr;
        else if(qtr != NULL && ptr == NULL)
            return qtr;
        while(ptr != NULL && qtr != NULL)
        {
            if(ptr->val <= qtr->val)
            {
                temp = ptr;
                ptr = ptr-> next;
            }
            else
            {
                temp = qtr;
                qtr = qtr->next;
            }
            if(flag == 0)
            {
                start = temp;
                flag = 1; 
                temp1 = temp;
            }
            else
            {
                temp1->next = temp;
                temp1 = temp;
            }
        }
        if(ptr != NULL)
        {
            temp1->next = ptr;
        }
        if(qtr != NULL)
        {
            temp1->next = qtr;
        }
        return start;
    }
};
