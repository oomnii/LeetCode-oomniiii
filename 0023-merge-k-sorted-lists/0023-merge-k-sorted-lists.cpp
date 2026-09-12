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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> vals;

        // Step 1: collect all values
        for (auto list : lists) {
            while (list) {
                vals.push_back(list->val);
                list = list->next;
            }
        }

        // If empty input
        if (vals.empty()) return nullptr;

        // Step 2: sort values
        sort(vals.begin(), vals.end());

        // Step 3: build new linked list
        ListNode* head = new ListNode(vals[0]);
        ListNode* curr = head;
        for (int i = 1; i < vals.size(); i++) {
            curr->next = new ListNode(vals[i]);
            curr = curr->next;
        }

        return head;
    }
};
