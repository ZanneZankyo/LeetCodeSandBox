/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (38.00%)
 * Likes:    13241
 * Dislikes: 463
 * Total Accepted:    1.1M
 * Total Submissions: 2.8M
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', return the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = ""
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 3 * 10^4
 * s[i] is '(', or ')'.
 * 
 * 
 */

// @lc code=start
#include <stack>
#include <string>
#include <vector>
#define MEMORY 0
#define SPEED 1
#define METHOD MEMORY
using namespace std;
class Solution {
public:
#if METHOD == MEMORY // 90% mem
    int longestValidParentheses(string s) {
        bits.resize(s.size(), false);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' && !bits[i]) {
                int j = i + 1;
                while (j < s.size() && bits[j]) ++j;
                if (s[j] == ')') {
                    bits[i] = true;
                    bits[j] = true;
                    while (i >= 0 && bits[i]) --i;
                    --i;
                    if (i < -1) {
                        i = -1;
                    }
                }
            }
        }
        int len = 0;
        int maxLen = 0;
        for (int i = 0; i < bits.size(); ++i) {
            if (bits[i]) {
                ++len;
            }
            else {
                maxLen = max(maxLen, len);
                len = 0;
            }
        }
        maxLen = max(maxLen, len);
        return maxLen;
    }
private:
    vector<bool> bits;
#else
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        int prevLen = 0;
        int len = 0;
        int clen = 0;
        for (int i = 0; i < s.size(); ++i) { 
            if (s[i] == '(') {
                ++len;
                ++clen;
            }
            else {
                --clen;
                if (clen >= 0 && len > 0) {
                    ++len;
                }
            }
            if (clen <= 0) {
                if (len > 0) {
                    len += prevLen;
                    maxLen = max(maxLen, len);
                    prevLen = len;
                    len = 0;
                }
                else {
                    prevLen = 0;
                }
                clen = 0;
            }
        }
        if (len > 0) {
            //len += prevLen - clen;
            len -= clen;
            maxLen = max(maxLen, len);
            prevLen = len;
            len = 0;
            clen = 0;
        }
        return maxLen;
    }
#endif
};
#if 0
#include <iostream>
void main() {
    string s = "(()())";//"(()(((()";
    Solution slt;
    cout << slt.longestValidParentheses(s) << endl;
}
#endif
// @lc code=end

