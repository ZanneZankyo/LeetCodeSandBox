/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (53.98%)
 * Likes:    9035
 * Dislikes: 395
 * Total Accepted:    947.1K
 * Total Submissions: 1.7M
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * Given an array nums with n objects colored red, white, or blue, sort them
 * in-place so that objects of the same color are adjacent, with the colors in
 * the order red, white, and blue.
 * 
 * We will use the integers 0, 1, and 2 to represent the color red, white, and
 * blue, respectively.
 * 
 * You must solve this problem without using the library's sort function.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,0,1]
 * Output: [0,1,2]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 1 <= n <= 300
 * nums[i] is either 0, 1, or 2.
 * 
 * 
 * 
 * Follow up: Could you come up with a one-pass algorithm using only constant
 * extra space?
 * 
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start0 = 0, start1 = 0, start2 = 0;
        for(int i = 0; i < nums.size(); ++i){
            int insertPoint = -1;
            int color = nums[i];
            switch(color){
            case 0:
                insertPoint = start0;
                ++start0;
                break;
            case 1:
                insertPoint = start0+start1;
                ++start1;
                break;
            case 2:
                insertPoint = start0+start1+start2;
                ++start2;
                break;
            }
            nums.erase(nums.begin()+i);
            nums.insert(nums.begin()+insertPoint, color);
        }
    }
};
// @lc code=end

