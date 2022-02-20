/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (71.32%)
 * Likes:    9239
 * Dislikes: 173
 * Total Accepted:    1.1M
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an array nums of distinct integers, return all the possible
 * permutations. You can return the answer in any order.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * Example 2:
 * Input: nums = [0,1]
 * Output: [[0,1],[1,0]]
 * Example 3:
 * Input: nums = [1]
 * Output: [[1]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * All the integers of nums are unique.
 * 
 * 
 */

// @lc code=start
class Solution {

public:
    vector<vector<int>> permute(vector<int>& nums) {
        result.clear();
        result.reserve(factorial(nums.size())); // number of results are !nums.size()
        permutation.clear();
        permutation.reserve(nums.size());
        usedNums.clear();
        usedNums.resize(nums.size(), false);
        numbers = &nums;
        generatePermutation();
        return result;
    }
private:
    int factorial(int num){
        int result = 1;
        while(num > 0){
            result *= num;
            --num;
        }
        return result;
    }
    void generatePermutation(){
        if(permutation.size() >= numbers->size()){
            result.push_back(permutation);
        }
        else{
            for(int i = 0; i < numbers->size(); ++i){
                if(usedNums[i]){
                    continue;
                }
                permutation.push_back(numbers->at(i));
                usedNums[i] = true;
                generatePermutation();
                permutation.pop_back();
                usedNums[i] = false;
            }
        }
    }
private:
    vector<int> *numbers;
    vector<int> permutation;
    vector<bool> usedNums;
    vector<vector<int>> result;
};
// @lc code=end

