#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isOperator(string s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }

    int pushHelper(int top, int second_top, string token) {
        if (token == "+") return second_top + top;
        else if (token == "-") return second_top - top;
        else if (token == "*") return second_top * top;
        else return second_top / top; 
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();

        for (int i = 0; i < n; i++) {
            string s = tokens[i];
            if (isOperator(tokens[i])) {
                int top = st.top();
                st.pop();
                int second_top = st.top();
                st.pop();
                st.push(pushHelper(top, second_top, s));
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};