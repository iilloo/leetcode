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
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> mq;//双端队列
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i >= k)
            {
                if (nums[i - k] == mq.front())
                {
                    mq.pop_front();
                }
                
            }
            while ((!mq.empty()) && nums[i] > mq.back())
            {
                mq.pop_back();
            }
            mq.push_back(nums[i]);
            if (i >= k - 1) {
                res.push_back(mq.front());
            }   
        }
        return res;
    }
};
// @lc code=end
