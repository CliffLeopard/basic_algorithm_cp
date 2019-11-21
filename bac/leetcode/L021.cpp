/**
 * author:CliffLeopard 
 * date:2019/11/21  
 * time:18:35
 * email:precipiceleopard@gmail.com
 * link:
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
        while (pn != NULL) {
            cout << pn->val << " ";
            pn = pn->next;
        }
        cout << endl;
    }
};

/**
 * 不需要额外结点
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;


        if (l2->val < l1->val) {
            ListNode *temp0 = l1;
            l1 = l2;
            l2 = temp0;
        }
        ListNode *head = l1;

        while (true) {
            if (l1->next == NULL) {
                l1->next = l2;
                break;
            }

            if (l2->val < l1->next->val) {
                ListNode *temp1 = l1->next;
                l1->next = l2;
                l2 = temp1;
                if (l2 == NULL)
                    break;
            } else {
                l1 = l1->next;
            }

        }
        return head;
    }
};

/**
 * 添加两个头节点
 */
class Solution2 {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode *head = new ListNode(-1);
        ListNode *tail = new ListNode(-1);
        head->next = tail;
        while (true) {
            if (l2->val < l1->val) {
                tail->next = l2;
                tail = tail->next;
                l2 = l2->next;
                if (l2 == NULL) {
                    tail->next = l1;
                    break;
                }
            } else {
                tail->next = l1;
                tail = tail->next;
                l1 = l1->next;
                if (l1 == NULL) {
                    tail->next = l2;
                    break;
                }
            }
        }
        return head->next->next;
    }
};

int main() {
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(1);
    a->addNode(2);
    a->addNode(4);
    b->addNode(3);
    b->addNode(4);
    a->travel();
    b->travel();
    Solution2 solution;
    ListNode *result = solution.mergeTwoLists(a, b);
    result->travel();
}