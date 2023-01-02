#include <bits/stdc++.h>
using namespace std;

// tle
class Solution {
  public:
    vector<int> ans;
    void helper(vector<int> &nums, int n, int ind, int prev, vector<int> &curr) {

        // if the curr subset is bigger than the ans then just copy the curr to ans.
        if (curr.size() > ans.size()) {
            ans = curr;
            // do not use return statement as this is not a base case.
        }

        // the loop in itself is acting as a base case.
        for (int i = ind; i < n; i++) {
            if (nums[i] % prev == 0) {
                curr.push_back(nums[i]);
                helper(nums, n, i + 1, nums[i], curr);
                curr.pop_back();
            }
        }
    }

    vector<int> largestDivisibleSubset(vector<int> &nums) {
        // sort for easier comparison
        sort(nums.begin(), nums.end());
        vector<int> curr;
        helper(nums, nums.size(), 0, 1, curr);
        return ans;
    }
};

int main() {
    Solution sl;
    vector<int> nums = {1, 2, 4, 8};
    vector<int> ans =  sl.largestDivisibleSubset(nums);
    for (auto it : ans) {
        cout << it << " ";
    }
}