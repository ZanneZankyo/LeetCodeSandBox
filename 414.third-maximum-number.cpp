/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 *
 * https://leetcode.com/problems/third-maximum-number/description/
 *
 * algorithms
 * Easy (28.73%)
 * Total Accepted:    86.7K
 * Total Submissions: 301.5K
 * Testcase Example:  '[3,2,1]'
 *
 * Given a non-empty array of integers, return the third maximum number in this
 * array. If it does not exist, return the maximum number. The time complexity
 * must be in O(n).
 * 
 * Example 1:
 * 
 * Input: [3, 2, 1]
 * 
 * Output: 1
 * 
 * Explanation: The third maximum is 1.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1, 2]
 * 
 * Output: 2
 * 
 * Explanation: The third maximum does not exist, so the maximum (2) is
 * returned instead.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: [2, 2, 3, 1]
 * 
 * Output: 1
 * 
 * Explanation: Note that the third maximum here means the third maximum
 * distinct number.
 * Both numbers with value 2 are both considered as second maximum.
 * 
 * 
 */
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if(nums.empty()){
            return 0x80000000;
        }
        int firstMax = 0x80000000;
        int prevMax = 0x7FFFFFFF;
        for(int k = 0; k < 3; ++k){
            int curMax = 0x80000000;
            int maxIndex = -1;
            for(int i = 0; i < nums.size(); ++i){
                if(curMax <= nums[i] && nums[i] < prevMax){
                    curMax = nums[i];
                    maxIndex = i;
                }
            }
            if(prevMax == 0x7FFFFFFF){
                firstMax = curMax;
            }
            if(maxIndex != -1){
                prevMax = curMax;
            }
            else{
                return firstMax;
            }
        }
        return prevMax;
    }
};

