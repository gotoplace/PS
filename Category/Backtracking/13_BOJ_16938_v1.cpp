/*
https://www.acmicpc.net/problem/16938 : 캠프 준비
2020KB 0ms

캠프에 사용할 문제는 두 문제 이상이어야 한다.
문제가 너무 어려우면 학생들이 멘붕에 빠지고, 문제가 너무 쉬우면 학생들이 실망에 빠지게 된다.
따라서, 문제 난이도의 합은 L보다 크거나 같고, R보다 작거나 같아야 한다.
또, 다양한 문제를 경험해보기 위해 가장 어려운 문제와 가장 쉬운 문제의 난이도 차이는 X보다 크거나 같아야 한다.
=> 문제를 잘 읽어야하는 문제 중 하나.

가장 어려운 문제, 가장 쉬운 문제의 난이도 차이를 잘 못 이해하여 풀이하였는데 실패.
다시 min, max 구하여 풀이하여 성공
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXN (15)

int N, L, R, X, A[MAXN +2], P[MAXN +2], sol;
int dbg = 0;
void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> L >> R >> X;
  for (int i = 1; i <= N; i++) cin >> A[i];
}
int checkProblem(int cnt) {
  // 문제 난이도의 합은 L보다 크거나 같고, R보다 작거나 같아야 한다.
  // 또, 다양한 문제를 경험해보기 위해 가장 어려운 문제와 가장 쉬운 문제의 난이도 차이는 X보다 크거나 같아야 한다
  int sum = 0;
  int min = 987654321, max = 0;
  for (int i = 0; i < cnt; i++) {
    sum += P[i];
    if (P[i] < min) min = P[i];
    if (P[i] > max) max = P[i];
  } 
  if (L <= sum && sum <= R && max - min >= X) return 1;
  return 0;
}
void DFS(int s, int cnt) { // 조합을 뽑고, 그 중에서 checkProblem()에 해당되는 조합만 sol 증가
  if (cnt >= 2) {
    if (checkProblem(cnt)) sol++;
  }
  for (int i = s; i <= N; i++) {
    P[cnt] = A[i];
    DFS(i + 1, cnt + 1);
  }
}
void Solve() {
  DFS(1, 0);
  cout << sol << endl;
}
int main() {
  InputData();
  Solve();
  return 0;
}
