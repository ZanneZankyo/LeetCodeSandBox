/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 *
 * https://leetcode.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (44.40%)
 * Total Accepted:    216.4K
 * Total Submissions: 487.4K
 * Testcase Example:  '19'
 *
 * Write an algorithm to determine if a number is "happy".
 * 
 * A happy number is a number defined by the following process: Starting with
 * any positive integer, replace the number by the sum of the squares of its
 * digits, and repeat the process until the number equals 1 (where it will
 * stay), or it loops endlessly in a cycle which does not include 1. Those
 * numbers for which this process ends in 1 are happy numbers.
 * 
 * Example: 
 * 
 * 
 * Input: 19
 * Output: true
 * Explanation: 
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 * 
 */
class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        while(n!=1){
            int sum = 0;
            while(n>0){
                int mod = n % 10;
                sum += mod * mod;
                n /= 10;
            }
            if(s.find(sum)!=s.end())
                return false;
            s.insert(sum);
            n = sum;
        }
        return true;
    }
};

