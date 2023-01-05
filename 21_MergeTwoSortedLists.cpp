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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        ListNode *head = nullptr, *cur1 = list1, *cur2 = list2, *cur = nullptr;
        
        while(cur1 && cur2){
            // cout << cur1->val << " " << cur2->val << endl;
            if(cur1->val <= cur2->val){
                if(cur) cur->next = cur1, cur = cur->next;
                else head = cur1, cur = head;
                cur1 = cur1->next;
            }
            else{
                if(cur) cur->next = cur2, cur = cur->next;
                else head = cur2, cur = head;
                cur2 = cur2->next;
            }
            // cout << cur->val << endl;
        }
        while(cur1) cur->next = cur1, cur = cur->next, cur1 = cur1->next;
        while(cur2) cur->next = cur2, cur = cur->next, cur2 = cur2->next;
        return head;
    }
};