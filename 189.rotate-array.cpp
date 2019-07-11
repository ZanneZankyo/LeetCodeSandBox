/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 *
 * https://leetcode.com/problems/rotate-array/description/
 *
 * algorithms
 * Easy (29.19%)
 * Total Accepted:    274.1K
 * Total Submissions: 938.3K
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * Given an array, rotate the array to the right by k steps, where k is
 * non-negative.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,4,5,6,7] and k = 3
 * Output: [5,6,7,1,2,3,4]
 * Explanation:
 * rotate 1 steps to the right: [7,1,2,3,4,5,6]
 * rotate 2 steps to the right: [6,7,1,2,3,4,5]
 * rotate 3 steps to the right: [5,6,7,1,2,3,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-1,-100,3,99] and k = 2
 * Output: [3,99,-1,-100]
 * Explanation: 
 * rotate 1 steps to the right: [99,-1,-100,3]
 * rotate 2 steps to the right: [3,99,-1,-100]
 * 
 * 
 * Note:
 * 
 * 
 * Try to come up as many solutions as you can, there are at least 3 different
 * ways to solve this problem.
 * Could you do it in-place with O(1) extra space?
 * 
 */
#if 1 // 89.65% runtime 27.93% space
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() == 1 || k == 0 || k == nums.size())
            return;
        vector<int> result;
        result.reserve(nums.size());
        k %= nums.size();
        int start = (nums.size() - k)%nums.size();
        result.insert(result.end(), nums.begin() + start, nums.end());
        result.insert(result.end(), nums.begin(), nums.begin() + start);

        nums = result;
    }
};
#endif

#if 0 //TLE
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() == 1 || k == 0 || k == nums.size())
            return;
        int time = 0;
        k %= nums.size();
        while(time != k){
            int temp = nums[nums.size()-1];
            for(int i = nums.size()-1; i > 0; --i){
                nums[i] = nums[i-1];
            }
            nums[0] = temp;
            ++time;
        }
    }
};
#endif

#if 0 //36.55% runtime 14.99% space
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() == 1 || k == 0 || k == nums.size())
            return;
        vector<int> result;
        result.reserve(nums.size());
        k %= nums.size();
        int start = (nums.size() - k)%nums.size();
        result.push_back(nums[start]);
        for(int i = (start+1)%nums.size(); i != start; i = (i+1)%nums.size()){
            result.push_back(nums[i]);
        }
        nums = result;
    }
};
#endif

