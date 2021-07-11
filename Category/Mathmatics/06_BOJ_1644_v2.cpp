/*
https://www.acmicpc.net/problem/1644 : 소수의 연속합
9128KB 28ms

소수를 구하는 방법 예제 : https://jongmin92.github.io/2017/11/05/Algorithm/Concept/prime/
소수를 빠르게 구하는 예제 : https://velog.io/@max9106/Algorithm-%EC%97%90%EB%9D%BC%ED%86%A0%EC%8A%A4%ED%85%8C%EB%84%A4%EC%8A%A4%EC%9D%98-%EC%B2%B4

공간 복잡도, 시간 복잡도 최적화 버전
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXN ((int)4e6) // 4,000,000

int N;
bool check[MAXN + 10];
vector<int> prime;

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N;
}
void MakePrimeNums() {
  // 2부터 N-1까지의 수 중에서 2의 배수를 모두 체로 거르고
  // 남은 숫자들 중에서 3의 배수로 거르고를 반복해서
  // 제곱근N 까지 나눠서 걸러지지 않고 남은 수들이 모두 소수가 됨
  for (int i = 2; i <= 2000; i++) { // 4,000,000의 제곱근, sqrt() 사용시 개선 없음
    if (check[i] == 0) {
      for (int j = i; i * j <= N; j++) check[i * j] = 1;
    }
  }
  // 0으로 남은 수들은 모두 소수
  for (int i = 2; i <= N; i++) {
    if (check[i] == 0) prime.push_back(i);
  }
}
void Solve() {
  // NOTE : 1은 소수가 아님
  // 에라토스테네스의 체
  MakePrimeNums();
  // 연속된 소수의 합으로 N을 만들 수 있는 경우의 수 찾기
  int cnt = 0, lo = 0, hi = 0, sum = 0;
  while (1) {
    if (sum >= N) sum -= prime[lo++];
    else if (hi == (int) prime.size()) break;
    else sum += prime[hi++];

    if (sum == N) cnt++;
  }
  cout << cnt << endl;
}
int main() {
  InputData();
  Solve();
  return 0;
}
