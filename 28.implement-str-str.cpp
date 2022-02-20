/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (31.36%)
 * Total Accepted:    390.7K
 * Total Submissions: 1.2M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */
#if 1 
// https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
class Solution {
private:
    void KMTPreProcess(vector<int> & outLps, string const & needle){
        int longestPrefixSurfix = 0;
        outLps.resize(needle.size(), 0);
        for(int i = 1; i < needle.size();){
            if(needle[i] == needle[longestPrefixSurfix]){
                ++longestPrefixSurfix;
                outLps[i] = longestPrefixSurfix;
                ++i;
            }
            else if(longestPrefixSurfix){
                longestPrefixSurfix = outLps[longestPrefixSurfix - 1];
            }
            else{
                outLps[i] = 0;
                ++i;
            }
        }
    }
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        if(haystack.empty())
            return -1;
        if(haystack.size() < needle.size())
            return -1;
        int i,j;
        bool match;
        vector<int> lps;
        KMTPreProcess(lps, needle);
        for(i = 0, j = 0; i < haystack.size();){
            if(haystack[i] == needle[j]){
                ++j;
                ++i;
            }
            if(j == needle.size()){
                return i - j;
            }
            if(i < haystack.size() && haystack[i] != needle[j]){
                j ? j = lps[j-1] : ++i;
            }
        }
        return -1;
    }
};
#endif
#if 0 // brute force time limit excceeded
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        if(haystack.empty())
            return -1;
        if(haystack.size() < needle.size())
            return -1;
        int i,j;
        bool match;
        for(i = 0; i < haystack.size() - needle.size() + 1; ++i){
            match = true;
            for(j = 0; j < needle.size(); ++j){
                if(haystack[i + j] != needle[j]){
                    match = false;
                    break;
                }
            }
            if(match)
                return i;
        }
        return -1;
    }
};
#endif

