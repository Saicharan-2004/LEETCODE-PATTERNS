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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode*temp=head;
        ListNode*ans=new ListNode(0);
        ListNode*r=ans;
        while(temp!=NULL)
        {
            int t=temp->val;
            ans->next=temp;
            ans=ans->next;
            while(temp->next!=NULL && temp->next->val==t)
            {
                temp=temp->next;
            }
            if(temp->next==NULL){
                ans->next=NULL;
                return r->next;
            }
            temp=temp->next;
        }

        return r->next;
    }
};