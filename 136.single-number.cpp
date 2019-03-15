/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 *
 * https://leetcode.com/problems/single-number/description/
 *
 * algorithms
 * Easy (59.18%)
 * Total Accepted:    424.9K
 * Total Submissions: 717.9K
 * Testcase Example:  '[2,2,1]'
 *
 * Given a non-empty array of integers, every element appears twice except for
 * one. Find that single one.
 * 
 * Note:
 * 
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 * Example 1:
 * 
 * 
 * Input: [2,2,1]
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,1,2,1,2]
 * Output: 4
 * 
 * 
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> m;
        for(int i = 0; i <nums.size(); i++){
            auto found = m.find(nums[i]);
            if(found == m.end()){
                m[nums[i]] = 1;
            }
            else{
                found->second ++;
            }
        }
        for(auto& pair : m){
            if(pair.second == 1)
                return pair.first;
        }
        return 0;
    }
};

