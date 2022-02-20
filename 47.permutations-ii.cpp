/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (53.34%)
 * Likes:    4483
 * Dislikes: 90
 * Total Accepted:    571.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers, nums, that might contain duplicates, return
 * all possible unique permutations in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,2]
 * Output:
 * [[1,1,2],
 * ⁠[1,2,1],
 * ⁠[2,1,1]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 8
 * -10 <= nums[i] <= 10
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        numbers = &nums;
        numGroups.clear();
        result.clear();
        result.reserve(factorial(nums.size())); // number of results are !nums.size()
        permutation.clear();
        permutation.reserve(nums.size());
        groupNums();
        generatePermutation();
        return result;
    }
private:
    void groupNums(){
        for(int num : *numbers){
            numGroups[num] = 0;
        }
        for(int num : *numbers){
            numGroups[num] += 1;
        }
    }
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
            for(auto it = numGroups.begin(); it != numGroups.end(); ++it){
                if(it->second <= 0){
                    continue;
                }
                permutation.push_back(it->first);
                --it->second;
                generatePermutation();
                permutation.pop_back();
                ++it->second;
            }
        }
    }
private:
    vector<int> *numbers;
    vector<int> permutation;
    map<int, int> numGroups; // first: the number , second: num of numbers
    vector<vector<int>> result;
};
// @lc code=end

