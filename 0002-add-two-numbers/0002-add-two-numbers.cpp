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
        string first = "", second = "";
        while (l1) {
            first += char(l1->val + '0');
            l1 = l1->next;
        }

        while (l2) {
            second += char(l2->val + '0');
            l2 = l2->next;
        }

        int i = 0, j = 0, carry = 0;
        string result = "";

        while (i < first.size() || j < second.size() || carry) {
            int sum = carry;

            if (i < first.size())
                sum += first[i++] - '0';

            if (j < second.size())
                sum += second[j++] - '0';

            result += char(sum % 10 + '0');
            carry = sum / 10;
        }

        ListNode* Head = new ListNode(0);
        ListNode* Sum = Head;

        for (char c : result) {
            Sum->next = new ListNode(c - '0');
            Sum = Sum->next;
        }

        return Head->next;
    }
};