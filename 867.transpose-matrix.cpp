/*
 * @lc app=leetcode id=867 lang=cpp
 *
 * [867] Transpose Matrix
 *
 * https://leetcode.com/problems/transpose-matrix/description/
 *
 * algorithms
 * Easy (63.74%)
 * Total Accepted:    38.8K
 * Total Submissions: 60.9K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix A, return the transpose of A.
 * 
 * The transpose of a matrix is the matrix flipped over it's main diagonal,
 * switching the row and column indices of the matrix.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [[1,4,7],[2,5,8],[3,6,9]]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,2,3],[4,5,6]]
 * Output: [[1,4],[2,5],[3,6]]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 1000
 * 1 <= A[0].length <= 1000
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        if(A.empty())
            return A;
        int row = A.size();
        int col = A[0].size();
        
        vector<vector<int>> B;
        
        B.resize(col);
        for(int i = 0 ; i < col; i++)
        {
            B[i].resize(row);
            for(int j = 0; j < row; j++)
                B[i][j] = A[j][i];
        }
        
        
        return B;
    }
};

