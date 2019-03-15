/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (54.04%)
 * Total Accepted:    231K
 * Total Submissions: 427.4K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given an array nums of n integers where n > 1,  return an array output such
 * that output[i] is equal to the product of all the elements of nums except
 * nums[i].
 * 
 * Example:
 * 
 * 
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 * 
 * 
 * Note: Please solve it without division and in O(n).
 * 
 * Follow up:
 * Could you solve it with constant space complexity? (The output array does
 * not count as extra space for the purpose of space complexity analysis.)
 * 
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> front(size);
        vector<int> back(size);
        front[0] = nums[0];
        back[size - 1] = nums[size - 1];
        for(int i = 1 ; i < size; i ++){
            front[i] = front[i - 1] * nums[i];
            back[size - 1 - i] = back[size - i] * nums[size - 1 - i];
        }
        vector<int> result(size);
        for(int i = 0 ; i < size; i++){
            int val = 1;
            if(i > 0)
                val *= front[i - 1];
            if(i + 1 < size)
                val *= back[i + 1];
            result[i] = val;
        }
        return result;
    }
};

