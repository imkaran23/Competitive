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
        ListNode* ans = new ListNode;
        ListNode* res = ans;
        int c = 0;
        while(l1!=nullptr || l2!=nullptr){
            int d1=0, d2=0;
            if(l1!=nullptr){ d1 = l1->val; l1 = l1->next;}
            if(l2!=nullptr){ d2 = l2->val; l2 = l2->next;}
            // cout<<d1<<" "<<d2<<" "<<c<<endl;
            ans->next = new ListNode((c+d1+d2)%10);
            ans = ans->next;
            c = (c+d1+d2)/10;
        } 
        
        if(c>0) ans->next = new ListNode(c);
        return res->next;
    }
};