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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        
        while(fast){
            if(fast->next && fast->next->next) fast = fast->next->next;
            else return nullptr;
            slow = slow->next;
            if(fast == slow) break;
        }
        ListNode *kitty = head;
        while(kitty != slow) kitty = kitty->next, slow = slow->next;
        return kitty;
    }
};