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
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode *root)
    {
        queue<TreeNode *> tq;
        int depth = 0;
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
                TreeNode *node = tq.front();
                tq.pop();
                if (node->left)
                {
                    tq.push(node->left);
                }
                if (node->right)
                {
                    tq.push(node->right);
                }
                if (node->left == NULL && node->right == NULL)
                {
                    return depth;
                }
            }
        }
        return depth;
    }

    // 递归法，后序求高度法
    int getDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int ldepth = getDepth(root->left);
        int rdepth = getDepth(root->right);
        if (root->left == NULL && root->right != NULL)
        {
            return 1 + rdepth;
        }
        if (root->right == NULL && root->left != NULL)
        {
            return 1 + ldepth;
        }
        return 1 + (ldepth >= rdepth ? rdepth : ldepth);
    }
    int minDepth_1(TreeNode *root)
    {
        return getDepth(root);
    }

    //递归法，前序求高度法
    int getDepth(TreeNode* root, int depth, int result) {
        if (root->left == NULL && root->right == NULL) {
            result = depth >= result ? result : depth;
            return result;
        }
        if (root->left) {
            ++depth; 
            result = getDepth(root->left, depth, result);
            --depth;
        }
        if (root->right) {
            ++depth; 
            result = getDepth(root->right, depth, result);
            --depth;
        }
        return result;
    }
    int minDepth_2(TreeNode *root)
    {
        if (!root) {
            return 0;
        }
        return getDepth(root, 1, 0x7fffffff);
    }
};
// @lc code=end
