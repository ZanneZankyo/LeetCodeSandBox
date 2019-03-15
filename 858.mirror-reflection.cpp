/*
 * @lc app=leetcode id=858 lang=cpp
 *
 * [858] Mirror Reflection
 *
 * https://leetcode.com/problems/mirror-reflection/description/
 *
 * algorithms
 * Medium (51.44%)
 * Total Accepted:    5.9K
 * Total Submissions: 11.5K
 * Testcase Example:  '2\n1'
 *
 * There is a special square room with mirrors on each of the four walls.
 * Except for the southwest corner, there are receptors on each of the
 * remaining corners, numbered 0, 1, and 2.
 * 
 * The square room has walls of length p, and a laser ray from the southwest
 * corner first meets the east wall at a distance q from the 0th receptor.
 * 
 * Return the number of the receptor that the ray meets first.  (It is
 * guaranteed that the ray will meet a receptor eventually.)
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: p = 2, q = 1
 * Output: 2
 * Explanation: The ray meets receptor 2 the first time it gets reflected back
 * to the left wall.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= p <= 1000
 * 0 <= q <= p
 * 
 * 
 * 
 */
class Solution {
public:
    int mirrorReflection(int p, int q) {
        int range = p;
        while(range % q != 0){
            range += p;
        }
        int dp = range / p;
        int dq = range / q;
        if(dp % 2 == 0)
            return 0;
        else{
            if(dq % 2 == 0)
                return 2;
            else
                return 1;
        }
    }
};

