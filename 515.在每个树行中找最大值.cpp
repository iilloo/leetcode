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
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> tq;
        if (root) {
            tq.push(root);
        }
        while (!tq.empty()) {
            int max = 0;
            int csize = tq.size();
            for (int i = 0; i < csize; ++i) {
                TreeNode* node = tq.front();
                tq.pop();
                if (i == 0) {
                    max = node->val;
                } else {
                    if (node->val > max) {
                        max = node->val;
                    }
                }
                if (node->left) {
                    tq.push(node->left);
                }
                if (node->right) {
                    tq.push(node->right);
                }
            }
            res.push_back(max);
        }
        return res;
    }
};
// @lc code=end

