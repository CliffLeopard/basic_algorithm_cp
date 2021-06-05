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

    ListNode(int x) : val(x), next(NULL) {

    }

    void add(int x) {
        ListNode *node = new ListNode(x);
        ListNode *tail = next;
        if (tail == NULL) {
            next = node;
        } else {
            while (tail->next != NULL) {
                tail = tail->next;
            }
            tail->next = node;
        }
    }

    void print() {
        cout << val << "  ";
        ListNode *node = next;
        while (node != NULL) {
            cout << node->val << "  ";
            node = node->next;
        }
    }
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int temp = 0;
        ListNode *head = new ListNode(-1);
        ListNode *tail = new ListNode(-1);
        head->next = tail;
        while (l1 != NULL || l2 != NULL) {
            int sum = temp;
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            ListNode *node = new ListNode(sum % 10);
            if (tail->val == -1) {
                head->next = node;
            } else {
                tail->next = node;
            }
            tail = node;
            temp = sum / 10;
        }
        if (temp != 0) {
            ListNode *tempNode = new ListNode(temp);
            tail->next = tempNode;
        }
        return head->next;
    }
};

int main() {

    ListNode *a = new ListNode(2);
    ListNode *b = new ListNode(5);
    a->add(4);
    a->add(9);
    b->add(6);
    b->add(4);

    a->print();
    cout << endl;
    b->print();
    cout << endl;
    Solution solution;
    solution.addTwoNumbers(a, b)->print();
    return 0;
}
