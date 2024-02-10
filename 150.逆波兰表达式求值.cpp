#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <list>
#include <string>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> sc;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                if (tokens[i] == "+") {
                    long long tmp_2 = sc.top();
                    sc.pop(); 
                    long long tmp_1 = sc.top();
                    sc.pop();
                    sc.push(tmp_1 + tmp_2);
                } else if (tokens[i] == "-") {
                    long long tmp_2 = sc.top();
                    sc.pop(); 
                    long long tmp_1 = sc.top();
                    sc.pop();
                    sc.push(tmp_1 - tmp_2);
                } else if (tokens[i] == "*") {
                    long long tmp_2 = sc.top();
                    sc.pop(); 
                    long long tmp_1 = sc.top();
                    sc.pop();
                    sc.push(tmp_1 * tmp_2);
                } else {
                    long long tmp_2 = sc.top();
                    sc.pop(); 
                    long long tmp_1 = sc.top();
                    sc.pop();
                    sc.push(tmp_1 / tmp_2);
                }
            } else {
                sc.push(stoll(tokens[i]));
            }
        }
        return sc.top();
    }
};
// @lc code=end

