/*
https://www.acmicpc.net/problem/1753 : 최단경로
다익스트라 최단경로 알고리즘, STL 우선순위큐를 활용하여 풀이

9180KB 116ms
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN ((int)2e4) // 20,000
#define endl '\n'

int V, E, K; // 노드 수, 간선 수, 시작점
using pii = pair<int, int>;
vector<pii> graph[MAXN + 10];
#define INF ((int)1e9 + 10)
int d[MAXN + 10];

void InputData() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> V >> E >> K;
  for (int i = 0;  i < E; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({w, v}); // cost, dest
  }
}
void Solve() {
  fill(d, d + V + 1, INF);
  priority_queue<pii, vector<pii>, greater<pii>> pq; // STL priority_queue는 max heap 구조, 최단경로에서는 min heap 구조 필요, greater필요
  d[K] = 0; pq.push({d[K], K}); // 시작점 큐에 넣고 시작
  while (!pq.empty()) {
    auto cur = pq.top(); pq.pop();
    int dist = cur.first, idx = cur.second;
    if (d[idx] != dist) continue;
    // 현재 노드에서 연결된 노드 최단 거리 갱신
    for (auto next : graph[idx]) {
      int cost = next.first, nidx = next.second;
      if (d[nidx] > dist + cost) {
        d[nidx] = dist + cost; pq.push({d[nidx], nidx});
      }
    }
  }
  // 최단 거리 출력
  for (int i = 1; i <= V; i++) {
    if (d[i] == INF) cout << "INF" << endl;
    else cout << d[i] << endl;
  }
}
int main() {
  InputData();
  Solve();
  return 0;
}
