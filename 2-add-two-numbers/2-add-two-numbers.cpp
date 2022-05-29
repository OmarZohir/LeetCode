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
        // while one of the lists is still not empty, keep on traversing the linked list and adding elements
        int l1_val, l2_val, sum;
        int carry = 0;
        // create this dummy head to be able to trace the end of the linked list
        ListNode* dummy_head = new ListNode();
        ListNode* l3 = dummy_head;
        
        while (l1 != nullptr || l2 != nullptr){
            l1_val = (l1 != NULL) ? l1->val: 0;
            l2_val = (l2 != NULL) ? l2->val: 0;
            
             
            sum = l1_val + l2_val + carry;
            carry = sum/10;
            sum = sum%10;
            
            ListNode* cur = new ListNode(sum);
            l3->next = cur;
            
            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
            l3 = cur;
        }
        
        if (carry > 0){
            ListNode* new_node = new ListNode(carry);
            l3->next = new_node;
            l3 = new_node;
        }
        
        return dummy_head->next;
    }
};