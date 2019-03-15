/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 *
 * https://leetcode.com/problems/single-number-ii/description/
 *
 * algorithms
 * Medium (45.26%)
 * Total Accepted:    159.3K
 * Total Submissions: 351.9K
 * Testcase Example:  '[2,2,3,2]'
 *
 * Given a non-empty array of integers, every element appears three times
 * except for one, which appears exactly once. Find that single one.
 * 
 * Note:
 * 
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 * Example 1:
 * 
 * 
 * Input: [2,2,3,2]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [0,1,0,1,0,1,99]
 * Output: 99
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
                found->second++;
                if(found->second == 3){
                    m.erase(found);
                }
            }
        }
        for(auto& pair : m){
            if(pair.second == 1)
                return pair.first;
        }
        return 0;
    }
};

