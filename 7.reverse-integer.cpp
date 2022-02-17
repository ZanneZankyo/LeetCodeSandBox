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
    bool isAdditionOverflow_Int(unsigned int source, unsigned int additive, bool positive)
    {
        static const unsigned int overFlow = pow(2,31) - 1;
        return positive ? overFlow - source < additive : overFlow + 1 - source < additive;
    }
    int reverse(int x) {
        if(x == -0x80000000)
            return 0;
        vector<int>digits;
        digits.reserve(11);
        bool positive = x > 0;
        x = positive ? x : x * -1;
        while(x > 0)
        {
            int digit = x % 10;
            digits.push_back(digit);
            x /= 10;
        }
        unsigned int result = 0;
        for(int i = 0; i<digits.size();i++)
        {
            int j = digits.size() - 1 - i;
            if(j >= 9 && digits[i] > 2)
                return 0;
            unsigned int additive = digits[i] * pow(10,j);
            if(isAdditionOverflow_Int(result,additive,positive))
                return 0;
            result += additive;
        }
        result = positive ? result : -result;
        return result;
    }
};
