/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (32.68%)
 * Total Accepted:    377.4K
 * Total Submissions: 1.2M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * 
 */
#if 1
class Solution {
private:
    int BinarySearchRotationPoint(vector<int> const &nums){
        int start = 0, end = nums.size() - 1;
        if(nums[start] < nums[end]){
            return 0;
        }
        while(start + 1 < end){
            int middle = (start + end) * 0.5;
            if(nums[middle] > nums[end]){
                start = middle;
            }
            else if(nums[middle] < nums[end]){
                end = middle;
            }
        }
        return end;
    }
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()){
            return -1;
        }
        if(nums.size() == 1){
            return nums[0] == target ? 0 : -1;
        }
        int rotationPoint = BinarySearchRotationPoint(nums);
        int start, end;
        if(rotationPoint == 0){
            start = 0;
            end = nums.size() - 1;
        }
        else if(target >= nums[0]){
            start = 0;
            end = rotationPoint - 1;
        }
        else{
            start = rotationPoint;
            end = nums.size() - 1;
        }
        do{
            int middle = (start + end) * 0.5;
            if(nums[middle] > target){
                end = middle;
            }
            else if(nums[middle] < target){
                start = middle;
            }
            else{
                return middle;
            }
            if(nums[start] == target){
                return start;
            }
            if(nums[end] == target){
                return end;
            }
        }
        while(start + 1 < end);
        return -1;
    }
};
#endif
#if 0
class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                return i;
            }
        }
        return -1;
    }
};
#endif

