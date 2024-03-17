#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;
/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    // 递归法中序
    TreeNode *pre = NULL;
    void inorder(TreeNode *root, int &minSub)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left, minSub);
        if (pre != NULL)
        {
            minSub = min(minSub, root->val - pre->val);
        }
        pre = root;
        inorder(root->right, minSub);
        return;
    }
    int getMinimumDifference(TreeNode *root)
    {
        int minSub = 0x7fffffff;
        inorder(root, minSub);
        return minSub;
    }
    // 迭代法中序
    int getMinimumDifference_1(TreeNode *root)
    {
        int minSub = 0x7fffffff;
        TreeNode *pre = NULL;
        TreeNode *cur = root;
        stack<TreeNode *> ts;
        while (cur != NULL || (!ts.empty()))
        {
            if (cur != NULL)
            {
                ts.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = ts.top();
                ts.pop();
                if (pre != NULL)
                {
                    minSub = min(minSub, cur->val - pre->val);
                }
                pre = cur;

                cur = cur->right;
            }
        }
        return minSub;
    }
};
// @lc code=end
