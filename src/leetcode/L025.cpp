/**
 * author:CliffLeopard 
 * date:2019/11/26  
 * time:14:05
 * email:precipiceleopard@gmail.com
 * link:https://leetcode.com/problems/reverse-nodes-in-k-group/
 * 难度:稍复杂的链表操作
 * 部分借用24的两两交换，只不过这时候head_cur每次下移一位。
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
    static ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == nullptr || head->next == nullptr || k == 1)
            return head;


        return head;
    }
};

int main() {
    auto *input = new ListNode(1);
    input->add(2);
    input->add(3);
    input->add(4);
    input->add(5);
    input->travel();

    ListNode *result1 = Solution::reverseKGroup(input, 2);
    ListNode *result2 = Solution::reverseKGroup(input, 3);
    result1->travel();
    result2->travel();
}
 