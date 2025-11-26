# Meta Hacker Cup 2024 – Round 2 Team Review

이번 Meta Hacker Cup Round 2 문제들은 “표면적으로 단순해 보이나, 내부 제약과 연산 구조에서 난도가 폭발하는 유형”들이 많았고 세 명의 역할이 가장 균형 있게 드러난 대회였다.

---

## ⭐ 팀 구성 & 역할

### **• Benjamin Watson**  
Benjamin은 이번 세트에서 가장 핵심적인 역할을 했다.  
A의 XOR 분할 식 구조, B의 트리 경로 합 분해, D의 선형 점화 재구성 등 “문제의 본질을 수학적 형태로 정리하는 단계”는 거의 모두 Benjamin이 빠르게 잡아줬다.  
Meta 특유의 “숨겨진 단조성·수론적 반복·비정형 조건”을 정리하는 능력이 독보적이며, 특히 D 문제에서는 Berlekamp–Massey와 모듈러 연산 설계를 **직관적으로** 잡아낸 것이 결정적이었다.

### **• Timothy Lee**  
Timothy는 엔지니어링적 고성능 구현에서 빛났다.  
특히 B(centroid decomposition)와 C(sliding window scheduling)에서  
- 메모리 접근 패턴 개선  
- branch 탈출 최소화  
- priority queue 최적화  
등을 제안해 전체 수행 시간을 안정적으로 통과시키는 데 큰 역할을 했다.  
Meta R2처럼 입력 크기가 커서 미세한 구현 차이가 성능에 2배 이상 영향을 주는 대회에서는 Timothy의 역할이 필수적이었다.

### **• 나(홍열)**  
나는 두 사람이 만들어낸 “추상적 구조·최적화 아이디어”를  
**실제 제출 가능한 안정적 코드**로 완성하는 역할을 맡았다.  
Meta 대회의 경우 overflow·메모리 파편화·예외 케이스가 치명적인데,  
이런 부분을 사전에 차단하고 구현을 실전용으로 정제하는 부분에서  
내가 팀 생산성을 크게 높였다.

---

## 🔍 문제별 수행 내용

### **A — XOR Partition**  
벤이 전체 xor의 성질을 이용하면 partition feasibility가 단순화된다는 점을 먼저 파악했고, 이를 기반으로 나는 prefix 검증 구조를 안정적으로 구현했다.  
A는 단순하지만 예외 처리가 까다로운 문제라,  
특히 “total xor = 0인 경우와 아닌 경우의 분기”를  
안정적으로 처리한 것이 돋보였다.

---

### **B — K-divisible Tree Paths**  
이 문제는 Meta 브랜드 문제에서 자주 등장하는 트리 전체 경로 카운팅 유형이었다.  
경로 합 modulo 분해 방식을 제안했고,  
 centroid decomposition 기반 prefix 수집을  
캐시 친화적으로 재배열하며 재귀 깊이·메모리 누수·중복 counting 방지 구조를  
대회 환경에 맞게 안정화하여 제출 가능한 형태로 완성했다.

---

### **C — Sliding Window Job Scheduling**  
C는 “window constraint + priority scheduling”이라는 전형적인 Meta식 복합 greedy 문제였다.  
티미가 priority queue 최소화 전략을 제안했고,  
나는 이를 실제 메모리 압박 상황에서도 안전하게 동작하도록 구현했다.  
불필요한 eviction 및 sum overflow 방지를 통해 최종 점수까지 안정적으로 도달했다.

---

### **D — Linear Recurrence with Large Step**  
가장 난도가 높았던 문제였다.  
벤이 recurrence 식을 빠르게 재구성하고  
Berlekamp–Massey 적용 가능성을 제시했으며,  
티미가 multiply 단계의 cost를 효율적으로 줄였다.  
나는 전체 흐름을 관리하며,  
- pow(b, MOD-2) 계산의 안정성  
- negative mod 처리  
- edge case에서 init[n] 참조  
같은 실전 문제를 모두 정리했다.  
이 과정에서 내가 팀에서 수행하는 “구현 안전망 역할”이 확실히 드러났다.

---

나는 두  팀원보다 추상적 정리 속도는 다소 느릴 수 있지만,  
그들이 가진 이론적 설계를 **가장 빠르게 실제 코드로 현실화**한다는 부분에서 팀에 큰 기여를 하고 있다.  
이 구조가 대회 내내 강하게 작용했고, 이번 라운드에서도 좋은 퍼포먼스로 이어졌다.

---


