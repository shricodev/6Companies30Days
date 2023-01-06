#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // or we can simply run the dfs which checks if there exista a cycle in a graph.
    // using this method since this is useful even if we are asked to print the topological sort.
    bool canFinish(int n, vector<vector<int>> &prerequisites) {
        vector<int> adj[n];

        // to complete task 0 task 1 should be done first.
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        vector<int> indegree(n);
        for (int i = 0; i < n; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        // there is for sure a node with indegree value 1.
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (auto it : adj[u]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        return topo.size() == n;
    }
};