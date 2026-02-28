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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *vectorToListNode(vector<int>& v) {
    ListNode *head = nullptr;
    ListNode *node = nullptr;
    for (int i = 0; i < v.size(); ++i) {
        ListNode *newNode = new ListNode(v[i]);
        if (node != nullptr) {
            node->next = newNode;
        }
        node = newNode;
        if (head == nullptr) {
            head = node;
        }
    }
    return head;
}
void releaseNodes(ListNode *node) {
    if (node == nullptr) {
        return;
    }
    releaseNodes(node->next);
    delete node;
}
void printNodes(ListNode *node, int n = 0) {
    if (node == nullptr) {
        return;
    }
    if (n > 0) {
        cout << ',';
    }
    cout << node->val;
    printNodes(node->next, n+1);
    if (n == 0) {
        cout << endl;
    }
}