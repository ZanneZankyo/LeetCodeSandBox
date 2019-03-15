/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 *
 * https://leetcode.com/problems/single-number-iii/description/
 *
 * algorithms
 * Medium (56.26%)
 * Total Accepted:    101.5K
 * Total Submissions: 180.4K
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 * Given an array of numbers nums, in which exactly two elements appear only
 * once and all the other elements appear exactly twice. Find the two elements
 * that appear only once.
 * 
 * Example:
 * 
 * 
 * Input:  [1,2,1,3,2,5]
 * Output: [3,5]
 * 
 * Note:
 * 
 * 
 * The order of the result is not important. So in the above example, [5, 3] is
 * also correct.
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant space complexity?
 * 
 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int,int> m;
        for(int i = 0; i <nums.size(); i++){
            auto found = m.find(nums[i]);
            if(found == m.end()){
                m[nums[i]] = 1;
            }
            else{
                found->second++;
                if(found->second == 2){
                    m.erase(found);
                }
            }
        }
        vector<int> result;
        for(auto& pair : m){
            if(pair.second == 1)
                result.push_back(pair.first);
        }
        return result;
    }
};

