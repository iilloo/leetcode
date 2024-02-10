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
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *vh = new ListNode(0xffff, head);
        ListNode *pre = vh, *cur = head, *after = NULL;
        if(cur == NULL)
        {
            return NULL;
        }
        if(cur->next == NULL)
        {
            return cur;
        }
        for(after = cur->next; after != NULL; after = after->next)
        {
            cur->next = after->next;
            after->next = pre->next;
            pre->next = after;
            ListNode *tmp = after;
            after = cur;
            cur = after;

            pre = after;
            cur = after->next;
            if(after->next != NULL)
            {
                after = after->next;
            }
        }
        head = vh->next;
        delete vh;
        return head;
    }
};
// @lc code=end
