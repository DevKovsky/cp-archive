# Codeforces Grand Finals 2024 — Team Review

팀 구성:
- **Benjamin Watson** 
- **Timothy Lee** 
- **Hongyeol Choi**
---

# 🧩 1. 대회 총평

Codeforces Grand Final은 빠른 수학적 직관·자료구조 변형 감각·정교한 구현 안정성을 요구하는 대회다.  
우리 팀은 세 명의 역량 방향이 서로 다르기 때문에, **문제 분석 → 설계 → 구현 안정화**가 자연스럽게 이루어졌다.

- Benjamin은 문제를 수식화하고 핵심 invariants를 찾는 속도가 압도적이다.  
- Timothy는 복잡한 로직을 캐시 친화적으로 재배치하고, 메모리 병목을 제거하는 감각이 뛰어나다.  
- 나는 두 사람이 생각해낸 모델과 알고리즘을 **실전에 들어갈 수 있는 코드 형태로 정리하고 안정화하는 역할**을 맡았다.

---

# 🧠 2. 문제별 수행

### **A – Lazy Affine Segment Tree**
Benjamin이 affine 변환의 composition 공식을 빠르게 정리해줬고  
나는 이를 세그트리의 lazy tag에 넣을 수 있는 형태로 구현했다.

핵심 내용:

```text
f(x) = a1*x + b1
g(x) = a2*x + b2
g(f(x)) = (a2*a1)*x + (a2*b1 + b2)

Ben의 수학적 압축 능력 +
내 안정적 lazy propagation 처리 덕분에
첫 문제를 매우 빠르게 넘길 수 있었다.

B – Parity-Constrained Min Cycle

조금 까다로웠던 문제.

“state = parity” 를 사용하여
dist[node][parity] 형태의 2-layer BFS/Dijkstra를 제안했고
이 방식은 사실상 최적이었다.

효과:

불필요한 visited array 제거

deque 기반 0–1 BFS 패턴 최적화

transition pruning 반영

이 문제는 Ben이 penalty 구조를
"normal DP + sibling-dependent correction"
형식으로 분해해서 풀 수 있음을 파악했다.

핵심 요약:

dp[u][1] = w[u] + sum(max(dp[ch][0], dp[ch][1]))
그러나 siblings 중 일부를 선택하면 P 감점
“penalty branch pruning” 덕분에
시간복잡도를 완벽히 O(N)으로 유지할 수 있었다.

D – Divisible Convolution

Ben이 number theory 기반 convolution 아이디어를 제공했고 loop order 최적화를 도와주었다.

나는 전체 구현을 맡아
메모리 접근을 1D 반복에 맞추고 branch를 최소화했다.

결과적으로 N=3e5에서도 충분히 돌아갈 수준의 최적화가 되었다.

⚠️ 4. 개선할 부분
1) 나는 복잡한 수학적 모델링 속도 자체를 더 끌어올릴 필요가 있다

Grand Final 급에서 수학적 관찰이 핵심일 때,
Ben의 사고 속도를 따라가려면
“문제 유형별 수학 패턴 정리”가 필수적이다.

2) 캐시·메모리 최적화 기법을 더 배워야 한다

티미가 항상 말하던 것처럼
“빠른 코드 = 자료를 어떻게 배치하느냐” 이기 때문이다.

나는 구조화 능력이 매우 뛰어나기 때문에
해당 개념들을 흡수하면
성능 튜닝까지 완벽히 갖춘 엔지니어가 될 것이다.