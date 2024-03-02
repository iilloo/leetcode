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
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
class Solution {
public:
    //递归法，后序遍历法
    int getHeight(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int lH = getHeight(root->left);
        int rH = getHeight(root->right);
        if (lH == -1 || rH == -1) {
            return -1;
        } else if ((lH - rH > 1) || (rH - lH > 1)) {
            return -1;
        }
        return 1 + (lH > rH ? lH : rH);
    }
    bool isBalanced(TreeNode* root) {
        int res = getHeight(root);
        if (res == -1) {
            return 0;
        }
        return 1;
    }
    //此题也可以用迭代法，但其实效率很低，
    //没有很好的模拟回溯的过程，有很多重复的计算
};
// @lc code=end

