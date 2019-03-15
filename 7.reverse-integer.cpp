/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.19%)
 * Total Accepted:    628K
 * Total Submissions: 2.5M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 0 when the reversed
 * integer overflows.
 * 
 */
class Solution {
public:
    bool isAdditionOverflow_Int(int source, int additive)
    {
        static const int overFlow = pow(2,31) - 1;
        return overFlow - source < additive;
    }
    int reverse(int x) {
        vector<int>digits;
        digits.reserve(32);
        bool positive = x > 0;
        x = positive ? x : x * -1;
        while(x > 0)
        {
            int digit = x % 10;
            digits.push_back(digit);
            x /= 10;
        }
        int result = 0;
        for(int i = 0; i<digits.size();i++)
        {
            int j = digits.size() - i - 1;
            int additive = digits[i] * pow(10,j);
            if(isAdditionOverflow_Int(result,additive))
                return 0;
            result += additive;
        }
        result = positive ? result : -result;
        return result;
    }
};
