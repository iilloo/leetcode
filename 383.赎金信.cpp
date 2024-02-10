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
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};
        for(int i = 0; i < magazine.size(); ++i)
        {
            ++record[magazine[i] - 'a'];
        }
        for(int i = 0; i < ransomNote.size(); ++i)
        {
            if((--record[ransomNote[i] - 'a']) < 0)
            {
                return 0;
            }
        }
        return 1;
    }
};
// @lc code=end

