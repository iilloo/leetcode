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
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode *root)
    {
        int depth = 0;
        queue<TreeNode *> tq;
        if (root)
        {
            tq.push(root);
        }
        while (!tq.empty())
        {
            int csize = tq.size();
            ++depth;
            for (int i = 0; i < csize; ++i)
            {
                TreeNode *tmp = tq.front();
                tq.pop();

                if (tmp->left)
                {
                    tq.push(tmp->left);
                }
                if (tmp->right)
                {
                    tq.push(tmp->right);
                }
            }
        }
        return depth;
    }
};
// @lc code=end
