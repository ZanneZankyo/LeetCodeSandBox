/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (40.52%)
 * Likes:    6312
 * Dislikes: 796
 * Total Accepted:    673K
 * Total Submissions: 1.7M
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given an m x n matrix, return all elements of the matrix in spiral order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 10
 * -100 <= matrix[i][j] <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
    enum Direction{
        Up,
        Down,
        Left,
        Right,
    };
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty() || matrix[0].empty()){
            return result;
        }
        int total = matrix.size() * matrix[0].size();
        result.reserve(total);
        int upBorder = -1, rightBorder = matrix[0].size(), downBorder = matrix.size(), leftBorder = -1;
        Direction dir = Right;
        int i = 0, j = 0;
        while(result.size() < total){
            result.push_back(matrix[i][j]);
            step(i, j, dir);
            if(i <= upBorder){
                ++i;
                dir = Right;
                ++leftBorder;
                step(i, j, dir);
            }
            else if(i >= downBorder){
                --i;
                dir = Left;
                --rightBorder;
                step(i, j, dir);
            }
            else if(j <= leftBorder){
                ++j;
                dir = Up;
                --downBorder;
                step(i, j, dir);
            }
            else if(j >= rightBorder){
                --j;
                dir = Down;
                ++upBorder;
                step(i, j, dir);
            }
        }
        return result;
    }
private:
    void step(int &i, int &j, Direction dir){
        switch(dir){
        case Up:
            --i;
            break;
        case Down:
            ++i;
            break;
        case Left:
            --j;
            break;
        case Right:
            ++j;
            break;
        default:
            break;
        }
    }
};
// @lc code=end

