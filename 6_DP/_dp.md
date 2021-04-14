# 다이나믹 프로그래밍

## 개요

[알고리즘 설명](https://blog.naver.com/kks227/220777103650)

- 주어진 문제를 여러 개의 부분 문제들로 나누어 푼 다음, 그 결과들로 주어진 문제를 푼다.
- 분할정복과 다르게 겹치는 문제가 발생 (메모이제이션이 필요)

### 메모이제이션

- 메모리에 결과값을 저장해서 겹치는내용은 메모리에서 가져와서 씀
- 시간을 훨씬 단축 시킬수 있음

### 탑다운, 바텀업

- 탑다운
  - 재귀 호출을 이용
  - 가장 큰 문제부터 방문해서 작은 문제순서대로
- 바텀업
  - 반복문을 이용
  - 작은 문제 부터 답을 쌓아서 큰문제를 해결

## 추천문제

- [1로 만들기](https://www.acmicpc.net/problem/1463) *
- [이친수](https://www.acmicpc.net/problem/2193)
- [01타일](https://www.acmicpc.net/problem/1904)
- [스티커](https://www.acmicpc.net/problem/9465)
- [동전 2](https://www.acmicpc.net/problem/2294) *
- [제곱수의 합](https://www.acmicpc.net/problem/1699)
- [2×n 타일링 2](https://www.acmicpc.net/problem/11727)
- [2×n 타일링](https://www.acmicpc.net/problem/11726)
- [붕어빵 판매하기](https://www.acmicpc.net/problem/11052)
- [쉬운 계단 수](https://www.acmicpc.net/problem/10844)
- [오르막 수](https://www.acmicpc.net/problem/11057)
- [이항 계수 2](https://www.acmicpc.net/problem/11051)
- [평범한 배낭 (★)](https://www.acmicpc.net/problem/12865)
- [문자열 판별 (★)](https://www.acmicpc.net/problem/16500) *
- [가장 큰 증가 부분 수열 (★)](https://www.acmicpc.net/problem/11055)

> 해결한 문제는 * 표시
