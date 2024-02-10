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
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
//双指针法(双指针只是思想，实际上可能有多个指针，此题用到了三个指针)
// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0, left = 0, right = 0; i < nums.size(); ++i)
        {
            // 如果i下标处的元素>0 则后面的全 > 0 和nums[i] + nums[left] + nums[right]必定 > 0
            if (nums[i] > 0)
            {
                return result;
            }
            // 对下标i处指向的元素的去重，如果当前i下标处的元素与上次i指向的元素一致
            // 则此次情况与上次情况一致就不用考虑此情况
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            left = i + 1;
            right = nums.size() - 1;
            while (right > left)
            {
                if ((nums[i] + nums[left] + nums[right]) > 0)
                {
                    --right;
                    continue;
                }
                if ((nums[i] + nums[left] + nums[right]) < 0)
                {
                    ++left;
                    continue;
                }
                if ((nums[i] + nums[left] + nums[right]) == 0)
                {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // 对left和right处的元素的去重(如果当前情况与下一个情况一致则直接指向下一情况所对应的元素处)
                    while (right > left && nums[left] == nums[left + 1])
                    {
                        ++left;
                    }
                    while (right > left && nums[right] == nums[right - 1])
                    {
                        --right;
                    }
                    // 两个while循环出来后left指向最右相同元素位置(与=0时的left元素值一致)
                    // right指向最左相同元素位置(与=0时的right指向元素的值一致)

                    ++left;
                    --right;
                }
            }
        }
        return result;
    }


    //二番战，双指针法
    vector<vector<int>> threeSum_1(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int i = 0, left = 0, right = 0;
        for (; i < nums.size(); ++i)
        {
            if (nums[i] > 0)
            {
                return result;
            }
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            left = i + 1, right = nums.size() - 1;
            while (left < right)
            {
                if (nums[i] + nums[left] + nums[right] > 0)
                {
                    --right;
                }
                else if (nums[i] + nums[left] + nums[right] < 0)
                {
                    ++left;
                }
                else 
                {
                    result.push_back({nums[i], nums[left], nums[right]});
                    --right, ++left;
                    while (left < right && nums[left] == nums[left - 1])
                    {
                        ++left;
                    }
                    while (left < right && nums[right] == nums[right + 1])
                    {
                        --right;
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end
