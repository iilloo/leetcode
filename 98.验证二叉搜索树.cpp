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
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    //中序递归法
    void inorder(TreeNode* root, vector<int>& arr) {
        if (root == NULL) {
            return ;
        }
        if (root->left) {
            inorder(root->left, arr);
        }
        arr.push_back(root->val);
        if (root->right) {
            inorder(root->right, arr);
        }
        return;
    }
    bool isValidBST(TreeNode* root) {
        bool result = true;
        vector<int> arr;
        if (root == NULL) {
            return false;
        }
        inorder(root, arr);
        for (int i = 0; i < arr.size() - 1; ++i) {
            if (arr[i] >= arr[i + 1]) {
                result = false;
            }
        }
        return result;
    }

    //迭代法
    bool isValidBST_1(TreeNode* root) {
        stack<TreeNode*> ts;
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        while (cur != NULL || !ts.empty()) {
            if (cur != NULL) {
                ts.push(cur);
                cur = cur->left;
            } else {
                cur = ts.top();
                ts.pop();
                if (pre != NULL && pre->val >= cur->val) {
                    return false;
                }
                pre = cur;
                
                cur = cur->right;
            }
        }
        return true;
    }
};
// @lc code=end

