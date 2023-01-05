#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void process(set<pair<int, int>> &st, int x, int y) {
        if (st.count({x, y})) {
            auto it = st.find({x, y});
            st.erase(it);
            return;
        }

        st.insert({x, y});
    }

    bool isRectangleCover(vector<vector<int>> &rectangles) {
        int n = rectangles.size();
        long long sumArea = 0;
        // these will hold the left, right, top, and bottom cordinate of the formed rectangle.
        int leftMost = INT_MAX;
        int rightMost = 0;
        int topMost = 0;
        int bottomMost = INT_MAX;

        set<pair<int, int>> st;

        for (vector<int> &rect : rectangles) {
            leftMost = min(leftMost, rect[0]);
            rightMost = max(rightMost, rect[2]);
            bottomMost = min(bottomMost, rect[1]);
            topMost = max(topMost, rect[3]);

            sumArea += (rect[2] - rect[0]) * 1LL * (rect[3] - rect[1]);

            // if the item is already in the set then remove else add. In this way we shouldget 4 items in the set which should not repeat the corners of the rectangle.
            process(st, rect[0], rect[1]); // bottom left point
            process(st, rect[0], rect[3]); // bottom right point
            process(st, rect[2], rect[3]); // top right point
            process(st, rect[2], rect[1]); // top left point
        }

        long long grandArea = (rightMost - leftMost) * 1LL * (topMost - bottomMost); // l * b
        if (sumArea != grandArea)
            return false;

        if (st.size() != 4 || !st.count({leftMost, bottomMost}) || !st.count({leftMost, topMost}) || !st.count({rightMost, bottomMost}) || !st.count({rightMost, topMost})) {
            return false;
        }
        return true;
    }
};