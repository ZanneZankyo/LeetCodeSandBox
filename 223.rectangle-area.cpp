/*
 * @lc app=leetcode id=223 lang=cpp
 *
 * [223] Rectangle Area
 *
 * https://leetcode.com/problems/rectangle-area/description/
 *
 * algorithms
 * Medium (48.93%)
 * Likes:    2146
 * Dislikes: 1667
 * Total Accepted:    277.9K
 * Total Submissions: 567.8K
 * Testcase Example:  '-3\n0\n3\n4\n0\n-1\n9\n2'
 *
 * Given the coordinates of two rectilinear rectangles in a 2D plane, return
 * the total area covered by the two rectangles.
 * 
 * The first rectangle is defined by its bottom-left corner (ax1, ay1) and its
 * top-right corner (ax2, ay2).
 * 
 * The second rectangle is defined by its bottom-left corner (bx1, by1) and its
 * top-right corner (bx2, by2).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2
 * = 2
 * Output: 45
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2,
 * by2 = 2
 * Output: 16
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -10^4 <= ax1 <= ax2 <= 10^4
 * -10^4 <= ay1 <= ay2 <= 10^4
 * -10^4 <= bx1 <= bx2 <= 10^4
 * -10^4 <= by1 <= by2 <= 10^4
 * 
 * 
 */

// @lc code=start
struct Point {
    int X;
    int Y;
    Point(int x = 0, int y = 0) : X(x), Y(y) {}
};
struct Rect{
    Point Min, Max;
    Rect(int minX = 0, int minY = 0, int maxX = 0, int maxY = 0) : Min(minX, minY), Max(maxX, maxY) {}
    const Point& getBottomLeft() const {return Min;}
    Point getBottomRight() const {return Point(Max.X, Min.Y);}
    Point getTopLeft() const {return Point(Min.X, Max.Y);}
    const Point& getTopRight() const {return Max;}
    bool isPointInside(const Point& p) const {
        return Min.X <= p.X && p.X <= Max.X && Min.Y <= p.Y && p.Y <= Max.Y;
    }
    int calcArea() const {return (Max.X - Min.X)*(Max.Y - Min.Y);}
    bool isValid() const {return Min.X <= Max.X && Min.Y <= Max.Y;}
    static bool getIntersection(const Rect& a, const Rect& b, Rect& out_Intersection) {
        out_Intersection = Rect(max(a.Min.X, b.Min.X), max(a.Min.Y, b.Min.Y), min(a.Max.X, b.Max.X), min(a.Max.Y, b.Max.Y));
        //Point Min(max(a.Min.X, b.Min.X), max(a.Min.Y, b.Min.Y));
        //Point Max(min(a.Max.X, b.Max.X), min(a.Max.X, b.Max.Y));
        /*if (a.isPointInside(b.getBottomLeft()) || a.isPointInside(b.getBottomRight())
            || a.isPointInside(b.getTopLeft()) || a.isPointInside(b.getTopRight())) {
            out_Intersection = r;
            return true;
        }
        else {
            return false;
        }*/
        return out_Intersection.isValid();
    }
};
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        Rect a(ax1, ay1, ax2, ay2);
        Rect b(bx1, by1, bx2, by2);
        Rect i;
        if (Rect::getIntersection(a,b,i)) {
            //cout << '(' << i.Min.X << ',' << i.Min.Y << "),(" << i.Max.X << ',' << i.Max.Y << ')' << endl;
            return a.calcArea() + b.calcArea() - i.calcArea();
        }
        else {
            return a.calcArea() + b.calcArea();
        }
    }
};
// @lc code=end

// -2\n-2\n2\n2\n-3\n-3\n3\n-1

