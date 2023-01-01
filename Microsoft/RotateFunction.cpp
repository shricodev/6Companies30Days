#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxRotateFunction(vector<int> &nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        vector<int> rotate_vals(n);
        int prev_sum = 0;
        int total_sum = 0;

        // 0th rotate
        for (int i = 0; i < n; i++) {
            rotate_vals[i] = nums[i] * i;
            prev_sum += rotate_vals[i];
            total_sum += nums[i];
        }
        maxi = max(maxi, prev_sum);          

        int last_elem = nums[n - 1];

        // the n - 2 rotations
        for (int i = 1; i < n; i++) {
            // this is the formuale I deduced. this is the sum for the curr index.
            int calculations = prev_sum - (last_elem * (n - 1)) + total_sum - last_elem;
            maxi = max(maxi, calculations);
            // for another index the calculation is the prev sum.
            prev_sum = calculations;
            last_elem = nums[n - 1 - i];
        }

        return maxi;

    }
};

int main() {
    Solution sl;
    vector<int> nums = {4, 3, 2, 6};
    cout << sl.maxRotateFunction(nums) << endl;
}
