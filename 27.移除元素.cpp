/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
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
// @lc code=start
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        // 这个方法太low了
        // int count = nums.size();
        // int j = 0;
        // vector<int> tmp = nums;
        // for(int i = 0 ; i < nums.size() ; ++i)
        // {
        //     if(nums[i] != val)
        //     {
        //         tmp[j++] = nums[i];
        //     }else {
        //         --count;
        //     }
        // }
        // nums = tmp;
        // return count;

        // 双指针法 顺序不变
        /*把双指针想象成i指向原数组，j指向一个新的空数组
        问题简化为将i指向的数组中不是val的元素腾到新的j指向的数组中(帮助理解)
        实际上双指针向前覆盖是完全可行的不会出现乱序的问题
        */
        // int i = 0,j = 0;
        // for(; i < nums.size(); ++i)
        // {
        //     if(nums[i] != val )
        //     {
        //         nums[j] = nums[i];
        //         ++j;
        //     }
        // }
        // return j;

        // 双指针法 顺序可变
        /* i指头，j指尾，
        当i指向值为val的元素时将j指向的非val值的元素覆盖到i的位置 
        */
        int i = 0, j = nums.size() - 1;
        for (; i <= j; ++i)
        {
            if (nums[i] == val)
            {
                while (j > 0 && nums[j] == val)
                {
                    --j;
                }
                if (i <= j)
                {
                    nums[i] = nums[j];
                    --j;
                }
            }
        }
        return j + 1;
    }
    //第二次遇到这个题
    int removeElement_2(vector<int> &nums, int val)
    {
        int i = 0, j = 0;
        for (; j < nums.size(); ++j)
        {
            if (nums[j] != val)
            {
                nums[i] = nums[j];
                ++i;
            }
        }
        return i;
    }
};
// @lc code=end
