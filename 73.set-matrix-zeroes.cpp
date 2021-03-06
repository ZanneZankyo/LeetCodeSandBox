/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (39.10%)
 * Total Accepted:    194K
 * Total Submissions: 496.1K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to
 * 0. Do it in-place.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * [
 * [1,1,1],
 * [1,0,1],
 * [1,1,1]
 * ]
 * Output: 
 * [
 * [1,0,1],
 * [0,0,0],
 * [1,0,1]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 * Output: 
 * [
 * [0,0,0,0],
 * [0,4,5,0],
 * [0,3,1,0]
 * ]
 * 
 * 
 * Follow up:
 * 
 * 
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best
 * solution.
 * Could you devise a constant space solution?
 * 
 * 
 */

struct MyPoint {
    int x;
    int y;
    MyPoint(int j, int i): x(j), y(i) {}
};

class Solution {
public:
    
    void setZeroes(vector<vector<int>>& matrix) {
        vector<MyPoint> points;
        for(int i = 0 ; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[0].size(); ++j){
                if(matrix[i][j] == 0){
                    points.emplace_back(j, i);
                }
            }
        }
        for(MyPoint const &p : points){
            for(int i = 0 ; i < matrix.size(); ++i){
                matrix[i][p.x] = 0;
            }
            for(int j = 0 ; j < matrix[0].size(); ++j){
                matrix[p.y][j] = 0;
            }
        }
    }
};

