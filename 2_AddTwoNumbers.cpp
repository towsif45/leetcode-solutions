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
        ListNode* tmp1 = l1, *tmp2=l2, *ans=NULL;
        ListNode* cur_node;
        int carry=0;
        while(tmp1 != NULL || tmp2 != NULL){
            int d = carry;
            if(tmp1 != NULL) d += tmp1->val;
            if(tmp2 != NULL) d += tmp2->val;
            
            carry = d/10;
            d %= 10;
            if(ans == NULL){
                ans = new ListNode(d);
                cur_node = ans;
            }
            else{
                ListNode* new_node = new ListNode(d);
                cur_node->next = new_node;
                cur_node = new_node;
            }
            if(tmp1 != NULL) tmp1 = tmp1->next;
            if(tmp2 != NULL) tmp2 = tmp2->next;
        }
        if(carry){
            ListNode* new_node = new ListNode(carry);
            cur_node->next = new_node;
            cur_node = new_node;
        }
        
        return ans;
    }
};