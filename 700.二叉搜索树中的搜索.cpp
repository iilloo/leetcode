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
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
    //递归法，二叉搜索树是一颗顺序树，左儿子比根小，右儿子比根大
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL || root->val == val) {
            return root;
        }
        TreeNode* result;
        if (root->val > val) {
            result = searchBST(root->left, val);
        }
        if (root->val < val) {
            result = searchBST(root->right, val);
        }
        return result;
    }
    //迭代法，不需要使用队列或栈来辅助了
    TreeNode* searchBST_1(TreeNode* root, int val) {
        if (root == NULL) {
            return root;
        }
        while (root != NULL) {
            if (root->val == val) {
                return root;
            } else if (root->val > val) {
                root = root->left;
            } else if (root->val < val) {
                root = root->right;
            }
        }
        return NULL;
    }
};
// @lc code=end

