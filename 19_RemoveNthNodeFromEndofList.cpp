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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = 1;
        ListNode* node = head;
        ListNode* prev;
        while(node->next != NULL){
            node = node->next;
            sz++;
        }
        if(sz-n+1 == 1){
            return head = head->next;
        }
        // cout << sz-n+1 << endl;
        node = head;
        int i=1;
        while(node->next != NULL && i<=sz-n){
            if(i == sz-n) prev = node;
            node = node->next;
            i++;
        }
        prev->next = node->next;
        // cout << node->val << endl;
        return head;
    }
};