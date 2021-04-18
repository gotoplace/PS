/*
https://www.acmicpc.net/problem/1759 : 암호 만들기

DFS로 풀이
전제 조건에 주의하면 금방 해결 가능함.

정렬, cnt == 4인 경우
모음 1개, 자음 2개 인 경우에만 출력
2016KB 0ms
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
int L, C, sel[15 + 5];
char A[15 + 5];

void InputData() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> L >> C;
  for (int i = 0; i < C; i++) cin >> A[i];
}
void printPw() {
  int found_a = 0, found_b = 0;
  for (int i = 0; i < C; i++) {
    if (sel[i] == 0) continue;
    if (A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u') found_a++;
    else found_b++;
  }
  if (found_a >= 1 && found_b >= 2) { // 모음 최소 1개, 자음 최소 2개이면 출력
    for (int i = 0; i < C; i++) {
      if (sel[i] == 0) continue;
      cout << A[i];
    }
    cout << endl;
  }
}
void DFS(int cnt, int s) {
  if (cnt == L) {
    printPw(); return;
  }
  for (int i = s; i < C; i++) {
    if (sel[i]) continue;
    sel[i] = 1;
    DFS(cnt + 1, i);
    sel[i] = 0;
  }
}
void Solve() {
  sort(A, A + C);
  DFS(0, 0);
}
int main() {
  InputData();
  Solve();
  return 0;
}
