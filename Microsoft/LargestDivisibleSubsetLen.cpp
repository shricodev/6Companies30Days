#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> ans;

    // simply for finding the len of the max div subset this works.
    int helper(vector<int> &nums, int n, int ind, int prev_ind) {

        if (ind == n) return 0;

        int not_take = 0 + helper(nums, n, ind + 1, prev_ind);
        int take = 0;

        if (prev_ind == -1 || nums[ind] % nums[prev_ind] == 0) {
            take = 1 + helper(nums, n, ind + 1, ind);
        }

        return max(take, not_take);
    }

    int largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int maxi = helper(nums, n, 0, -1);
        return maxi;
    }
};

int main() {
    Solution sl;
    vector<int> nums = {1,2, 4,8, 9, 16};
    cout << sl.largestDivisibleSubset(nums) << endl;
}