/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (38.12%)
 * Total Accepted:    280.6K
 * Total Submissions: 736K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 */
class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        bool carry = false;
        int i = a.size() - 1;
        int j = b.size() - 1;
        while(i>=0 || j>=0){
            int x = i >= 0 ? a[i] - '0' : 0;
            int y = j >= 0 ? b[j] - '0' : 0;
            char newChar = '0';
            if(x && y){
                if(carry){
                    newChar = '1';
                }
                else{
                    carry = true;
                }
            }
            else if((!x && y) || (x && !y)){
                if(!carry){
                    newChar = '1';
                }
            }
            else{
                if(carry){
                    newChar = '1';
                    carry = false;
                }
            }
            result.insert(result.begin(), newChar);
            i--;
            j--;
        }
        if(carry){
            result.insert(result.begin(), '1');
        }
        return result;
    }
};
