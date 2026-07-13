#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> bfs(vector<vector<int>>& adj, int V) {

    vector<int> ans;
    vector<bool> visited(V, false);

    queue<int> q;
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        ans.push_back(node);
        for (int neighbour : adj[node]) {

            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }

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

    vector<int> ans = bfs(adj, V);

    cout << "BFS Traversal: ";

    for (int node : ans)
        cout << node << " ";

    cout << endl;

    return 0;
}