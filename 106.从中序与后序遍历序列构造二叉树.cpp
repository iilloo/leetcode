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
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) {
            return NULL;
        }
        int rootValue = postorder[postorder.size() - 1];
        TreeNode *root = new TreeNode(rootValue);
        if (postorder.size() == 1) {
            return root;
        }
        int inorderCutPoint;
        for (inorderCutPoint = 0; inorderCutPoint < inorder.size(); ++inorderCutPoint) {
            if (inorder[inorderCutPoint] == rootValue) {
                break;
            }
        }

        vector<int> inorderLeft(inorder.begin(), inorder.begin() + inorderCutPoint);
        vector<int> inorderRight(inorder.begin() + inorderCutPoint + 1, inorder.end());

        vector<int> postorderLeft(postorder.begin(), postorder.begin() + inorderLeft.size());
        vector<int> postorderRight(postorder.begin() + inorderLeft.size(), postorder.end() - 1);


        root->left = buildTree(inorderLeft, postorderLeft);
        root->right = buildTree(inorderRight, postorderRight);
        return root;
    }
    //上面的子vector耗时耗力，可以用下标来表示子vector的左开右闭的区间
    TreeNode* travel(vector<int> &inorder, int inL, int inR, vector<int> &postorder, int postL, int postR) {
        //递归结束条件
        if (postR == postL) {
            return NULL;
        }
        //中
        int rootValue = postorder[postR - 1];
        TreeNode* root = new TreeNode(rootValue);
        if (postL + 1 == postR) {
            return root;
        }

        int inorderCutPoint = 0;
        for(inorderCutPoint = inL; inorderCutPoint < inR; ++inorderCutPoint) {
            if (inorder[inorderCutPoint] == rootValue) {
                break;
            }
        }
        int LeftInorderL = inL;
        int LeftInorderR = inorderCutPoint;
        int RightInorderL = inorderCutPoint + 1;
        int RightInorderR = inR;

        int LeftPostorderL = postL;
        int LeftPostorderR = postL + inorderCutPoint - inL;
        int RightPostorderL = LeftPostorderR;
        int RightPostorderR = postR - 1;
        root->left = travel(inorder, LeftInorderL, LeftInorderR, postorder, LeftPostorderL, LeftPostorderR);
        root->right = travel(inorder, RightInorderL, RightInorderR, postorder, RightPostorderL, RightPostorderR);
        return root;
    }
    TreeNode* buildTree_1(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 && postorder.size() == 0) {
            return NULL;
        }
        return travel(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};
// @lc code=end

