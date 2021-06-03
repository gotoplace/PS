/*
https://www.acmicpc.net/problem/15666 : N과 M (12)
2020KB 0ms

N개의 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다.
고른 수열은 비내림차순이어야 한다.
길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족하면, 비내림차순이라고 한다.
=> 중복순열을 구하는 문제
& 중복되는 수열을 여러 번 출력하면 안됨

중복순열을 구하되 prev_num과 같은 수는 무시하도록 가지치기 한다.
그리고, 비내림차순 조건으로 가지치기 한다.

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
int arr[MAXN + 2], sol[MAXN + 2];

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> arr[i];
}
void PrintNum() {
  for (int i = 0; i < M; i++) cout << sol[i] << " ";
  cout << endl;
}
void DFS(int cnt) {
  if (cnt == M) {
    PrintNum(); return;
  }
  int prev_num = -1;
  for (int i = 0; i < N; i++) {
    if (prev_num == arr[i]) continue;
    if (cnt > 0 && sol[cnt - 1] > arr[i]) continue;
    prev_num = arr[i];
    sol[cnt] = arr[i];
    DFS(cnt + 1);
  }
}
int main() {
  InputData();
  sort(arr, arr + N);
  DFS(0);
  return 0;
}
