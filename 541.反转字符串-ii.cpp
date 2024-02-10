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
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        int i = 0, length = s.size();
        int j = 0, tmp = 0;
        for (i = 0; i < length; i += (2 * k))
        {
            if (i + k < length)
            {
                j = i + k;
                //reverse为左闭右开的
                reverse(s.begin() + i, s.begin() + j);
            } else {
                reverse(s.begin() + i, s.end());
            }
            
        }
        return s;
    }
};
// @lc code=end
