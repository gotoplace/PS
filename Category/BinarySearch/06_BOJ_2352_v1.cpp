/*
https://www.acmicpc.net/problem/2352 : 반도체 설계
2332KB 4ms

LIS를 구하고 그 길이를 출력하는 문제
아래 조건으로 처리
- LIS[]에 오름차순으로 port[] 입력이 가능한지
- 그렇지 않다면, lowerBound()가 찾아주는 pos에 port[] 입력
- LIS의 len을 출력

LIS 활용시 LIS 배열에 저장되는 값이 문제 예시와는 달라서 다른 방법으로 접근해야하는지 고민했음.

참고 : https://steadev.tistory.com/5
사실 위 예시 기준으로 cache를 마지막에 찍어보면 위 그림과 같은 답은 도출되지 않습니다. 
2-2가 연결되야 하는데 5-1이 연결되있는 등 겹치게 됩니다.
하지만 답에서 요구하는 것은 최대 몇개까지냐 이므로 굳이 고려하지 않았습니다. 
어짜피 뒤에 더 큰 숫자의 포트와 연결되어 있기에 아래 연결된 포트들은 개수를 측정하는데 별 의미가 없었습니다.

아래 코드의 결과 cache안에는 2-2, 4-3, 6-5가 아닌 5-1, 4-3, 6-5가 들어있습니다.
여기서 5-1이냐 2-2냐는 답을 도출하는데 있어 중요치 않습니다.

참고 : https://sihyungyou.github.io/baekjoon-2352/ (STL 숏코드)
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXN ((int)4e4) // 40,000

int N;
int port[MAXN + 10], LIS[MAXN + 10];

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> port[i];
}
int lowerBound(int lo, int hi, int target) {
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (target <= LIS[mid]) hi = mid;
    else lo = mid + 1;
  }
  return lo;
}
void Solve() {
  // LIS 길이를 구하면 답
  int len = 0;
  for (int i = 1; i <= N; i++) {
    if (LIS[len] < port[i]) LIS[++len] = port[i];
    else {
      int pos = lowerBound(1, len, port[i]);
      LIS[pos] = port[i];
    }
  }
  cout << len << endl;
}
int main() {
  InputData();
  Solve();
  return 0;
}
