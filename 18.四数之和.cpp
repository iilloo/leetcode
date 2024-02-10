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
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); k++) {
            // 剪枝处理
            if (nums[k] > target && nums[k] >= 0) {
            	break; // 这里使用break，统一通过最后的return返回
            }
            // 对nums[k]去重
            if (k > 0 && nums[k] == nums[k - 1]) {
                continue;
            }
            for (int i = k + 1; i < nums.size(); i++) {
                // 2级剪枝处理 和上面的减枝处理思想其实一样
                if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0) {
                    break;
                }

                // 对nums[i]去重
                if (i > k + 1 && nums[i] == nums[i - 1]) {
                    continue;
                }
                int left = i + 1;
                int right = nums.size() - 1;
                while (right > left) {
                    // nums[k] + nums[i] + nums[left] + nums[right] > target 会溢出
                    if ((long) nums[k] + nums[i] + nums[left] + nums[right] > target) {
                        right--;
                    // nums[k] + nums[i] + nums[left] + nums[right] < target 会溢出
                    } else if ((long) nums[k] + nums[i] + nums[left] + nums[right]  < target) {
                        left++;
                    } else {
                        result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        // 对nums[left]和nums[right]去重
                        while (right > left && nums[right] == nums[right - 1]) right--;
                        while (right > left && nums[left] == nums[left + 1]) left++;

                        // 找到答案时，双指针同时收缩
                        right--;
                        left++;
                    }
                }

            }
        }
        return result;
    }


    //二番战，双指针法，和15.三数之和思想一致
    vector<vector<int>> fourSum_1(vector<int>& nums, int target)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int i = 0, j = 0, left = 0, right = 0;
        for (; i < nums.size(); ++i)
        {
            if (nums[i] > target && nums[i] >= 0)
            {
                return result;
            }

            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            for (j = i + 1; j < nums.size(); ++j)
            {
                //注意这个地方剪枝的break而不是直接返回
                if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0)
                {
                    break;
                }
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                left = j + 1, right = nums.size() - 1;
                while (left < right)
                {
                    if ((long)nums[i] + nums[j] + nums[left] + nums[right] > target)
                    {
                        --right;
                    }
                    else if ((long)nums[i] + nums[j] + nums[left] + nums[right] < target)
                    {
                        ++left;
                    }
                    else
                    {
                        result.push_back(vector<int>({nums[i], nums[j], nums[left], nums[right]}));
                        ++left, --right;
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
            
        }
        return result;
    }
};

// @lc code=end

int main()
{
    vector<int> arr = {2, 2, 2, 2, 2};
    Solution *s = new Solution();
    vector<vector<int>> result = s->fourSum_1(arr, 8);
    for(int i = 0; i < result.size(); ++i)
    {
        for(int j = 0; i < result[i].size(); ++j)
        {
            cout<<result[i][j] ;
        }
        cout<<endl;
    }
    return 0;

}

