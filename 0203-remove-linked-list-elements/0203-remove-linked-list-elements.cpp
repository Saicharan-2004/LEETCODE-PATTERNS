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
    ListNode* removeElements(ListNode* head, int v) 
    {
        ListNode*ans=new ListNode(0);
        ListNode*temp=head;
        ListNode*t=ans;
        while(temp!=NULL)
        {
            if(temp->val!=v)
            {
                ans->next=temp;
                ans=ans->next;
            }
            temp=temp->next;
        }
        ans->next=NULL;
        return t->next;
    }
};