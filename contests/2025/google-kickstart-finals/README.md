# Google Kick Start 2025 – Finals

2025년 Google Kick Start Finals 문제들은 Google의 알고리즘 철학이 가장 강하게 드러나는 구성으로 이루어져 있다. Apple이 엔지니어링적 감각과 시스템 제약 중심의 문제를 낸다면, Google은 정교한 수학 구조·대규모 입력 처리·그리디 최적화·상태 압축·행렬 최적계산 같은 “알고리즘 자체의 깊이”를 핵심으로 둔다. 이 세트의 A/B/C/D 문제들은 서로 완전히 다른 영역을 다루면서도, Google이 Finals에서 즐겨 사용하는 핵심 패턴을 정확히 반영하고 있다.

---

## 🔍 문제 구조 개요

**Problem A – Circular Gap Minimization**  
원형 배열을 K개의 구간으로 나누어 최대 간격을 최소화하는 문제이다. Kick Start에서 정석적으로 등장하는 “정렬 + gap 계산 + binary search 최적화” 구조를 따른다. 원형으로 이어지는 케이스를 처리하기 위해 마지막 구간을 별도 계산하는 방식이 핵심이다.

**Problem B – Forbidden-State Graph Walk**  
u → v 이동의 자유도가 큰 directed graph에서, forbidden 상태를 피하면서 정확히 L 스텝 이동 가능한 경우의 수를 세는 문제이다. DP + adjacency 압축 구조가 필요하며, Google Finals에서 자주 등장하는 “상태를 적절히 제한한 경로 카운팅” 유형을 충실히 따른다.

**Problem C – Sliding Window Median of Medians**  
Google 특유의 median 문제로, 두 multiset(low/high)을 사용해 중앙값을 유지하는 전형적인 Kick Start 스타일이다. 슬라이딩 윈도우 이동 시 값 추가/삭제 후 rebalance하는 구조, 그리고 도출된 모든 median들의 중앙값을 다시 구하는 2-step median이 특징이다.

**Problem D – Compressed Automaton Matrix Power**  
상태가 압축된 자동자를 행렬로 모델링하고, T^L을 빠르게 계산하는 matrix exponentiation 문제이다. Google Finals의 전형적인 난이도인 “state compression + O(K³ log L) 계산” 패턴을 따른다. DP가 느린 경우 행렬 거듭제곱으로 전환하는 Finals급 문제 구조가 이 문제에 포함된다.

---

## ⚙️ Google Kick Start Finals의 공통 특징

- 대규모 입력을 빠르게 처리하기 위한 선형 또는 로그 기반 알고리즘  
- 명확한 수학적 성질을 기반으로 비정형 문제를 정형화하는 능력  
- 그래프/DP/그리디/행렬구조 등 다양한 알고리즘 영역을 폭넓게 요구  
- 깔끔한 분기 처리와 메모리 안정성이 필요  
- “구조를 이해하면 쉽게 풀리지만, 구조를 이해하기 전까지는 절대 직관적으로 풀리지 않음”

이번 문제 세트는 이러한 Kick Start Finals 특성을 그대로 반영해 구성되어 있다.

---

## 📁 폴더 구성

| 파일 | 설명 |
|------|------|
| `A.cpp` | 정렬 + 이분 탐색 기반의 원형 gap 최소화 |
| `B.cpp` | forbidden 상태 기반 graph DP |
| `C.cpp` | 두 multiset 기반 sliding window median |
| `D.cpp` | 상태 압축 automaton의 행렬 거듭제곱 |

---

## 🏁 마무리

Google Kick Start Finals 문제들은 알고리즘 자체가 핵심이며, “문제를 어떻게 모델링하고 단순화하는가”를 가장 중요하게 다룬다. 본 세트는 Google이 실제 Finals에서 요구하는 사고구조에 맞게 설계되었고, 각 문제의 풀이 역시 실전에서 제출 가능한 수준으로 구성되어 있다.
