#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string getHint(string secret, string guess) {
        int no_of_bulls = 0;
        int no_of_cows = 0;

        // int in guess or secret is single digit.
        vector<int> secret_freq(10, 0);
        vector<int> guess_freq(10, 0);
        
        // finding the count of the bulls and their indices.
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                no_of_bulls++;
            } else {
                secret_freq[secret[i] - '0']++;
                guess_freq[guess[i] - '0']++;
            }
        }

        for(int i = 0; i < 10; i++)  {
            // we are taking the min since it is the max that is matching in both the array.
            no_of_cows += min(secret_freq[i], guess_freq[i]);
        }

        string ans = to_string(no_of_bulls) + "A" + to_string(no_of_cows) + "B";
        return ans; 
    }
};