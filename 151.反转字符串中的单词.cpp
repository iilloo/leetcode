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
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution
{
public:
    void cutSpace(string &s)
    {
        int sp = 0, fp = 0;
        int length = s.size();
        // 解决字符串前面的空格
        while (length > 0 && fp < length && s[fp] == ' ')
        {
            ++fp;
        }
        for (; fp < length; ++fp)
        {
            if (fp - 1 > 0 && s[fp] == ' ' && s[fp - 1] == ' ')
            { // 解决多余的空格
                continue;
            }
            else
            { // 非空格和单词之间的第一个空格被保留
                s[sp] = s[fp];
                ++sp;
            }
        }
        if (sp - 1 > 0 && s[sp - 1] == ' ')
        { // 如果结尾有多个空格的话上边的for循环中的操作
            // 会保留第一个空格
            // 此时sp指向此空格的下一个位置
            // sp - 1表示字符串的去掉空格后的大小
            s.resize(sp - 1);
        }
        else
        { // 结尾没有空格，
            // 此时sp的大小就是去掉多余空格后多余字符串的大小
            s.resize(sp);
        }
    }
    void cutSpacePlus(string &s)
    {
        int sp = 0, fp = 0, length = s.size();
        for (; fp < length; ++fp)
        {
            if (s[fp] != ' ')
            { // fp指向的元素是字符
                if (sp != 0)
                { // 如果此时sp此时指向的不是开头
                    s[sp] = ' ';
                    ++sp;
                }
                // s[sp] = s[fp];
                // ++sp;
                while (fp < length && s[fp] != ' ')
                { // 一旦fp指向了一字符，则指向了一个单词的开始
                    // 所以可以连续的赋值，直到遇到空格
                    s[sp] = s[fp];
                    ++sp, ++fp;
                }
            }
        }
        s.resize(sp);
    }
    string reverseWords(string s)
    {
        cutSpace(s);                 // 去除多余空格
        reverse(s.begin(), s.end()); // 翻转整体
        int left = 0, right = 0, length = s.size();
        for (; right < length; ++right)
        {
            if (s[right] == ' ') // 翻转单词
            {
                reverse(s.begin() + left, s.begin() + right);
                left = right + 1;
            }
        }
        // 翻转最后一个单词
        reverse(s.begin() + left, s.begin() + right);

        return s;
    }
};

// 二番战，双指针法
class Solution_2
{
public:
    void cutSpace(string &s)
    {
        int i = 0, j = 0;
        for (; j < s.size(); ++j)
        {
            if (s[j] != ' ')
            {
                while (j < s.size() && s[j] != ' ')
                {
                    s[i] = s[j];
                    ++j, ++i;
                }
                s[i] = ' ';
                ++i;
            }
        }
        s.resize(i - 1);
    }
    string reverseWords(string s)
    {
        cutSpace(s);                 // 去除多余空格
        reverse(s.begin(), s.end()); // 翻转整体
        int left = 0, right = 0, length = s.size();
        for (; right < length; ++right)
        {
            if (s[right] == ' ') // 翻转单词
            {
                reverse(s.begin() + left, s.begin() + right);
                left = right + 1;
            }
        }
        // 翻转最后一个单词
        reverse(s.begin() + left, s.begin() + right);

        return s;
    }
};
// @lc code=end
