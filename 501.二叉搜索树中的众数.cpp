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
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    //递归法
    int maxCount = 0;
    int count = 0;
    vector<int> result;
    TreeNode* pre = NULL;
    void inorder(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inorder(root->left);
        if (pre == NULL) {
            count = 1;
        } else if (pre->val == root->val) {
            count++;
        } else {
            count = 1;
        }
        pre = root;

        if (count == maxCount) {
            result.push_back(root->val);
        } else if (count > maxCount) {
            maxCount = count;
            result.clear();
            result.push_back(root->val);
        }

        inorder(root->right);
        return;
    }
    vector<int> findMode(TreeNode* root) {
        result.clear();
        inorder(root);
        return result;
    }

    //迭代法，中序
    vector<int> findMode_1(TreeNode* root) {
        int maxCount = 0;
        int count = 0;
        vector<int> result;
        stack<TreeNode*> ts;
        TreeNode* pre = NULL;
        TreeNode* cur = root;
        while (cur != NULL || ts.empty() != 1) {
            if (cur != NULL) {
                ts.push(cur);
                cur = cur->left;
            } else {
                cur = ts.top();
                ts.pop();
                if (pre == NULL) {
                    count = 1;
                } else if (pre->val == cur->val) {
                    ++count;
                } else {
                    count = 1;
                }
                
                if (count == maxCount) {
                    result.push_back(cur->val);
                } else if (count > maxCount) {
                    result.clear();
                    maxCount = count;
                    result.push_back(cur->val);
                }
                pre = cur;
                cur = cur->right;
            }
        }
        return result;
    }
};
// @lc code=end

