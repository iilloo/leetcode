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
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution   
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i)
        {
            int tmp = target - nums[i];
            auto iter = m.find(tmp);
            if (iter == m.end())
            {
                m[nums[i]] = i;//用下标的方式向map中添加<key, value>
                //map.insert(pair<int, int>(nums[i], i)); 用insert函数插入pair类型的元素
                //pair类型元素的第一个值作为key，第二个值作为value插入map中
            }
            else
            {
                return {iter->second, i};
            }
        }
        return {};
    }
};
// @lc code=end
