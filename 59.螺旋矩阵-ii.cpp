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
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> reslut(n, vector(n, 0));
        int l = 0, r = n - 1, t = 0, b = n - 1, count = 1;
        while (count <= n * n)
        {
            for (int j = l; j <= r; ++j)
            {
                reslut[t][j] = count;
                ++count;
            }
            ++t;
            for (int j = t; j <= b; ++j)
            {
                reslut[j][r] = count;
                ++count;
            }
            --r;
            for (int j = r; j >= l; --j)
            {
                reslut[b][j] = count;
                ++count;
            }
            --b;
            for (int j = b; j >= t; --j)
            {
                reslut[j][l] = count;
                ++count;
            }
            ++l;
        }
        return reslut;
    }
};
// @lc code=end
