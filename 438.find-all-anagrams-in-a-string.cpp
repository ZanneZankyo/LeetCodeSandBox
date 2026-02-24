/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (53.27%)
 * Likes:    13147
 * Dislikes: 375
 * Total Accepted:    1.2M
 * Total Submissions: 2.2M
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * Given two strings s and p, return an array of all the start indices of p's
 * anagrams in s. You may return the answer in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "cbaebabacd", p = "abc"
 * Output: [0,6]
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of "abc".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "abab", p = "ab"
 * Output: [0,1,2]
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length, p.length <= 3 * 10^4
 * s and p consist of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (p.size() > s.size() || p.size() == 0) {
            return result;
        }
        char pFeature[26];
        memset(pFeature, 0, sizeof(pFeature));
        for(char c : p) {
            ++pFeature[c - 'a'];
        }
        char sFeature[26];
        memset(sFeature, 0, sizeof(sFeature));
        for (int i = 0; i < p.size(); ++i) {
            char c = s[i];
            ++sFeature[c - 'a'];
        }
        for (int i = 0; i <= s.size() - p.size(); ++i){
            if (i > 0) {
                char c = s[i - 1];
                --sFeature[c - 'a'];
                c = s[i + p.size() - 1];
                ++sFeature[c - 'a'];
            }
            if (memcmp(pFeature, sFeature, sizeof(pFeature)) == 0) {
                result.emplace_back(i);
            }
        }
        return result;
    }
#if 0
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        vector<bool> visited(p.size(), false);
        for (int i = 0; i < s.size() && i + p.size() <= s.size(); ++i) {
            fill(visited.begin(), visited.end(), false);
            bool hitAnagram = true;
            for (int j = i; j < s.size() && j - i < p.size(); ++j) {
                bool hit = false;
                for (int k = 0; k < visited.size(); ++k) {
                    if (s[j] == p[k] && !visited[k]) {
                        visited[k] = true;
                        hit = true;
                        break;
                    }
                }
                if (!hit) {
                    hitAnagram = false;
                    break;
                }
            }
            if (hitAnagram) {
                result.emplace_back(i);
            }
        }
        return result;
    }
#endif
};
// @lc code=end

