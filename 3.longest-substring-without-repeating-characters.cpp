/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.03%)
 * Total Accepted:    831.5K
 * Total Submissions: 3M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<bool> appearedCharacters;
        appearedCharacters.resize(128,false);
        
        int max = 0;
        int fromIndex = 0;
        int toIndex = 0;
        while(fromIndex < s.size())
        {
            for(toIndex = fromIndex; toIndex < s.size(); toIndex++ )
            {
                int tableIndex = s[toIndex];
                if(appearedCharacters[tableIndex])
                    break;
                else
                    appearedCharacters[tableIndex] = true;
            }
            int length = toIndex - fromIndex;
            max = (length > max) ? length : max;
            
            for(int i = fromIndex; i <= toIndex; i++)
            {
                int tableIndex = s[i];
                appearedCharacters[tableIndex] = false;
            }
                
            
            fromIndex++;
        }
        return max;
    }
};

