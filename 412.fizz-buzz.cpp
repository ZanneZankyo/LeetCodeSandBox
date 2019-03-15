/*
 * @lc app=leetcode id=412 lang=cpp
 *
 * [412] Fizz Buzz
 *
 * https://leetcode.com/problems/fizz-buzz/description/
 *
 * algorithms
 * Easy (58.96%)
 * Total Accepted:    186K
 * Total Submissions: 315.5K
 * Testcase Example:  '1'
 *
 * Write a program that outputs the string representation of numbers from 1 to
 * n.
 * 
 * But for multiples of three it should output “Fizz” instead of the number and
 * for the multiples of five output “Buzz”. For numbers which are multiples of
 * both three and five output “FizzBuzz”.
 * 
 * Example:
 * 
 * n = 15,
 * 
 * Return:
 * [
 * ⁠   "1",
 * ⁠   "2",
 * ⁠   "Fizz",
 * ⁠   "4",
 * ⁠   "Buzz",
 * ⁠   "Fizz",
 * ⁠   "7",
 * ⁠   "8",
 * ⁠   "Fizz",
 * ⁠   "Buzz",
 * ⁠   "11",
 * ⁠   "Fizz",
 * ⁠   "13",
 * ⁠   "14",
 * ⁠   "FizzBuzz"
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        for(int i = 1; i <= n; i++){
            string str;
            if(i % 3 == 0 && i % 5 == 0)
                str = "FizzBuzz";
            else if(i % 3 == 0)
                str = "Fizz";
            else if(i % 5 == 0)
                str = "Buzz";
            else
                str = to_string(i);
            result.push_back(str);
        }
        return result;
    }
};

