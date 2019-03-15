/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 *
 * https://leetcode.com/problems/majority-element-ii/description/
 *
 * algorithms
 * Medium (31.38%)
 * Total Accepted:    93.9K
 * Total Submissions: 299.2K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an integer array of size n, find all elements that appear more than ⌊
 * n/3 ⌋ times.
 * 
 * Note: The algorithm should run in linear time and in O(1) space.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: [3]
 * 
 * Example 2:
 * 
 * 
 * Input: [1,1,1,3,3,2,2,2]
 * Output: [1,2]
 * 
 */
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> log;
        for(int i = 0; i < nums.size(); i++){
            auto found = log.find(nums[i]);
            if(found != log.end())
                found->second++;
            else
                log[nums[i]] = 1;
        }
        vector<int> result;
        for(auto& pair : log){
            if(pair.second > nums.size() / 3){
                result.push_back(pair.first);
            }
        }
        return result;
    }
};

