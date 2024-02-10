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
#include <string>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fp = head, *sp = head;
        int step = 0;
        while (fp != NULL && fp->next != NULL)
        {
            fp = fp->next->next;
            sp = sp->next;
            ++step;
            if (fp == sp)
            {
                break;
            }
        }
        if (fp != sp || step == 0)
        {
            return NULL;
        }
        ListNode *i = head, *j = fp;
        while (i != j)
        {
            i = i->next;
            j = j->next;
        }
        return i;
    }

    // 二番战，双指针法
    ListNode *detectCycle_1(ListNode *head)
    {
        ListNode *sp = head, *fp = head;
        int step = 0;
        while (fp != NULL && fp->next != NULL)
        {
            sp = sp->next;
            fp = fp->next->next;
            ++step;
            if (fp == sp)
            {
                break;
            }
        }
        if (fp != sp || step == 0)
        {
            return NULL;
        }
        ListNode *meet = sp, *i = head;
        while (meet != i)
        {
            meet = meet->next;
            i = i->next;
        }
        return i;
    }
};
// @lc code=end
