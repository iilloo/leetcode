#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <list>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> res;
        queue<TreeNode *> tq;
        if (root)
        {
            tq.push(root);
        }
        while (!tq.empty())
        {
            double num = 0;
            int csize = tq.size();
            for (int i = 0; i < csize; ++i)
            {
                TreeNode *node = tq.front();
                tq.pop();
                num += node->val;
                if (i == csize - 1)
                {
                    res.push_back(num / csize);
                }
                if (node->left)
                {
                    tq.push(node->left);
                }
                if (node->right)
                {
                    tq.push(node->right);
                }
            }
        }
        return res;
    }
};
// @lc code=end
