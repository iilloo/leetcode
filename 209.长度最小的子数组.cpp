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
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */
/* 
    滑动窗口(双指针) */
// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int reslut = 0xffffff, num = 0, i = 0, j = 0;
        for(; j < nums.size(); ++j)
        {
            num += nums[j];
            while( num >= target)
            {             
                int l = j - i +1;
                if(l < reslut)
                {
                    reslut = l;
                }
                num -= nums[i];
                ++i;
            }
        }
        if( reslut <= nums.size())
        {
            return reslut;
        }
        return 0;
    } 
};
// @lc code=end

