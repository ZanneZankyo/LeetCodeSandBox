/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (28.17%)
 * Likes:    7566
 * Dislikes: 1086
 * Total Accepted:    644.9K
 * Total Submissions: 2.3M
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string s and a pattern p, implement regular expression
 * matching with support for '.' and '*' where:
 * 
 * 
 * '.' Matches any single character.​​​​
 * '*' Matches zero or more of the preceding element.
 * 
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "aa", p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aa", p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the preceding element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "ab", p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 20
 * 1 <= p.length <= 30
 * s contains only lowercase English letters.
 * p contains only lowercase English letters, '.', and '*'.
 * It is guaranteed for each appearance of the character '*', there will be a
 * previous valid character to match.
 * 
 * 
 */

// @lc code=start
/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start

#if 1
class Solution {
public:
    bool isMatch(string s, string p) 
    {
        if(p.empty())
            return s.empty();
        bool matchFirstChar = !s.empty() && (s[0] == p[0] || p[0] == '.');
        if(p.size() >= 2 && p[1] == '*')
        {
            return (matchFirstChar && !s.empty() && isMatch(s.substr(1), p)) || (isMatch(s, p.substr(2)));
        }
        else
        {
            return matchFirstChar && !s.empty() && isMatch(s.substr(1), p.substr(1));
        }
    }
};
#endif

#if 0 // first try: All accepted but time limit excceeded
class Solution {
public:
    bool isMatch(string s, string p) {
        int sIndex = 0, pIndex = 0;
        while(sIndex < s.size() && pIndex < p.size())
        {
            bool matchAnyChar = p[pIndex] == '.';
            bool matchAnyLength = pIndex + 1 < p.size() && p[pIndex + 1] == '*';
            bool hasMatchedAnyLength = true;

            if(matchAnyLength)
            {
                if(pIndex + 2 < p.size())
                {
                    if(matchAnyChar)
                    {
                        int newSIndex = sIndex;
                        while(newSIndex < s.size())
                        {
                            // recursive:
                            if(isMatch(string(s.begin()+newSIndex, s.end()), string(p.begin()+pIndex+2,p.end())))
                            {
                                return true;
                            }
                            ++newSIndex;
                        }
                        hasMatchedAnyLength = true;
                        sIndex = newSIndex;
                    }
                    else
                    {
                        int newSIndex = sIndex;
                        bool sameLetter = true;
                        while(newSIndex < s.size() && sameLetter)
                        {
                            // recursive:
                            if(isMatch(string(s.begin()+newSIndex, s.end()), string(p.begin()+pIndex+2,p.end())))
                            {
                                return true;
                            }
                            sameLetter = s[newSIndex] == p[pIndex];
                            ++newSIndex;
                        }                    
                        hasMatchedAnyLength = s[sIndex] == p[pIndex];
                    }
                }
                else
                {
                    while(sIndex < s.size() && (s[sIndex] == p[pIndex] || matchAnyChar))
                    {
                        ++sIndex;
                    }
                    --sIndex;
                }
            }
            else if(!matchAnyChar && s[sIndex] != p[pIndex])
            {
                return false;
            }
            if(hasMatchedAnyLength)
                ++sIndex;
            ++pIndex;
            if(matchAnyLength)
                ++pIndex;
        }
        while(sIndex >= s.size() && pIndex < p.size())
        {
            if(pIndex + 1 >= p.size() || p[pIndex + 1] != '*')
            {
                return false;
            }
            pIndex += 2;
        }
        return sIndex >= s.size() && pIndex >= p.size();
    }
};
#endif
/*
"aaa"
"a.*.*a"

"aacccabaaba"
"a.*.*aba"

"mississippi"
"mis*is*p*."

"a"
"ab*"

"aabcbcbcaccbcaabc"
".*a*aa*.*b*.c*.*a*"

"abcaaaaaaabaabcabac"
".*ab.a.*a*a*.*b*b*"

"bcccccbaccccacaa"
".*bb*c*a*b*.*b*b*c*"
*/

// @lc code=end

