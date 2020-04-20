/**
 * author:CliffLeopard 
 * date:2020/1/6  
 * time:16:33
 * email:precipiceleopard@gmail.com
 * link:
 * 记录一些常用的数据结构
 *
 */

/**
 * 双向链表：
 * 防止循环
 * Head->next = A  A->next=B B->previous=A B->next=Tail, Tail->previous=B  Head->previous=Tail;
 * A->previous=NULL;Tail->next=NULL
 */
struct ListNode {
    int key;
    ListNode *previous;
    ListNode *next;

    ListNode() : previous(NULL), next(NULL) {

    }

    ListNode(int key) : previous(NULL), next(NULL) {
        this->key = key;
    }

//        每次都插入到最前面
    void addNode(int key) {
        ListNode *ahead = this;
        ListNode *newNode = new ListNode(key);
        newNode->next = ahead->next;
        newNode->previous = ahead;
        ahead->next = newNode;

        if (!newNode->next) {
            this->previous = newNode;
        } else {
            newNode->next->previous = newNode;
        }

        this->next->previous = NULL;
    }

// 删掉最尾部元素
    int popNode() {
        if (this->previous) {
            ListNode *pop = this->previous;
            int val_pop = pop->key;
            this->previous = pop->previous;
            this->previous->next = NULL;
            return val_pop;
        }
        return -1;
    }

//        删除对应元素
    void deleteNode(int key) {
        ListNode *ahead = this;
        while (ahead->next && ahead->next->key != key) {
            ahead = ahead->next;
        }
        if (ahead->next) {
            if (ahead->next->next)
                ahead->next->next->previous = ahead;

            ahead->next = ahead->next->next;
            if (!ahead->next) {
                this->previous = ahead;
            }
        }
    }

    void forwardTravel() {
        cout << "forwardTravel:" << endl;
        ListNode *ahead = this;
        while (ahead->next) {
            cout << ahead->next->key << "  ";
            ahead = ahead->next;
        }
        cout << endl;
    }

    void backwardTravel() {
        cout << "backwardTravel:" << endl;
        ListNode *ahead = this;
        while (ahead->previous) {
            cout << ahead->previous->key << "  ";
            ahead = ahead->previous;
        }
        cout << endl;
    }
};