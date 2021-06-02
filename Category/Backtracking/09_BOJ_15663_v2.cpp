/*
https://www.acmicpc.net/problem/15663 : N과 M (9)
4072KB 900ms
=> 메모리 사용량은 줄었으나, 실행 시간이 길어졌음. 최적화 필요

N개의 자연수를 입력받고 정렬하는 것 외에 15654 N과 M (5) 순열 문제와 동일한 문제
단, 입력되는 자연수에 중복된 값이 있으며, 중복된 수열을 제거해야 함

순열, 중복순열, 조합, 중복조합 개념
https://m.blog.naver.com/alwaysneoi/100155625557

순열, 중복순열, 조합, 중복조합 공식
https://bb-dochi.tistory.com/47
https://m.blog.naver.com/honeyeah/220295949101
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXN (8)

int N, M;
int arr[MAXN + 2], used[MAXN + 2], sol[MAXN + 2];
vector<vector<int>> backup_sol; // 공간복잡도를 줄이기 위해 2차원 vector 사용

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> arr[i];
}
int FindNum() {
  int found;
  for (int i = 0; i < (int)backup_sol.size(); i++) {
    found = 1;
    for (int j = 0; j < M; j++) { // M개 원소 하나씩 비교하여 다른 값이면 0, break
      if (backup_sol[i][j] != sol[j]) {
        found = 0; break;
      }
    }
    if (found) break; // 이 전에 출력된 수열과 중복된다면 반복문 종료
  }
  return found;
}
void BackupNum() {
  vector<int> v;
  for (int i = 0; i < M; i++) v.push_back(sol[i]);
  backup_sol.push_back(v);
}
void PrintNum() {
  for (int i = 0; i < M; i++) cout << sol[i] << " ";
  cout << endl;
}
void DFS(int cnt) {
  if (cnt == M) {
    if (FindNum() == 1) return; // 이 전에 출력된 값 중 중복된 수열이 있으면 그냥 return
    BackupNum(); // backup_sol[][] 가장 마지막에 backup
    PrintNum(); return;
  }
  for (int i = 0; i < N; i++) {
    if (used[i]) continue;
    used[i] = 1;
    sol[cnt] = arr[i];
    DFS(cnt + 1);
    used[i] = 0;
  }
}
int main() {
  InputData();
  sort(arr, arr + N);
  DFS(0);
  return 0;
}
