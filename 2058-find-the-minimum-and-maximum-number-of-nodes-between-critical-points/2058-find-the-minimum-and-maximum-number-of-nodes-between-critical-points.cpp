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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* forward = curr->next;
        int i=0;
        int str = -1;
        int prevIdx = -1;
        int minDis = INT_MAX;
        while(forward){
            if(curr->val>prev->val && curr->val>forward->val || 
                curr->val<prev->val && curr->val<forward->val){
                if(str == -1){
                    str = i;
                    prevIdx = i;
                }
                else{
                    minDis = min(minDis,i-prevIdx);
                    prevIdx = i;
                }
            }
            
            i++;
            prev = prev->next;
            curr = curr->next;
            forward = forward->next;
        }
        int maxDis = prevIdx-str;
        if(minDis != INT_MAX){
            return {minDis,maxDis};
        }
        return {-1,-1};
    }
};