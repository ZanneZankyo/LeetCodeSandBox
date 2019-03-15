/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (40.76%)
 * Total Accepted:    360.1K
 * Total Submissions: 883.5K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 * 
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * 
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result = digits;
        
        result[result.size() - 1] ++;
        if(result[result.size() - 1] >= 10){
            result[result.size() - 1] -= 10;
            bool carry = true;
            int i = result.size() - 2;
            while(carry && i >= 0){
                result[i] ++;
                if(result[i] < 10){
                    carry = false;
                    break;
                }
                else
                    result[i] -= 10;
                i--;
            }
            if(carry){
                result.insert(result.begin(), 1);
            }
        }
        
        return result;
    }
};

