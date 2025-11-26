# Codeforces Grand Finals 2024

이 폴더는 2024 Codeforces Grand Final 난이도에 맞춰 구성된  
A/B/C/D 네 문제의 솔루션을 포함합니다.  
문제들은 실제 그랜드파이널 스타일을 모방하여  
고성능 자료구조, 그래프 최적화, 트리 DP, 수론적 convolution 등  
복합 기술을 필요로 합니다.

---

## 📌 Problem Overview

### **A — Lazy Affine Segment Tree**
구간에 대해 x → a·x + b 형태의 어파인 변환을 적용하고  
range sum 쿼리를 처리하는 고급 Segment Tree 문제.

- Lazy propagation  
- Affine transformation  
- O(log N) per query

---

### **B — Parity-Constrained Min Cycle in Directed Graph**
각 간선이 parity(0/1)를 가질 때  
총 parity=1인 최단 사이클을 찾는 그래프 문제.

- Parity state Dijkstra/BFS  
- Cycle detection  
- O(N·M) 최적 구현

---

### **C — Weighted Independent Set on Tree + Sibling Penalty**
트리에서 독립 집합을 찾되,  
siblings 두 명 이상이 선택되면 penalty가 적용되는 변형 DP.

- Tree DP  
- Sibling penalty  
- Complexity: O(N)

---

### **D — Divisible Convolution with Sieve Acceleration**
i divides j 조건이 붙은 convolution 계산.  
NTT가 아니라 divisor traversal로 최적화.

- Divisor-based convolution  
- Sieve-like enumeration  
- O(N log N)

---

## 📁 Files

| File | Description |
|------|-------------|
| `A.cpp` | Lazy affine segment tree |
| `B.cpp` | Directed graph parity cycle |
| `C.cpp` | Tree DP with penalty |
| `D.cpp` | Divisible convolution |

---

## 💡 Notes

Codeforces Grand Finals 문제는  
자료구조 설계력, 수학적 감각, 구현 디테일이 극도로 중요합니다.  
이 세트는 실제 GF에 근접한 난도를 의도적으로 반영했습니다.

실제 대회 대비용 학습 자료로 사용하기 좋습니다.
