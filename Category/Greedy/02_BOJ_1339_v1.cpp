/*
https://www.acmicpc.net/problem/1339 : 단어 수학
2028KB 0ms

참고 : https://yabmoons.tistory.com/132, https://imnotabear.tistory.com/85
그리디, 브루트포스로 분류됨
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXN (26) // for alphabets

int N;
int anum[MAXN +2];
vector<string> v;

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s; v.push_back(s);
  }
}
bool comp(int a, int b) {
  if (a > b) return true;
  return false;
}
void Solve() {
  for (int i = 0; i < N; i++) { // 입력받은 단어 순서대로 처리
    string s = v[i];
    int len = s.length();
    int pow = 1; // 1의 자리부터 처리하기 위해 10 거듭제곱 수 1로 초기화
    for (int j = len - 1; j >= 0; j--) { // 1의 자리부터 처리
      int idx = s[j] - 'A'; // char 'A'를 빼면 idx를 알 수 있음
      anum[idx] += pow; // 각 알파벳에 해당되는 idx요소에 값이 더해진다
      pow *= 10; // 자리수가 커질 수록 10씩 곱해야 하므로 pow값에 10씩 곱한다
    }
  }
  // 내림차순 정렬
  sort(anum, anum + MAXN, comp);
  int sum = 0, num = 9; // 가장 큰 수에 9를 곱하고 다음 수에는 8을 곱 num 감소 하는 방법으로 진행
  for (int i = 0; i < MAXN; i++) {
    if (anum[i] == 0) break; // 더 이상 처리할 필요 없음
    sum += anum[i] * num;
    num--;
  }
  cout << sum << endl;
}
int main() {
  InputData();
  Solve();
  return 0;
}
