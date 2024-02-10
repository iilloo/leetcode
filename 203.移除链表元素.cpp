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
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */
/* 添加了虚拟头节点的情况 */
/* Definition for singly-linked list. */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *vh = new ListNode(0xffff, head);
        ListNode *j = head, *i = vh;
        while (j != NULL)
        {
            if (j->val == val)
            {
                i->next = j->next;
                ListNode *tmp = j;
                j = j->next;
                delete tmp;
            }
            else
            {
                i = j;
                j = j->next;
            }
        }
        head = vh->next;
        delete vh;
        return head;
    }
};
// @lc code=end
