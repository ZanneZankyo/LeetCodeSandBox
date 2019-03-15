/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (40.59%)
 * Total Accepted:    354.6K
 * Total Submissions: 873.7K
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */
class Solution {
public:
    void combination(vector<string>& result, string& str, string& digits, int index){
        if(index >= digits.size())
        {
            if(!str.empty())
                result.push_back(str);
            return;
        }
        char c = digits[index];
        char startChar = 0;
        char endChar = 0;
        switch(c)
        {
            case '2':{
                startChar = 'a';
                endChar = 'c';
                break;
            }
            case '3':{
                startChar = 'd';
                endChar = 'f';
                break;
            }
            case '4':{
                startChar = 'g';
                endChar = 'i';
                break;
            }
            case '5':{
                startChar = 'j';
                endChar = 'l';
                break;
            }
            case '6':{
                startChar = 'm';
                endChar = 'o';
                break;
            }
            case '7':{
                startChar = 'p';
                endChar = 's';
                break;
            }
            case '8':{
                startChar = 't';
                endChar = 'v';
                break;
            }
            case '9':{
                startChar = 'w';
                endChar = 'z';
                break;
            }
        }
        for(char n = startChar; n <= endChar; n++)
        {
            str.push_back(n);
            combination(result, str, digits, index + 1);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string str;
        str.reserve(digits.size());
        combination(result, str, digits, 0);
        return result;
    }
};

