#include <iostream>
#include <vector>
using namespace std;

void dfs(int cur, vector<int>* adj, int* parent);

int main() {
    int n;
    cin >> n;
    vector<int> adj[100001];
    int parent[100001] = {};

    for(int i=0;i<n-1;i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    parent[1] = -1;
    dfs(1, adj, parent);

    for(int i=2;i<=n;i++) {
        cout << parent[i] << '\n';
    }
}

void dfs(int cur, vector<int>* adj, int* parent) {
    for(int next : adj[cur]) {
        if(parent[next] == 0) {
            parent[next] = cur;
            dfs(next, adj, parent);
        }
    }
}