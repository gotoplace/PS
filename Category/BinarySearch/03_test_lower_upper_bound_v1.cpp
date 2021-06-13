/*
// lower bound : 타겟보다 같거나 큰 값이 나오는 처음 위치를 찾음, 이상
// upper bound : 타겟보다 큰 값이 나오는 처음 위치를 찾음, 초과

참고 : https://jackpot53.tistory.com/33?category=715474, https://blockdmask.tistory.com/168

아래 예제에서 target이 10이면 주어진 배열크기 만큼 리턴되어야 하기 때문에 hi = N -1 이 아니고 hi = N으로 지정 해야 한다.

10 3
1 2 4 5 6 6 7 7 7 9
=>
2
2

10 6
1 2 4 5 6 6 7 7 7 9
=>
4
6

10 7
1 2 4 5 6 6 7 7 7 9
=>
6
9

10 8
1 2 4 5 6 6 7 7 7 9
=>
9
9

10 9
1 2 4 5 6 6 7 7 7 9
=>
9
9

*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXN (100)

int N, K;
int arr[MAXN + 10];

void InputData() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> arr[i];
}
int lowerBound() {
  int lo = 0, hi = N;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (K <= arr[mid]) hi = mid; // 타겟보다 같거나 큰 값이 나오는 처음 위치
    else lo = mid + 1;
  }
  return lo; // lo와 hi동일해서 아무거나 리턴해도 됨
}
int upperBound() {
  int lo = 0, hi = N;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (K < arr[mid]) hi = mid; // 타겟보다 큰 값이 나오는 처음 위치
    else lo = mid + 1;
  }
  return lo; // lo와 hi동일해서 아무거나 리턴해도 됨
}
void Solve() {
  sort(arr, arr + N);
  cout << lowerBound() << endl;
  cout << upperBound() << endl;
}
int main() {
  InputData();
  Solve();
  return 0;
}
