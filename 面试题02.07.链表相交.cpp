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
//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *i = headA, *j = headB;
        int sizeA = 0, sizeB = 0;
        while( i != NULL)
        {
            i = i->next;
            ++sizeA;
        }
        while(j != NULL)
        {
            j = j->next;
            ++sizeB;
        }
        i = headA, j = headB;
        int sub = sizeA - sizeB;
        if(sub < 0)
        {
            for(int t = sub; t < 0; ++t)
            {
                j = j->next;
            }
        }
        else
        {
            for(int t = 0; t < sub; ++t)
            {
                i = i->next;
            }
        }
        while(i != NULL)
        {
            if(i == j)//判断地址是否相同
            {
                return i;
            }
            i = i->next;
            j = j->next;
        }
        return NULL;
    }

    //二番战，双指针法
    ListNode *getIntersectionNode_1(ListNode *headA, ListNode *headB)
    {
        ListNode *i = headA, *j = headB;
        int countA = 0, countB = 0;
        while (i != NULL)
        {
            ++countA;
            i = i->next;
        }
        i = headA;
        while (j != NULL)
        {
            ++countB;
            j = j->next;
        }
        j = headB;
        if (countA < countB)
        {
            int tmp = countB - countA;
            while (tmp > 0)
            {
                j = j->next;
                --tmp;
            }
        }
        else
        {
            int tmp = countA - countB;
            while (tmp > 0)
            {
                i = i->next;
                --tmp;
            }
        }
        while (i != NULL)
        {
            if (i == j)
            {
                return i;
            }
            i = i->next;
            j = j->next;
        }
        return NULL;
    }

};