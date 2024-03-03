#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    //递归法，我个人认为是中序和后序的结合
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        if (root->left == NULL && root->right == NULL)
        {
            return 0;
        }
        int ls = sumOfLeftLeaves(root->left);
        if (root->left != NULL && root->left->left == NULL && root->left->right == NULL)
        {
            ls = root->left->val;
        }
        int rs = sumOfLeftLeaves(root->right);
        return ls + rs;
    }
    //递归法，前序
    void travel(TreeNode *root, int &sum) {
        if (!root) {
            return;
        }
        if (root->left != NULL && 
            root->left->left == NULL && 
            root->left->right == NULL) {
                sum += root->left->val;
        }
        if (root->left) {
            travel(root->left, sum);
        }
        if (root->right) {
            travel(root->right, sum);
        }
        return;
    }
    int sumOfLeftLeaves_1(TreeNode *root) {
        int sum = 0;
        travel(root, sum);
        return sum;
    }

    //迭代法，前序(其他的顺序也可以做)
    int sumOfLeftLeaves_2(TreeNode *root) {
        stack<TreeNode*> ts;
        int sum = 0;
        if (root != NULL) {
            ts.push(root);
        }
        while (!ts.empty()) {
            TreeNode* tmp = ts.top();
            ts.pop();
            if (tmp->left != NULL && tmp->left->left == NULL && tmp->left->right == NULL) {
                sum += tmp->left->val;
            }
            if (tmp->left) {
                ts.push(tmp->left);
            }
            if (tmp->right) {
                ts.push(tmp->right);
            }
        }
        return sum;
    }
};
// @lc code=end
