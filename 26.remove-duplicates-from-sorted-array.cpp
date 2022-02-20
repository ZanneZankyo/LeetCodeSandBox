/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
 *
 * algorithms
 * Easy (39.81%)
 * Total Accepted:    537.6K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,1,2]'
 *
 * Given a sorted array nums, remove the duplicates in-place such that each
 * element appear only once and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 * 
 * Example 1:
 * 
 * 
 * Given nums = [1,1,2],
 * 
 * Your function should return length = 2, with the first two elements of nums
 * being 1 and 2 respectively.
 * 
 * It doesn't matter what you leave beyond the returned length.
 * 
 * Example 2:
 * 
 * 
 * Given nums = [0,0,1,1,1,2,2,3,3,4],
 * 
 * Your function should return length = 5, with the first five elements of nums
 * being modified to 0, 1, 2, 3, and 4 respectively.
 * 
 * It doesn't matter what values are set beyond the returned length.
 * 
 * 
 * Clarification:
 * 
 * Confused why the returned value is an integer but your answer is an array?
 * 
 * Note that the input array is passed in by reference, which means
 * modification to the input array will be known to the caller as well.
 * 
 * Internally you can think of this:
 * 
 * 
 * // nums is passed in by reference. (i.e., without making a copy)
 * int len = removeDuplicates(nums);
 * 
 * // any modification to nums in your function would be known by the caller.
 * // using the length returned by your function, it prints the first len
 * elements.
 * for (int i = 0; i < len; i++) {
 * print(nums[i]);
 * }
 * 
 */
#if 1 // 22.64% time 93.29% mem
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int maxNum = nums[0];
        int nextIndex = 1;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > maxNum)
            {
                nums[nextIndex] = nums[i];
                maxNum = nums[i];
                ++nextIndex;
            }
        }
        return nextIndex;
    }
};
#endif
#if 0 // 5.01% time 93.29% mem
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i){
            int j = i+1;
            while(j < nums.size() && nums[i] == nums[j])
                nums.erase(nums.begin()+j);
        }
        return nums.size();
    }
};
#endif
#if 0 // 5.01% time 5.95% mem
// since it is a sorted array, don't use this. this is for a unsorted array
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> appearedNums;
        for(int i = 0; i < nums.size(); ++i){
            if(appearedNums.find(nums[i]) != appearedNums.end())
            {
                nums.erase(nums.begin() + i);
                --i;
            }
            else
            {
                appearedNums.emplace(nums[i]);
            }
        }
        return nums.size();
    }
};
#endif
