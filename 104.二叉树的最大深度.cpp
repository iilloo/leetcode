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

    //递归法 后序遍历法,求高度的过程
    int maxDepth_1(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int ld = maxDepth_1(root->left);
        int rd = maxDepth_1(root->right);
        return ld >= rd ? ld + 1 : rd + 1; 
    }

    //递归法，前序遍历法，求深度的过程
    int result;
    void getDepth(TreeNode* node, int depth) {
        result = depth > result ? depth : result;
        if (!(node->left) && !(node->right)) {
            return;
        }
        if (node->left) {
            ++depth;
            getDepth(node->left, depth);
            --depth;
        }
        if (node->right) {
            ++depth;
            getDepth(node->right, depth);
            --depth;
        }
        return;
    }
    int maxDepth_2(TreeNode *root) {
        result = 0;
        if (!root) {
            return 0;
        }
        getDepth(root, 1);
        return result;
    }
};
// @lc code=end
