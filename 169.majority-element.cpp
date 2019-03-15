/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (51.67%)
 * Total Accepted:    354.2K
 * Total Submissions: 685.6K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> log;
        for(int i = 0; i < nums.size(); i++){
            auto found = log.find(nums[i]);
            if(found != log.end())
                found->second++;
            else
                log[nums[i]] = 1;
        }
        int max = 0;
        int result = -1;
        for(auto& pair : log){
            if(pair.second > max){
                max = pair.second;
                result = pair.first;
            }
        }
        return result;
    }
};

