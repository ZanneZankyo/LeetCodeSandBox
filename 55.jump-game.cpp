/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (31.42%)
 * Total Accepted:    240.7K
 * Total Submissions: 766.2K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Determine if you are able to reach the last index.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
 * index.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its
 * maximum
 * jump length is 0, which makes it impossible to reach the last index.
 * 
 * 
 */
class Solution {
public:
    bool recursion(vector<int>& nums, int start, int jumpLength){
        if(start == nums.size() - 1)
            return true;
        while(jumpLength > 0){
            if(start + jumpLength < nums.size() && recursion(nums,start + jumpLength,nums[start + jumpLength])){
                return true;
            }
            else
                jumpLength--;
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        //return recursion(nums,0,nums[0]);
        if(nums.size() <= 1)
            return true;
        bool result = true;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] == 0){
                bool canPass = false;
                for(int j = i - 1; j >= 0; j--){
                    if(nums[j] > i - j || (i == nums.size() - 1 && nums[j] >= i - j)){
                        canPass = true;
                        break;
                    }
                }
                if(!canPass){
                    return false;
                }
            }
        }
        return true;
    }
};

