/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (16.02%)
 * Total Accepted:    261.9K
 * Total Submissions: 1.6M
 * Testcase Example:  '"the sky is blue"'
 *
 * Given an input string, reverse the string word by word.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "the sky is blue"
 * Output: "blue is sky the"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "  hello world!  "
 * Output: "world! hello"
 * Explanation: Your reversed string should not contain leading or trailing
 * spaces.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "a good   example"
 * Output: "example good a"
 * Explanation: You need to reduce multiple spaces between two words to a
 * single space in the reversed string.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * A word is defined as a sequence of non-space characters.
 * Input string may contain leading or trailing spaces. However, your reversed
 * string should not contain leading or trailing spaces.
 * You need to reduce multiple spaces between two words to a single space in
 * the reversed string.
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * For C programmers, try to solve it in-place in O(1) extra space.
 */
class Solution {
public:
	void reverseWords(string &s) {
		for (int i = 0; i < s.size() / 2; i++) {
			char temp = s[i];
			s[i] = s[s.size() - 1 - i];
			s[s.size() - 1 - i] = temp;
		}
		int startIndex = 0;
		int endIndex = 0;
		while (startIndex < s.size()) {
			while (startIndex < s.size() && s[startIndex] == ' ') {
				startIndex++;
			}
			if (endIndex == 0 && startIndex != 0) {
				s.erase(s.begin(), s.begin() + startIndex);
				startIndex = 0;
			}
			else if (startIndex >= s.size() && startIndex != endIndex) {
				s.erase(s.begin() + endIndex, s.end());
			}
			else if (startIndex - endIndex > 1) {
				s.erase(s.begin() + endIndex + 1, s.begin() + startIndex);
				startIndex = endIndex + 1;
			}

			if (startIndex >= s.size())
				break;
			endIndex = startIndex;
			while (endIndex < s.size() && s[endIndex] != ' ') {
				endIndex++;
			}
			for (int i = 0; i < (endIndex - startIndex) / 2; i++) {
				char temp = s[startIndex + i];
				s[startIndex + i] = s[endIndex - 1 - i];
				s[endIndex - 1 - i] = temp;
			}
			startIndex = endIndex;
		}
	}
};

