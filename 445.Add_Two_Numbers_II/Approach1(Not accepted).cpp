/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* temp1 = l1, *temp2 = l2;
        int i = 10;
        unsigned long long num1 = 0, num2 = 0;
        while( temp1 != NULL )
        {
            num1 = num1*i + temp1->val;
            temp1 = temp1->next;
        }
        
        while( temp2 != NULL )
        {
            num2 = num2*i + temp2-> val;
            temp2 = temp2->next;
        }
        unsigned long long sum = num1+num2;
        ListNode* nxt = NULL;
        ListNode* node;
        if( sum == 0 )
        {
            node = new ListNode(sum%10);
        }
        while( sum > 0 )
        {
            node = new ListNode(sum%10);
            sum /= 10;
            node->next = nxt;
            nxt = node;
        }
        return node;
    }
};
