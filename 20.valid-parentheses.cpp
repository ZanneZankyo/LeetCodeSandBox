/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (36.00%)
 * Total Accepted:    531.2K
 * Total Submissions: 1.5M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */
class Solution {
public:
    bool recursion(string& s, int i){
        int j = i + 1;
        if(j >= s.size())
            return false;
        if(s[j] == '(' || s[j] == '[' || s[j] == '{'){
            return recursion(s,j);
        }
        if((s[i] == '(' && s[j] == ')') || (s[i] == '[' && s[j] == ']') || (s[i] == '{' && s[j] == '}')){
            s.erase(s.begin() + j);
            s.erase(s.begin() + i);
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        while(!s.empty())
        {
            bool result = recursion(s,0);
            if(!result)
                return false;
        }
        return true;
    }
};

