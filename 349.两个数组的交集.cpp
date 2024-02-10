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
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result;
        unordered_set<int> nums1_set(nums1.begin(),nums1.end());
        for(int num : nums2)
        {
            if(nums1_set.count(num) != 0)
            {
                result.insert(num);
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};
// @lc code=end

