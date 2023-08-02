//描述：输入vector<vector<int>> rects,单个矩形表示为rect[i]=[x1,y1,x2,y2] 有以下两个条件：1.任两个矩形无交集 2.所有矩形并集也为矩形  返回bool值判断是否满足上述两个条件
//样例：[[0,1,2,4],[0,4,4,5],[1,1,4,2],[2,2,4,4]]  false
//在存储角点的过程中，如果发现重复的角点，则将其从`corners`中移除。最后，判断`corners`中的角点数量是否为4，并且总面积是否等于所有矩形的并集的面积，如果满足条件则返回`true`，否则返回`false`。
#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool isRectangleCover(vector<vector<int>>& rects) {
    int minX = INT_MAX, minY = INT_MAX, maxX = INT_MIN, maxY = INT_MIN;
    int area = 0;
    set<pair<int, int>> corners;
    
    for (vector<int>& rect : rects) {
        minX = min(minX, rect[0]);
        minY = min(minY, rect[1]);
        maxX = max(maxX, rect[2]);
        maxY = max(maxY, rect[3]);
        area += (rect[2] - rect[0]) * (rect[3] - rect[1]);
        
        pair<int, int> bottomLeft = {rect[0], rect[1]};
        pair<int, int> bottomRight = {rect[2], rect[1]};
        pair<int, int> topLeft = {rect[0], rect[3]};
        pair<int, int> topRight = {rect[2], rect[3]};
        
        if (corners.count(bottomLeft)) {
            corners.erase(bottomLeft);
        } else {
            corners.insert(bottomLeft);
        }
        
        if (corners.count(bottomRight)) {
            corners.erase(bottomRight);
        } else {
            corners.insert(bottomRight);
        }
        
        if (corners.count(topLeft)) {
            corners.erase(topLeft);
        } else {
            corners.insert(topLeft);
        }
        
        if (corners.count(topRight)) {
            corners.erase(topRight);
        } else {
            corners.insert(topRight);
        }
    }
    
    if (corners.size() != 4 || area != (maxX - minX) * (maxY - minY)) {
        return false;
    }
    
    return true;
}

int main() {
    vector<vector<int>> rects = {{1, 1, 3, 3}, {3, 1, 4, 2}, {1, 3, 2, 4}, {2, 2, 4, 4}};
    bool result = isRectangleCover(rects);
    cout << (result ? "true" : "false") << endl;
    return 0;
}