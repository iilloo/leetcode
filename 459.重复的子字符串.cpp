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
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution {
public:
    void Next(string s, int *next)
    {
        int j = 0, i = 1;
        next[0] = 0;
        for (; i < s.size(); ++i)
        {
            while (j > 0 && s[j] != s[i])
            {
                j = next[j - 1];
            }
            if (s[j] == s[i])
            {
                ++j;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern(string s) {
        int length = s.size();
        int *next = new int[length];
        Next(s, next);
        if(next[length - 1] != 0 && length % (length - next[length - 1]) == 0)
        {
            return true;
        }
        return false;
    }
};
// @lc code=end

