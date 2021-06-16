/*
https://www.acmicpc.net/problem/2609 : 최대공약수와 최소공배수
2020KB 0ms

https://ko.wikipedia.org/wiki/%EC%9C%A0%ED%81%B4%EB%A6%AC%EB%93%9C_%ED%98%B8%EC%A0%9C%EB%B2%95
2개의 자연수 a, b에 대해서 a를 b로 나눈 나머지를 r이라 하면 (단 a>b), a와 b의 최대공약수는 b와 r의 최대공약수와 같다.
이 성질에 따라, b를 r로 나눈 나머지 r0를 구하고, 다시 r을 r0로 나눈 나머지를 구하는 과정을 반복하여 나머지가 0이 되었을 때
나누는 수가 a와 b의 최대공약수이다.
이는 명시적으로 기술된 가장 오래된 알고리즘으로서도 알려져 있으며, 기원전 300년경에 쓰인 유클리드의 <원론> 제7권, 명제 1부터 3까지에 해당한다.
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define GCD1
int A, B;
void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> A >> B;
}
#ifdef GCD1
int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}
#elif GCD2
int gcd(int a, int b) {
  if (b == 0) return a;
  else gcd(b, a % b);
}
#else
int gcd(int a, int b) {
  int r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
#endif
void Solve() {
  // 최대공약수 GCD 구하기
  int sol = gcd(A, B);
  cout << sol << endl;
  cout << A * B / sol << endl; // 두 수의 곱을 최대공약수로 나누어주면 그 값이 최소공배수
}
int main() {
  InputData();
  Solve();
  return 0;
}
