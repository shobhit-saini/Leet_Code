/*
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
       
        ListNode* slow = head , *fast = head ;
        stack<int> s ;
        int c = 0;
        if( head == NULL || head -> next == NULL )
            return true ;
        while( fast != NULL && fast -> next != NULL )
        {
            s.push(slow -> val) ;
            slow = slow -> next ;
            fast = fast -> next -> next ;
        }
        if( fast != NULL )
            slow = slow -> next ;
        while( slow != NULL )
        {
            if( s.top() != slow -> val )
                return false ;
            s.pop() ;
            slow = slow -> next ;
        }
        return true ;
    }
};
