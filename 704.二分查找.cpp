/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <list>
using namespace std;
// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while( left <= right)
        {
            mid = ( right - left ) / 2 + left;
            if( nums[mid] == target )
            {
                return mid;
            }
            if( target > nums[mid] )
            {
                left = mid + 1;
            }
            if( target < nums[mid] )
            {
                right = mid -1 ;
            }
        }
        return -1;
    }
};
// @lc code=end

