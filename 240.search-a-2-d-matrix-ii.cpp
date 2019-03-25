/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 *
 * https://leetcode.com/problems/search-a-2d-matrix-ii/description/
 *
 * algorithms
 * Medium (40.35%)
 * Total Accepted:    166.1K
 * Total Submissions: 411.1K
 * Testcase Example:  '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n5'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * 
 * 
 * Example:
 * 
 * Consider the following matrix:
 * 
 * 
 * [
 * ⁠ [1,   4,  7, 11, 15],
 * ⁠ [2,   5,  8, 12, 19],
 * ⁠ [3,   6,  9, 16, 22],
 * ⁠ [10, 13, 14, 17, 24],
 * ⁠ [18, 21, 23, 26, 30]
 * ]
 * 
 * 
 * Given target = 5, return true.
 * 
 * Given target = 20, return false.
 * 
 */
class Solution {
public:
    int binarySearch(vector<int>& nums ,int startIndex, int endIndex, int target){
        int near = startIndex;
        int far = endIndex;
        if(nums[near] == target)
            return near;
        if(nums[far] == target)
            return far;
        int half = (near + far) / 2;
        do{
            int n = nums[half];
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

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        int startRow = 0;
        int endRow = 0;
        for(int i = 0; i < matrix.size(); ++i){
            if(matrix[i][0] <= target && target <= matrix[i][matrix[i].size()-1]){
                if(binarySearch(matrix[i], 0, matrix[i].size() - 1, target) != -1){
                    return true;
                }
            }
        }
        return false;
    }
};

