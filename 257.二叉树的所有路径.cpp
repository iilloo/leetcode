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
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    //递归法，前序
    void travel(TreeNode* root, vector<int> &path, vector<string> &result) {
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            string cp = "";
            for (int i = 0; i < path.size() - 1; ++i) {
                cp += to_string(path[i]);
                cp += "->";
            }
            cp += to_string(path[path.size() -1]);
            result.push_back(cp);
            return;
        }
        
        if (root->left) {
            travel(root->left, path, result);
            path.pop_back();
        }
        if (root->right) {
            travel(root->right, path, result);
            path.pop_back();
        }
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> result;
        if (!root) {
            return result;
        }
        travel(root, path, result);
        return result;
    }
    //迭代法，前序
    vector<string> binaryTreePaths_1(TreeNode* root) {
        stack<TreeNode*> ts;
        stack<string> path;
        vector<string> result;
        if (root) {
            ts.push(root);
        }
        path.push(to_string(root->val));
        while (!ts.empty()) {
            TreeNode* tmp = ts.top();
            ts.pop();
            string p = path.top();
            path.pop();
            if ((tmp->left == NULL) && (tmp->right == NULL)) {
                result.push_back(p);
            }
            if (tmp->right) {
                ts.push(tmp->right);
                path.push(p + "->" + to_string(tmp->right->val));

            }
            if (tmp->left) {
                ts.push(tmp->left);
                path.push(p + "->" + to_string(tmp->left->val));

            }
        }
        return result;
    }
};
// @lc code=end

