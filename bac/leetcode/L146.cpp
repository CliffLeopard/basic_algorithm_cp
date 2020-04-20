/**
 * author:CliffLeopard 
 * date:2020/1/6  
 * time:12:13
 * email:precipiceleopard@gmail.com
 * link:https://leetcode.com/problems/lru-cache/
 */

#include <iostream>
#include "unordered_map"
#include "list"

using namespace std;

class LRUCache {

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->head = new ListNode();
        this->contain = 0;
    }

    int get(int key) {
        if (capacity < 1)
            return -1;
        ListNode *ahead = head->next;
        while (ahead && ahead->key != key) {
            ahead = ahead->next;
        }
        if (ahead) {
            //存在对应的key,向前移动
            int rest = ahead->value;
            if (ahead->previous) {
                ahead->previous->next = ahead->next;
                if (ahead->next) {
                    ahead->next->previous = ahead->previous;
                } else {
                    if (ahead->previous)
                        head->previous = ahead->previous;
                    else
                        head->previous = ahead;
                }

                ahead->next = head->next;
                ahead->previous = NULL;
                head->next->previous = ahead;
                head->next = ahead;
            }
            return rest;
        } else
            return -1;
    }

    void put(int key, int value) {
        if (capacity < 1)
            return;

        ListNode *ahead = head->next;
        while (ahead && ahead->key != key) {
            ahead = ahead->next;
        }
        if (ahead) {
            // 存在对应的key值。向前移动
            ahead->value = value;
            if (ahead->previous) {
                ahead->previous->next = ahead->next;

                if (ahead->next) {
                    ahead->next->previous = ahead->previous;
                } else {
                    if (ahead->previous)
                        head->previous = ahead->previous;
                    else
                        head->previous = ahead;
                }

                ahead->next = head->next;
                ahead->previous = NULL;
                head->next->previous = ahead;
                head->next = ahead;
            }
        } else {
            //不存在对应key值，增加一个
            ListNode *newNode = new ListNode(key, value);
            newNode->next = head->next;
            if (head->next)
                head->next->previous = newNode;
            else
                head->previous = newNode;
            head->next = newNode;
            contain++;
            if (contain > capacity) {
                contain--;
                if (head->previous->previous) {
                    head->previous->previous->next = NULL;
                }
                head->previous = head->previous->previous;
            }
        }
    }

private:
    struct ListNode {
        int key;
        int value;
        ListNode *previous;
        ListNode *next;

        ListNode() : previous(NULL), next(NULL) {}

        ListNode(int key, int value) : previous(NULL), next(NULL) {
            this->key = key;
            this->value = value;
        }
    };

    ListNode *head;
    int contain = 0;
    int capacity;
};

class LRUCache2 {
public:
    LRUCache2(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        auto iter = myMap.find(key);
        if (iter == myMap.end()) return -1;

        mylist.splice(mylist.begin(), mylist, iter->second);
        return iter->second->second;
    }

    void put(int key, int value) {
        auto iter = myMap.find(key);
        if (iter != myMap.end()) {
            iter->second->second = value;
            mylist.splice(mylist.begin(), mylist, iter->second);
        } else {
            mylist.insert(mylist.begin(), make_pair(key, value));
            myMap[key] = mylist.begin();
            if (myMap.size() > cap) {
                myMap.erase(mylist.rbegin()->first);
                mylist.pop_back();
            }
        }
    }

private:
    int cap;
    list<pair<int, int>> mylist;
    unordered_map<int, list<pair<int, int>>::iterator> myMap;
};


int main() {
    LRUCache cache = LRUCache(1);
    cache.put(2, 1);
    cout << cache.get(2) << endl;
    cache.put(3, 2);
    cout << cache.get(2) << endl;
    cout << cache.get(3) << endl;
//    cache.put(4, 4);
//    cout << cache.get(1) << endl;
//    cout << cache.get(3) << endl;
//    cout << cache.get(4) << endl;
    return 0;
}

int main2() {
    map<int, int> mp;
    for (int i = 0; i < 3; i++) {
        mp[i] = i * 100;
    }
    map<int, int>::iterator iterator;
    for (iterator = mp.begin(); iterator != mp.end(); iterator++) {
        cout << "key:" << iterator->first << "  value:" << iterator->second << endl;
    }
    return 0;

}