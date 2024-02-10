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
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        int sum = n;
        while(sum != 1)
        {
            int i = 0, j = sum;
            sum = 0;
            while(j != 0)
            {
                i = j % 10;
                j = j / 10;
                sum += i * i;
            }
            if(s.count(sum) == 0)
            {
                s.insert(sum);
            }
            else 
            {
                return 0;
            } 
        }
        return 1;
    }
};
// @lc code=end

