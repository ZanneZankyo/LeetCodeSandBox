/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (46.92%)
 * Likes:    20009
 * Dislikes: 849
 * Total Accepted:    2.1M
 * Total Submissions: 4.4M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given two strings s and t of lengths m and n respectively, return the
 * minimum window substring of s such that every character in t (including
 * duplicates) is included in the window. If there is no such substring, return
 * the empty string "".
 * 
 * The testcases will be generated such that the answer is unique.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "ADOBECODEBANC", t = "ABC"
 * Output: "BANC"
 * Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C'
 * from string t.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "a", t = "a"
 * Output: "a"
 * Explanation: The entire string s is the minimum window.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "a", t = "aa"
 * Output: ""
 * Explanation: Both 'a's from t must be included in the window.
 * Since the largest window of s only has one 'a', return empty string.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == s.length
 * n == t.length
 * 1 <= m, n <= 10^5
 * s and t consist of uppercase and lowercase English letters.
 * 
 * 
 * 
 * Follow up: Could you find an algorithm that runs in O(m + n) time?
 * 
 */

// @lc code=start
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        r.clear();
        if (t.empty()) {
            return r;
        }
        if (t.size() == 1) {
            for (char c : s) {
                if (c == t[0]){
                    return t;
                }
            }
            return r;
        }
        m.clear();
        for (char c : t) {
            auto found = m.find(c);
            if (found != m.end()) {
                ++(found->second);
            }
            else {
                m.insert({c,1});
            }
        }
        int minLen = 0;
        int remain = t.size();
        for (int i = 0, j = 0; i < s.size(); ++i) {
            auto found = m.find(s[i]);
            if (found != m.end()) {
                if (found->second > 0) {
                    --remain;
                }
                --(found->second);
                if (remain == 0) {
                    auto found2 = m.find(s[j]);
                    while((found2 == m.end() || found2->second < 0 ) && j < i) {
                        if (found2 != m.end() && found2->second < 0) {
                            ++(found2->second);
                        }
                        ++j;
                        found2 = m.find(s[j]);
                    }
                    int len = i - j + 1;
                    if (minLen == 0 || len < minLen) {
                        minLen = len;
                        r = s.substr(j, len);
                    }
                    ++(found2->second);
                    ++remain;
                    ++j;
                    found2 = m.find(s[j]);
                    while(found2 == m.end() && j < i) {
                        ++j;
                        found2 = m.find(s[j]);
                    }
                    //++remain;
                    //++(found2->second);
                }
            }
        }
        return r;
    }
private:
    string r;
    unordered_map<char, int> m;
    #if 0 // TLE
public:
    string minWindow(string s, string t) {
        string r;
        if (t.empty()) {
            return r;
        }
        if (t.size() == 1) {
            for (char c : s) {
                if (c == t[0]){
                    return t;
                }
            }
            return r;
        }
        m.clear();
        for (char c : t) {
            auto found = m.find(c);
            if (found != m.end()) {
                ++(found->second);
            }
            else {
                m.insert({c,1});
            }
        }
        for (int i = 0; i < s.size(); ++i) {
            auto found = m.find(s[i]);
            if (found != m.end()) {
                b = m;
                --b[s[i]];
                int remain = t.size() - 1;
                int nextI = i - 1;
                int j = i + 1;
                for (;j < s.size(); ++j) {
                    found = m.find(s[j]);
                    if (found != m.end()) {
                        if (nextI < i) {
                            nextI = j;
                        }
                        if (found->second > 0){
                            --(found->second);
                            --remain;
                            if (remain == 0) {
                                break;
                            }
                        }
                    }
                }
                if (remain == 0) {
                    int len = j + 1 - i;
                    if (r.empty() || len < r.size()) {
                        r = s.substr(i, len);
                    }
                }
                if (nextI > i) {
                    i = nextI - 1;
                }
            }
        }
        return r;
    }
private:
    unordered_map<char, int> m;
    unordered_map<char, int> b;
#endif
};
#if 0
#include <iostream>
void main() {
    Solution s;
    cout << s.minWindow("acbbaca", "aba") << endl;
    cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;
    //cout << s.minWindow("ab", "a") << endl;
}
#endif
// @lc code=end

