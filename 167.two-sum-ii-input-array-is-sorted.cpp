/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 *
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
 *
 * algorithms
 * Easy (49.57%)
 * Total Accepted:    219.8K
 * Total Submissions: 443.4K
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers that is already sorted in ascending order, find
 * two numbers such that they add up to a specific target number.
 * 
 * The function twoSum should return indices of the two numbers such that they
 * add up to the target, where index1 must be less than index2.
 * 
 * Note:
 * 
 * 
 * Your returned answers (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution and you may
 * not use the same element twice.
 * 
 * 
 * Example:
 * 
 * 
 * Input: numbers = [2,7,11,15], target = 9
 * Output: [1,2]
 * Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
 * 
 */
class Solution {
public:

    int findIndex(vector<int>& nums ,int myIndex, int target){
        int near = myIndex + 1;
        int far = nums.size() - 1;
        if(nums[near] == target)
            return near;
        if(nums[far] == target)
            return far;
        int half = (near + far) / 2;
        do{
            int n = nums[half];
            if(n == target){
                return half;
            }
            else if(n < target){
                near = half + 1;
            }
            else{
                far = half;
            }
            half = (near + far) / 2;
        }while(near < far);
        return -1;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        result.reserve(numbers.size());
        if(numbers.size() == 0)
            return result;
        result = vector<int>();
        for(int i = 0; i < numbers.size() - 1; ++i){
            int j = findIndex(numbers,i,target - numbers[i]);
            if(j != -1){
                result.push_back(i + 1);
                result.push_back(j + 1);
                continue;
            }
        }
        return result;
    }
};

