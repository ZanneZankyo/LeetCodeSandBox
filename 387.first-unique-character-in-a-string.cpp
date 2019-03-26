/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (49.38%)
 * Total Accepted:    242.1K
 * Total Submissions: 489.5K
 * Testcase Example:  '"leetcode"'
 *
 * 
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 * 
 * Examples:
 * 
 * s = "leetcode"
 * return 0.
 * 
 * s = "loveleetcode",
 * return 2.
 * 
 * 
 * 
 * 
 * Note: You may assume the string contain only lowercase letters.
 * 
 */
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> charPosInSet(26,-1);
        vector<int> charsInStr; 
        for(char c : s){
            int index = c - 'a';
            if(charPosInSet[index] == -1){
                charPosInSet[index] = charsInStr.size();
                charsInStr.push_back(1);
            }
            else{
                ++charsInStr[charPosInSet[index]];
            }
        }
        for(int i = 0; i < s.size(); ++i){
            int index = s[i] - 'a';
            if(charsInStr[charPosInSet[index]] == 1){
                return i;
            }
        }
        return -1;
    }
};

