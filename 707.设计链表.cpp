#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <list>
using namespace std;
/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList
{
public:
    // 定义链表节点结构体
    struct LinkedNode
    {
        int val;
        LinkedNode *next;
        LinkedNode(int val) : val(val), next(nullptr) {}
    };
    LinkedNode *vh = NULL;
    int size = 0;
    MyLinkedList()
    {
        vh = new LinkedNode(0xffff);
        size = 0;
    }

    int get(int index)
    {
        LinkedNode *p = vh;
        for (int i = 0; i <= index; ++i)
        {
            if (p->next != NULL)
            {
                p = p->next;
            }
            else
            {
                return -1;
            }
        }
        return p->val;
    }

    void addAtHead(int val)
    {
        LinkedNode *np = new LinkedNode(val);
        np->next = vh->next;
        vh->next = np;
        ++size;
    }

    void addAtTail(int val)
    {
        LinkedNode *np = new LinkedNode(val);
        LinkedNode *p = vh;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = np;
        ++size;
    }

    void addAtIndex(int index, int val)
    {
        if (index == size)
        {
            addAtTail(val);
        }
        else if (index > size)
        {
            ;
        }
        else
        {
            LinkedNode *np = new LinkedNode(val);
            LinkedNode *p = vh;
            for (int i = 0; i < index; ++i)
            {
                p = p->next;
            }
            np->next = p->next;
            p->next = np;
            ++size;
        }
    }

    void deleteAtIndex(int index)
    {
        if (index >= 0 && index <= size - 1)
        {
            LinkedNode *p = vh;
            for (int i = 0; i < index; ++i)
            {
                p = p->next;
            }
            LinkedNode *q = p->next;
            p->next = q->next;
            delete q;
            --size;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
