/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (51.20%)
 * Total Accepted:    312.8K
 * Total Submissions: 609.9K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t , write a function to determine if t is an anagram
 * of s.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * 
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 * 
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        char mapS[26];
        char mapT[26];
        memset(mapS, 0, sizeof(mapS));
        memset(mapT, 0, sizeof(mapT));
        for(char c : s){
            mapS[c - 'a']++;
        }
        for(char c : t){
            mapT[c - 'a']++;
        }
        
        for(int i = 0 ; i < 26; ++i){
            if(mapS[i] != mapT[i]){
                return false;
            }
        }
        return true;
    }
};

