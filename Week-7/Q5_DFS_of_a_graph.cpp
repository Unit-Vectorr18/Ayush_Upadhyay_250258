#include <iostream>
#include <vector>
using namespace std;

void dfsHelper(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& ans) {

    visited[node] = true;
    ans.push_back(node);

    for (int neighbour : adj[node]) {
        if (!visited[neighbour]) {
            dfsHelper(neighbour, adj, visited, ans);
        }
    }
}

vector<int> dfs(vector<vector<int>>& adj, int V) {

    vector<int> ans;
    vector<bool> visited(V, false);

    dfsHelper(0, adj, visited, ans);

    return ans;
}

int main() {

    int V = 5;

    vector<vector<int>> adj(V);

    adj[0].push_back(2);
    adj[0].push_back(3);
    adj[0].push_back(1);

    adj[1].push_back(0);

    adj[2].push_back(0);
    adj[2].push_back(4);

    adj[3].push_back(0);

    adj[4].push_back(2);

    vector<int> ans = dfs(adj, V);

    cout << "DFS Traversal: ";

    for (int node : ans)
        cout << node << " ";

    cout << endl;

    return 0;
}