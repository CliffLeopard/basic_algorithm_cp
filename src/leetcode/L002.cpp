/**
 * author:CliffLeopard
 * date:2019/11/10
 * time:15:43
 * email:precipiceleopard@gmail.com
 * link:https://leetcode.com/problems/add-two-numbers
 */

#include<iostream>

using namespace std;

/**
 * 难度:简单
 * 基础队列问题
 */
struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {

    }

    void add(int x) {
        auto *node = new ListNode(x);
        ListNode *tail = next;
        if (tail == nullptr) {
            next = node;
        } else {
            while (tail->next != nullptr) {
                tail = tail->next;
            }
            tail->next = node;
        }
    }

    void print() const {
        cout << val << "  ";
        ListNode *node = next;
        while (node != nullptr) {
            cout << node->val << "  ";
            node = node->next;
        }
    }
};

class Solution {
public:
    static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int temp = 0;
        auto *head = new ListNode(-1);
        auto *tail = new ListNode(-1);
        head->next = tail;
        while (l1 != nullptr || l2 != nullptr) {
            int sum = temp;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            auto *node = new ListNode(sum % 10);
            if (tail->val == -1) {
                head->next = node;
            } else {
                tail->next = node;
            }
            tail = node;
            temp = sum / 10;
        }
        if (temp != 0) {
            auto *tempNode = new ListNode(temp);
            tail->next = tempNode;
        }
        return head->next;
    }
};

int main() {

    auto *a = new ListNode(2);
    auto *b = new ListNode(5);
    a->add(4);
    a->add(9);
    b->add(6);
    b->add(4);

    a->print();
    cout << endl;
    b->print();
    cout << endl;
    Solution::addTwoNumbers(a, b)->print();
    return 0;
}
