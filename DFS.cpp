#include <iostream>
#include <vector>
using namespace std;

void dfs(int v, vector<bool>& used, vector<vector<int>>& graph) {
    used[v] = true;
    for(int w: graph[v]) {
        if(!used[v]) {
            dfs(w, used, graph);
        }
    }
}


int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N + 1);

    for(int i = 0; i < M; i++) {
        int s, t;
        cin >> s >> t;
        graph[s].push_back(t);
        graph[t].push_back(s);
    }

    int v;
    cin >> v;
    vector<bool> used(N+1, false);

    dfs(v, used, graph);

    for(int i = 1; i <= N; i++) {
        if(used[i]) {
            cout << i << ' ';
        }
    }
}