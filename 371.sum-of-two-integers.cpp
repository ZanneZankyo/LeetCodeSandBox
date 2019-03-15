/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 *
 * https://leetcode.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Easy (51.16%)
 * Total Accepted:    126.7K
 * Total Submissions: 247.6K
 * Testcase Example:  '1\n2'
 *
 * Calculate the sum of two integers a and b, but you are not allowed to use
 * the operator + and -.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: a = 1, b = 2
 * Output: 3
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: a = -2, b = 3
 * Output: 1
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int getSum(int a, int b) {
        int result = 0;
        int digit = 1;
        bool carry = false;
        for(int i = 0; i < 32; i++){
            if((digit & a) && (digit & b)){
                if(carry){
                    result |= digit;
                }
                else{
                    carry = true;
                }
            }
            else if((digit & a) || (digit & b)){
                if(!carry){
                    result |= digit;
                }
            }
            else{
                if(carry){
                    result |= digit;
                    carry = false;
                }
            }
            digit <<= 1;
        }
        return result;
    }
};

