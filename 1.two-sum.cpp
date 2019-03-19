/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (42.28%)
 * Total Accepted:    1.5M
 * Total Submissions: 3.7M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an numsay of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * Example:
 * 
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 * 
 * 
 */
class Solution {

    struct mySet{
        int index;
        int value;
        bool operator < (const mySet& comp){
            return value < comp.value;
        }
    };

public:

    int findIndex(vector<mySet>& sets ,int myIndex, int target){
        int near = myIndex + 1;
        int far = sets.size() - 1;
        if(sets[near].value == target)
            return near;
        if(sets[far].value == target)
            return far;
        int half = (near + far) / 2;
        do{
            int n = sets[half].value;
            if(n == target){
                return half;
            }
            else if(n < target){
                near = half + 1;
            }
            else{
                far = half;
            }
            half = (near + far) / 2;
        }while(near < far);
        return -1;
    }
#define TIME 0
#define SPACE 1
#define METHOD TIME

#if METHOD == TIME
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        result.reserve(nums.size());
        if(nums.size() == 0)
            return result;
        vector<mySet> sets;
        sets.resize(nums.size());
        for(int i = 0; i < nums.size(); ++i){
            sets[i].index = i;
            sets[i].value = nums[i];
        }
        sort(sets.begin(), sets.end());
        result = vector<int>();
        for(int i = 0; i < sets.size() - 1; ++i){
            int j = findIndex(sets,i,target - sets[i].value);
            if(j != -1){
                result.push_back(sets[i].index);
                result.push_back(sets[j].index);
                break;
            }
        }
        return result;
    }
#elif METHOD == SPACE
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i = 0; i < nums.size(); ++i)
            for(int j = i+1; j < nums.size(); ++j)
                if(nums[i] + nums[j] == target )
                {
                    result.push_back(i);
                    result.push_back(j);
                    continue;
                }
        return result;
    }
#endif
};

