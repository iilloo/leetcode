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
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    void travel(TreeNode* root, int depth, int &maxDepth, int &leftValue) {
        
        if (root->left == NULL && root->right == NULL) {
            if (depth > maxDepth) {
                maxDepth = depth;//保证在该深度下只有最左边的结点才能进入该if语句
                leftValue = root->val;
            }
            return;
        }
        if (root->left) {
            travel(root->left, depth + 1, maxDepth, leftValue);
        }
        if (root->right) {
            travel(root->right, depth + 1, maxDepth, leftValue);
        }
        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        int maxDepth = 0, leftValue = 0;
        travel(root, 1, maxDepth, leftValue);
        return leftValue;
    }
};
// @lc code=end

