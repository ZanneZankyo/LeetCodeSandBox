/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (30.86%)
 * Total Accepted:    292.8K
 * Total Submissions: 948.7K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * Example 1:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * 
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 */
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> rows;
        rows.resize(numRows);
        int cursor = 0;
        bool down = true;
        for(char c : s)
        {
            rows[cursor].push_back(c);
            if(numRows == 1)
                continue;
            if(down)
            {
                cursor++;
                if(cursor>=numRows)
                {
                    down = false;
                    cursor-=2;
                }
            }
            else
            {
                cursor--;
                if(cursor<0)
                {
                    down = true;
                    cursor = 1;
                }
            }
        }
        string result;
        for(const string& rs : rows)
        {
            result.insert(result.end(),rs.begin(),rs.end());
        }
        return result;
    }
};

