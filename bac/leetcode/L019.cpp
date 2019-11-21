/**
 * author:CliffLeopard 
 * date:2019/11/21  
 * time:12:00
 * email:precipiceleopard@gmail.com
 * link:https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}

    void addNode(int x) {
        ListNode *tail = this;
        while (tail->next != NULL)
            tail = tail->next;
        tail->next = new ListNode(x);
    }

    void travel() {
        cout << val << " ";
        ListNode *pn = next;
        while (pn) {
            cout << pn->val << " ";
            pn = pn->next;
        }
        cout << endl;
    }
};

/**
 * 一次遍历
 * 双指针，使得两指针间距为n+1；
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (!head) return NULL;
        ListNode *left = head;
        ListNode *right = head;
        int i = 0;
        while (right != NULL) {
            right = right->next;
            if (i < n + 1) {
                i++;
            } else {
                left = left->next;
            }
        }
        if (i == n)
            return head->next;
        left->next = left->next->next;
        return head;
    }
};

/**
 * 两次遍历
 */
class Solution2 {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (!head)
            return NULL;
        ListNode *ahead = head;
        int sum = 0;
        while (ahead != NULL) {
            sum++;
            ahead = ahead->next;
        }
        if (sum == n)
            return head->next;

        ahead = head;
        while (--sum > n) {
            ahead = ahead->next;
        }
        if (ahead->next)
            ahead->next = ahead->next->next;
        return head;
    }
};

int main() {
    Solution solution;
    ListNode *head = new ListNode(1);
    head->addNode(2);
    head->addNode(3);
    head->addNode(4);
//    head->addNode(5);
    head->travel();
    ListNode *node = solution.removeNthFromEnd(head, 4);
    node->travel();
}