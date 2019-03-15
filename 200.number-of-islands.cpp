/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (40.48%)
 * Total Accepted:    311.9K
 * Total Submissions: 770.6K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * Output: 3
 * 
 */
class Solution {
public:
    struct Point{
        int x;
        int y;
        Point(int px, int py): x(px), y(py) {}
    };
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;
        vector<vector<bool>> visit;
        visit.resize(grid.size());
        for(int i = 0 ; i < grid.size(); i++){
            visit[i].resize(grid[0].size(), false);
        }
        
        int sum = 0;
        for(int y = 0; y < grid.size(); y++){
            for(int x = 0; x < grid[y].size(); x++){
                if(visit[y][x])
                    continue;
                if(grid[y][x] == '1'){
                    queue<Point> q;
                    q.push(Point(x,y));
                    while(!q.empty()){
                        Point p = q.front();
                        q.pop();
                        if(p.y < 0 || p.y >= grid.size() || p.x < 0 || p.x >= grid[y].size() || visit[p.y][p.x] || grid[p.y][p.x] == '0'){
                            continue;
                        }
                        visit[p.y][p.x] = true;
                        q.push(Point(p.x+1,p.y));
                        q.push(Point(p.x-1,p.y));
                        q.push(Point(p.x,p.y+1));
                        q.push(Point(p.x,p.y-1));
                    }
                    sum++;
                }
            }
        }
        return sum;
    }
};

