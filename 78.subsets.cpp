/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (51.34%)
 * Total Accepted:    337.9K
 * Total Submissions: 657.9K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
class Solution {
public:
    void recursive(vector<int>& current, vector<vector<int>>& result, vector<int>& nums, int startIndex){
        result.push_back(current);
        for(int i = startIndex; i < nums.size(); ++i){
            current.push_back(nums[i]);
            recursive(current, result, nums, i+1);
            current.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.reserve(nums.size() * nums.size());
        vector<int> current;
        current.reserve(nums.size());
        recursive(current, result, nums, 0);
        return result;
    }
};

