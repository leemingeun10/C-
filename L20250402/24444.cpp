//2025 0402 gpt해설 추후 다시 풀 예정


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void bfs(int start, const vector<vector<int>>& graph, vector<int>& visit_order) {
    queue<int> q;
    int order = 1;
    q.push(start);
    visit_order[start] = order++;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : graph[current]) {
            if (visit_order[neighbor] == 0) {
                q.push(neighbor);
                visit_order[neighbor] = order++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, R;
    cin >> N >> M >> R;

    vector<vector<int>> graph(N + 1);
    vector<int> visit_order(N + 1, 0);

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    bfs(R, graph, visit_order);

    for (int i = 1; i <= N; ++i) {
        cout << visit_order[i] << '\n';
    }

    return 0;
}
