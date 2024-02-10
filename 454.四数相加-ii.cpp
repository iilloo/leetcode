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
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums1.size(); ++i)
        {
            for(int j = 0; j < nums2.size(); ++j)
            {
                int sum = nums1[i] + nums2[j];
                auto iter = m.find(sum);
                if(iter == m.end())
                {
                    m.insert(pair<int, int>(sum, 1));
                }
                else
                {
                    ++(iter->second);
                }
            }
        }
        int count = 0;
        for(int i = 0; i < nums3.size(); ++i)
        {
            for(int j = 0; j < nums4.size(); ++j)
            {
                int sum = 0 - (nums3[i] + nums4[j]);
                auto iter = m.find(sum);
                if(iter != m.end())
                {
                    count += iter->second;
                }
            }
        }
        return count;
    }
};
// @lc code=end

