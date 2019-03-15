/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (26.74%)
 * Total Accepted:    494K
 * Total Submissions: 1.8M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */
class Solution {
public:
    bool isPalindrome2(const string& s)
    {
        if(s.size() == 1)
            return true;
        int i,j;
        if((s.size() & 1) == 0)
        {
            i = s.size() / 2 - 1;
            j = s.size() / 2;
        }
        else
        {
            i = j = s.size() / 2;
        }
        
        for(; i>=0 && j<s.size(); i--,j++)
            if(s[i]!=s[j])
                break;
        return i == -1 && j == s.size();
    }
    bool isPalindrome(const string& s, int from, int to)
    {
        int size = to - from + 1;
        if(size == 1)
            return true;
        int i,j;
        if((size & 1) == 0)
        {
            i = size / 2 - 1 + from;
            j = size / 2 + from;
        }
        else
        {
            i = j = size / 2 + from;
        }
        
        for(; i>=from && j<=to; i--,j++)
            if(s[i]!=s[j])
                break;
        return i == from-1 && j == to+1;
    }
    string longestPalindrome(string s) {
        int from = 0;
        int to = 0;
        string result;
        int maxLen = 0;
        while(from < s.size())
        {
            to = s.size() - 1;
            while(to >= from)
            {
                int len = to - from + 1;
                if(len > maxLen)
                {
                    if(isPalindrome(s,from,to))
                    {
                        maxLen = len;
                        result = s.substr(from, len);
                        break;
                    }
                }
                to--;
            }
            from++;
        }
        return result;
    }
};

