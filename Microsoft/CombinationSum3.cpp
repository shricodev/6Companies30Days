#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> ans;
    void findSum(vector<int> &curr, int k, int n, vector<bool> &taken, int i) {

        if (i == 10) {
            if (k == 0 && n == 0) {
                ans.push_back(curr);
                return;
            }
            return;
        }

        // if we can take.
        if (i <= n && taken[i] == 0 && k > 0) {

            curr.push_back(i);
            taken[i] = 1;
            findSum(curr, k - 1, n - i, taken, i + 1);
            taken[i] = 0;
            curr.pop_back();
        }

        // not take.
        findSum(curr, k, n, taken, i + 1);
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        vector<int> curr;
        vector<bool> taken(10, 0);
        findSum(curr, k, n, taken, 1);
        return ans;
    }
};