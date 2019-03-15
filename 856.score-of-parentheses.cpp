/*
 * @lc app=leetcode id=856 lang=cpp
 *
 * [856] Score of Parentheses
 *
 * https://leetcode.com/problems/score-of-parentheses/description/
 *
 * algorithms
 * Medium (55.15%)
 * Total Accepted:    15.3K
 * Total Submissions: 27.8K
 * Testcase Example:  '"()"'
 *
 * Given a balanced parentheses string S, compute the score of the string based
 * on the following rule:
 * 
 * 
 * () has score 1
 * AB has score A + B, where A and B are balanced parentheses strings.
 * (A) has score 2 * A, where A is a balanced parentheses string.
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: 1
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "(())"
 * Output: 2
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "()()"
 * Output: 2
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "(()(()))"
 * Output: 6
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * S is a balanced parentheses string, containing only ( and ).
 * 2 <= S.length <= 50
 * 
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int cur(string& s, int index){
        int sum = 0;
        while(index + 1 < s.size() && s[index + 1] == '('){
            sum += cur(s,index+1);
        }
        sum *= 2;
        if(sum == 0)
            sum = 1;
        s.erase(s.begin() + index);
        s.erase(s.begin() + index);
        return sum;
    }
    int scoreOfParentheses(string S) {
        int sum = 0;
        while(!S.empty()){
            sum += cur(S,0);
        }
        return sum;
    }
};

