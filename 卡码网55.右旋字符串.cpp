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
int main()
{
    int n = 0;
    string str = "";
    cin >> n;
    cin >> str;
    reverse(str.begin(), str.end());
    reverse(str.begin(), str.begin() + n);
    reverse(str.begin() + n, str.end());
    cout << str;
}