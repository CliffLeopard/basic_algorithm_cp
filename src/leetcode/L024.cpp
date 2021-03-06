/**
 * author:CliffLeopard 
 * date:2019/11/26  
 * time:13:12
 * email:precipiceleopard@gmail.com
 * link:https://leetcode.com/problems/swap-nodes-in-pairs/submissions/
 * 简单的链表操作
 */
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}

    void add(int x) {
        ListNode *head = this;
        while (head->next) {
            head = head->next;
        }
        auto *new_node = new ListNode(x);
        head->next = new_node;
    }

    void travel() {
        ListNode *head = this;
        while (head) {
            cout << head->val << "  ";
            head = head->next;
        }
        cout << endl;
    }
};

class Solution {
public:
    static ListNode *swapPairs(ListNode *head) {
        auto *head_cur = new ListNode(-1);
        ListNode *result = head_cur;
        ListNode *temp;
        head_cur->next = head;
        if (!head || head->next == nullptr)
            return head;
        while (head && head->next) {
            temp = head->next->next;
            head_cur->next = head->next;
            head_cur->next->next = head;
            head->next = temp;

            head_cur = head_cur->next->next;
            head = head_cur->next;
        }
        return result->next;
    }
};

int main() {
    auto *input = new ListNode(1);
    input->add(2);
    input->add(3);
    input->add(4);
    input->add(5);
    input->add(6);
    input->travel();
    ListNode *result = Solution::swapPairs(input);
    result->travel();
}