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
        stack<int>s1, s2;
        while( temp1 != NULL )
        {
            s1.push(temp1->val);
            temp1 = temp1->next;
        }
        
        while( temp2 != NULL )
        {
            s2.push(temp2-> val);
            temp2 = temp2->next;
        }
        ListNode* nxt = NULL;
        ListNode* node;
        int c = 0, sum;
        while( !s1.empty() && !s2.empty() )
        {
            
            sum = s1.top() + s2.top() + c;
            node = new ListNode(sum%10);
            c = sum/10;
            s1.pop();
            s2.pop();
            node->next = nxt;
            nxt = node;
        }
        while( !s1.empty() )
        {
            sum = s1.top() + c;
            node = new ListNode(sum%10);
            c = sum/10;
            s1.pop();
            node->next = nxt;
            nxt = node;
        }
        while( !s2.empty() )
        {
            sum = s2.top() + c;
            node = new ListNode(sum%10);
            c = sum/10;
            s2.pop();
            node->next = nxt;
            nxt = node;
        }
        if( c == 1 )
        {
            node = new ListNode(1);
            node->next = nxt;
            nxt = node;
        }
        return node;
    }
};
