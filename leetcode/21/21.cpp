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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head=nullptr;
        ListNode* ptr=nullptr;
        ListNode* l1ptr=l1;
        ListNode* l2ptr=l2;
        
        while(l1ptr!=nullptr || l2ptr!=nullptr){
            int curVal;
            if(l1ptr==nullptr){
                curVal=l2ptr->val;
                l2ptr=l2ptr->next;
            }
            else if(l2ptr==nullptr){
                curVal=l1ptr->val;
                l1ptr=l1ptr->next;
            }
            else{
                if(l1ptr->val<l2ptr->val){
                    curVal=l1ptr->val;
                    l1ptr=l1ptr->next;
                }
                else{
                    curVal=l2ptr->val;
                    l2ptr=l2ptr->next;
                }
            }
            
            if(head==nullptr){
                head=new ListNode(curVal);
                ptr=head;
            }
            else{
                ListNode* newNode=new ListNode(curVal);
                ptr->next=newNode;
                ptr=ptr->next;
            }
        }
        return head;
    }
};