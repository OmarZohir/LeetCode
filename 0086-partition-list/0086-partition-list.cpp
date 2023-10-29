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
    ListNode* partition(ListNode* head, int x) {
        //create two linkedlists and join them towards the end
        ListNode* smallHead = new ListNode();
        ListNode* largeHead = new ListNode();
        ListNode* curSmall = smallHead;
        ListNode* curLarge = largeHead;
        while (head != nullptr){
            //Add to small list
            if (head->val < x){
                if (smallHead == nullptr){
                    smallHead = head;
                    curSmall = head;
                    head = head->next;
                    curSmall->next = nullptr;
                }
                else{
                    curSmall->next = head;
                    curSmall = curSmall->next;
                    head = head->next;
                    curSmall->next = nullptr;
                }
            }
            // Add to large list
            else {
                if (largeHead == nullptr){
                    largeHead = head;
                    curLarge = head;
                    head = head->next;
                    curLarge->next = nullptr;
                }
                else{
                    curLarge->next = head;
                    curLarge = curLarge->next;
                    head = head->next;
                    curLarge->next = nullptr;
                }
            }
        }
        curSmall->next = largeHead->next;
        return smallHead->next;
    }
};