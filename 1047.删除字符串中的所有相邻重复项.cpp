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
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> sc;
        string res = "";//初始时赋值为空串
        for (int i = 0; i < s.size(); ++i) {
            if (sc.empty()) {
                sc.push(s[i]);
                // cout<<"input "<<s[i]<<endl; 
            } else {
                if (sc.top() == s[i])
                {
                    sc.pop();
                    // cout<<"output "<<s[i]<<endl;
                } else {
                    sc.push(s[i]);
                    // cout<<"input "<<s[i]<<endl;
                }
            }
        }
        if (sc.empty()) {
            return res;
        }
        int i = 0;
        while (!sc.empty()) {
            res += sc.top();//注意这里是+=
            sc.pop();
            ++i;
        }
        // cout<<res<<endl;
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

int main() {
    Solution *s = new Solution();
    s->removeDuplicates("abbaca");
    return 0;
}

