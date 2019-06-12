/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int a = nums[i];
            int indexB = i+1;
            int indexC = nums.size()-1;
            while(indexB < indexC){
                int sum = a + nums[indexB] + nums[indexC];
                if(sum == 0){
                    vector<int> r;
                    r.push_back(a);
                    r.push_back(nums[indexB]);
                    r.push_back(nums[indexC]);
                    result.push_back(r);
                    int c = nums[indexC];
                    while(indexC > i && c == nums[indexC]) --indexC;
                }
                else if(sum < 0){
                    ++indexB;
                }
                else{
                    --indexC;
                }
            }
        }
        return result;
    }
};

