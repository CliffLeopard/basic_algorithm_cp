/**
 * author:CliffLeopard 
 * date:2019/11/25  
 * time:22:31
 * email:precipiceleopard@gmail.com
 * link:https://leetcode.com/problems/generate-parentheses/
 */
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}

    void addNode(int x) {
        ListNode *head = this;
        while (head->next != NULL) {
            head = head->next;
        }
        ListNode *node = new ListNode(x);
        head->next = node;
    }

    void travel() {
        ListNode *head = this;
        while (head != NULL) {
            cout << head->val << "-->";
            head = head->next;
        }
        cout << endl;
    }
};

/**
 * 这种算法理论上不慢，但是vector的erase操作确实令人发指，造成速度极慢。576ms打败了7.57%的用户。但是内存消耗打败了98。35%。
 * 时间效率应该是O(kN),k代表单个链表中元素个数。
 */
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *result;

        vector<ListNode *>::iterator iter1 = lists.begin();
        while (iter1 != lists.end()) {
            if (*iter1 != NULL) {
                iter1++;
            } else {
                *iter1 = *(lists.end() - 1);
                lists.pop_back();
            }
        }

        if (lists.size() == 0)
            return NULL;
        if (lists.size() == 1)
            return lists[0];

        int n = lists.size();
        vector<ListNode *>::iterator iter2 = lists.begin() + 1;
        for (iter2; iter2 != lists.end(); iter2++) {
            if ((*iter2)->val < lists[0]->val) {
                ListNode *temp = lists[0];
                lists[0] = *iter2;
                *iter2 = temp;
            }
        }

        result = lists[0];
        if (lists[0]->next == NULL) {
            lists[0]->next = lists[1];

            *(lists.begin() + 1) = *(lists.end() - 1);
            lists.pop_back();
        }

        while (lists.size() > 1) {
            vector<ListNode *>::iterator iterator1 = lists.begin() + 1;
            while (iterator1 != lists.end()) {
                if (*iterator1 != NULL) {
                    if ((*iterator1)->val < lists[0]->next->val) {
                        ListNode *temp = lists[0]->next;
                        lists[0]->next = *iterator1;
                        *iterator1 = temp;
                    }
                    iterator1++;
                } else {
                    *iterator1 = *(lists.end() - 1);
                    lists.pop_back();
                }
            }
            lists[0] = lists[0]->next;
            if (lists.size() == 1)
                break;
            if (lists[0]->next == NULL) {
                lists[0]->next = lists[1];
                *(lists.begin() + 1) = *(lists.end() - 1);
                lists.pop_back();
            }
        }
        return result;
    }
};

/**
 * 使用分治算法
 * 直接捞过来21的两个链表合并，之后两两合并，直到一个。
 */
#include <queue>

class Solution2 {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        queue<ListNode *> list_queue;
        vector<ListNode *>::iterator iter1 = lists.begin();
        while (iter1 != lists.end()) {
            if (*iter1 != NULL)
                list_queue.push(*iter1);
            iter1++;
        }

        if (list_queue.empty())
            return NULL;
        while (list_queue.size() > 1) {
            ListNode *node1 = list_queue.front();
            list_queue.pop();
            ListNode *node2 = list_queue.front();
            list_queue.pop();
            list_queue.push(mergeTwoLists(node1, node2));
        }
        return list_queue.front();
    }

private:
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


int main() {

    ListNode *A = new ListNode(1);
    ListNode *B = new ListNode(1);
    ListNode *C = new ListNode(2);
    ListNode *D = new ListNode(0);

    A->addNode(4);
    A->addNode(5);

    B->addNode(3);
    B->addNode(4);

    C->addNode(6);

    A->travel();
    B->travel();
    C->travel();

    vector<ListNode *> lists;
    lists.push_back(A);
    lists.push_back(B);
    lists.push_back(NULL);
    lists.push_back(C);
    lists.push_back(D);

    Solution2 solution;
    ListNode *result = solution.mergeKLists(lists);
    result->travel();
    return 0;
}