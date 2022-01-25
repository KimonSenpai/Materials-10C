#include <iostream>
#include <vector>
using namespace std;

void dfs(int v, vector<vector<int>>& graph, vector<bool>& mark) {
    mark[v] = true;
    for(int w: graph[v]) {
        if(!mark[w]) {
            dfs(w, graph, mark);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<bool> mark(n + 1, false);
    for(int i = 0; i < m; i++) {
        int f, t;
        cin >> f >> t;
        graph[f].push_back(t);
        graph[t].push_back(f);
    }
    int v;
    cin >> v;
    dfs(v, graph, mark);
    for(int v = 1; v <= n; v++) {
        if(mark[v]) {
            cout << v << ' ';
        }
    }
    cout << '\n';
}