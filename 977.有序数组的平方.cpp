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
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
/* 
    双指针法
     */
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int i = 0, j = nums.size() - 1;
        int t = j;
        vector<int> reslut(nums.size(), 0);//初始化一个全为0的和nums大小一致的vector
        for (; t >= 0 ; --t)
        {
            int l = nums[i] * nums[i], r = nums[j] * nums[j];
            if (l >= r)
            {
                reslut[t] = l;
                ++i;
            }
            else
            {
                reslut[t] = r;
                --j;
            }
        }
        return reslut;
    }
};
// @lc code=end
