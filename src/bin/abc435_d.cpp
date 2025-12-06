#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> E(N);
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y, x--, y--;
        E[y].push_back(x);
    }

    vector<int> vis(N);
    auto bfs = [&](int sv) {
        vis[sv] = true;
        queue<int> q;
        q.push(sv);
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            for (auto v : E[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    };

    int Q;
    cin >> Q;
    while (Q--) {
        int type, v;
        cin >> type >> v, v--;
        if (type == 1 && !vis[v]) bfs(v);
        if (type == 2) cout << (vis[v] ? "Yes" : "No") << endl;
    }
}
