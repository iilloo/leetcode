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
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> sc;
        for (int i =  0; i < s.size(); ++i) {
            if (s[i] == '(') {
                sc.push(')');
            } else if (s[i] == '[') {
                sc.push(']');
            } else if (s[i] == '{') {
                sc.push('}');
            } else if (s[i] == ' ') {
                continue;
            } else {
                if ((!sc.empty()) && sc.top() == s[i]) {
                    sc.pop();
                } else {
                    return false;
                }
            }
        }
        if (sc.empty()) {
            return true;
        }
        return false;

    }
};
// @lc code=end

