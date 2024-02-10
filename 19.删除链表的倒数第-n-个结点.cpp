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
using namespace std;

/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *vh = new ListNode(0xffff, head);
        ListNode *cur = vh, *aft = vh;
        for(int i = 0; i < n ; ++i)
        {
            aft = aft->next;
        }
        while(aft->next != NULL)
        {
            cur =cur->next;
            aft = aft->next;
        }
        ListNode *tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
        head = vh->next;
        delete vh;
        return head;

    }

    // 二番战，双指针法
    ListNode *removeNthFromEnd_1(ListNode *head, int n)
    {
        ListNode *vh = new ListNode(0xffff, head);
        ListNode *i = vh, *j = vh;
        for (int i = 0; i < n + 1; ++i)
        {
            j = j->next;
        }
        while (j != NULL)
        {
            i = i->next;
            j = j->next;
        }
        ListNode *tmp = i->next;
        i->next = tmp->next;
        delete tmp;
        head = vh->next;
        delete vh;
        return head;
    }
};
// @lc code=end
