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

/*

Test case:

"abcabcbb"
""
"pwwkew"
"bbbbb"
"abcbaeb"
"abcdefg"

*/

#define TIME 1
#define SPACE 2
#define METHOD TIME

#if METHOD == TIME

class Solution {
public:

    bool appearedCharacters[128];

    int lengthOfLongestSubstring(string s) {

        if(s.empty()) return 0;
        
        memset(appearedCharacters, 0, sizeof(bool)*128);
        
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
            
            memset(appearedCharacters, 0, sizeof(bool)*128);
            
            while(fromIndex < s.size() && s[fromIndex] != s[toIndex]) ++fromIndex;
            ++fromIndex;
        }
        return max;

    }
};
#endif

#if METHOD == SPACE

#endif

