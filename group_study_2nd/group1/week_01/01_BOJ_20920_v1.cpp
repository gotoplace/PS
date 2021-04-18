/*
https://www.acmicpc.net/problem/20920 : 영단어 암기는 괴로워

STL map 사용
map은 내부적으로 레드블랙트리구조이며, 삽입,삭제,검색시 최악의 경우에도 O(logN)을 보장한다고 함.
map<string, int> : string을 key로하여 int값 삽입, 삭제, 검색이 가능하고
이를 활용하여 memo[mapId - 1]에 해당되는 값을 O(1)로 접근 가능함.

13860KB 148ms
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN ((int)1e5) // 100,000
#define endl '\n'

map<string, int> mapset;
typedef struct _memo {
  string word;
  int cnt;
} MEMO;
MEMO memo[MAXN + 10];
int N, M, mapId = 1;
void InputData() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
}
bool comp(const MEMO &a, const MEMO &b) {
  if (a.cnt == b.cnt) {
    // 3. 알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치
    if (a.word.length() == b.word.length()) return a.word < b.word;
    // 2. 해당 단어의 길이가 길수록 앞에 배치
    return a.word.length() > b.word.length();
  }
  // 1. 자주 나오는 단어일수록 앞에 배치
  return a.cnt > b.cnt;
}
void Solve() {
  for (int i = 0; i < N; i++) {
    string word; cin >> word;
    if (word.length() < M) continue;
    if (mapset[word] == 0) { // 새로운 단어
      mapset[word] = mapId;
      memo[mapId - 1].word = word; memo[mapId - 1].cnt = 1; mapId++;
    }
    else { // 이미 입력된 단어, cnt 증가
      int id = mapset[word] - 1;
      memo[id].cnt++;
    }
  }
  // 정렬
  sort(memo, memo + mapId - 1, comp);
  for (int i = 0; i < mapId - 1; i++) cout << memo[i].word << endl;
}
int main() {
  InputData();
  Solve();
  return 0;
}
