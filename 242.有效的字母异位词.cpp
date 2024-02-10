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
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        int reslut[26] = {0};
        for(int i = 0; i < s.size(); ++i)
        {
            ++reslut[s[i] - 'a'];
        }
        for(int i = 0; i < t.size(); ++i)
        {
            --reslut[t[i] - 'a'];
        }
        for (int i = 0; i < 26; i++) {
            if (reslut[i] != 0) {
                return 0;
            }
        }
        return 1;
    }
};
// @lc code=end

