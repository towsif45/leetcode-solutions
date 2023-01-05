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
    ListNode* swapPairs(ListNode* head) {
        ListNode *cur = head, *prev = nullptr;
        if(!head) return cur;
        if(head->next) head = head->next;
        while(cur && cur->next){
            ListNode *tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = cur;
            if(!prev){
                prev = cur; 
            }
            else{
                prev->next = tmp;
                prev = cur;
            }
            // cout << cur->val << endl;
            cur = cur->next;
        }
        return head;
    }
};