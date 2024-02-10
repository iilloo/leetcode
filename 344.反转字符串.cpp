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
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size() - 1, tmp = 0;
        while(l < r)
        {
            tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            ++l,--r;
        }
    }
    //双指针法
    void reverseString_2(vector<char>& s) 
    {
        int left = 0, right = s.size() - 1, tmp = 0;
        while (left < right)
        {
            tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            ++left;
            --right;
        }
    }
};
// @lc code=end

