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
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = NULL, *cur = head, *aft = NULL;
        if (head == NULL)
        {
            return NULL;
        }
        if (head->next == NULL)
        {
            return cur;
        }

        aft = head->next;
        cur->next = pre;
        while (aft != NULL)
        {
            
            pre = cur;
            cur = aft;
            aft = aft->next;
            cur->next = pre;
            
        }
        return cur;
    }

    //二番战，双指针法
    ListNode *reverseList_1(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        if (head->next == NULL)
        {
            return head;
        }
        ListNode *i = head, *j = i->next, *k = j->next;
        i->next = NULL;
        while (k != NULL)
        {
            j->next = i;
            i = j;
            j = k;
            k = k->next;
        }
        j->next = i;
        return j;

    }
};
// @lc code=end
