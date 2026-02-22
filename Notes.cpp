class Notes{
    #define INT_MAX 0x7FFFFFFF
    #define INT_MIN 0x80000000
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
};

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
        return out_Intersection.isValid();
    }
};