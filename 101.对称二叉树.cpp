#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <list>
#include <string>
#include <stack>
using namespace std;
/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool compare(TreeNode *left, TreeNode *right)
    {
        if (left && !right)
        {
            return false;
        }
        else if (right && !left)
        {
            return false;
        }
        else if (!right && !left)
        {
            return true;
        }
        else if (right->val != left->val)
        {
            return false;
        }
        bool out = compare(left->left, right->right);
        bool in = compare(left->right, right->left);
        return out && in;
    }
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }
        return compare(root->left, root->right);
    }
    // 迭代法，用栈实现
    bool isSymmetric_1(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }
        queue<TreeNode *> ts;
        ts.push(root->left);
        ts.push(root->right);
        while (!ts.empty())
        {
            TreeNode *lt = ts.front();
            ts.pop();
            TreeNode *rt = ts.front();
            ts.pop();
            if (lt && !rt)
            {
                return false;
            }
            else if (!lt && rt)
            {
                return false;
            }
            else if (!lt && !rt)
            {
                continue;
            }
            else if (lt->val != rt->val)
            {
                return false;
            }
            ts.push(lt->left);
            ts.push(rt->right);
            ts.push(lt->right);
            ts.push(rt->left);
        }
        return true;
    }
    //迭代法使用栈来实现的话，只需要将上面的队列改为栈就可以了，
    //其余的保持不变
};
// @lc code=end
