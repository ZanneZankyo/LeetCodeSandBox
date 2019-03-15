/*
Given an input string , reverse the string word by word. 

Example:

Input:  ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
Note: 

A word is defined as a sequence of non-space characters.
The input string does not contain leading or trailing spaces.
The words are always separated by a single space.
Follow up: Could you do it in-place without allocating extra space?
*/
class Solution {
public:
    void reverseWords(vector<char>& s) {
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