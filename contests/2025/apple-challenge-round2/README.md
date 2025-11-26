# Apple Coding Competition 2025 – Round 2

2025년 Apple Round 2의 문제들은 단순한 알고리즘 문제처럼 보이지만, 그 내부에는 Apple이 실제로 중요하게 생각하는 엔지니어링 감각과 시스템적 사고가 깊게 반영되어 있다. Apple이 주로 다루는 iOS 생태계, Swift 런타임, 메모리 안정성, 에너지 관리, functional 구조 등이 문제 속에 자연스럽게 녹아 있기 때문에, 단순히 알고리즘만 빠르면 되는 대회가 아니라 “문제를 현실 서비스의 제약과 연결해서 이해할 수 있는가”가 핵심이 된다.

---

## 🔍 문제 구조 개요

A 문제는 통계적 개념(분산)을 빠르게 계산해야 하는 상황을 제시하면서, ML/데이터 엔지니어링에서 자주 사용되는 E[x]·E[x²] 기반의 분석을 요구한다. 이는 단순 수학 문제가 아니라 Apple의 ‘ML in production’ 철학과 이어진다. B 문제는 Swift의 문자열 처리 방식과 매우 유사한 상태 전이 기반 tokenizer 구조를 구현하는 문제인데, 실제 Swift compiler나 Foundation 라이브러리의 토크나이저 동작 원리를 그대로 모델링한 형태에 가깝다.

C 문제는 Apple 기기에서 가장 중요한 제약 중 하나인 “배터리 사용량”을 중심에 둔 스케줄링 문제이며, 사전에 정해진 에너지 budget 내에서 최적 해를 선택해야 한다. Apple OS 특유의 resource management 방식이 문제에 반영되어 있다. D 문제는 불변 자료구조(Immutable / Functional Structure)를 직접 구현하는 문제이며, 이 역시 Swift의 값 타입(value semantics), ARC 기반 메모리 모델, snapshot 기반 데이터 관리와 매우 유사한 철학을 가지고 있다.

---

## ⚙️ 이 문제 세트의 핵심 포인트

Apple Round 2는 단순히 알고리즘적 정답을 찾는 것이 아니라 다음을 모두 요구한다:

- 실제 서비스 맥락에서의 제약을 고려한 문제 이해  
- 단순 효율성 이상의 “안정성” 중심 구현  
- functional 사고·메모리 안전성·분산 계산 감각  
- iOS/Swift 생태계 기반의 문제를 추상화하는 능력  

이 때문에 문제 간 중복이 전혀 없으며, 네 개의 문제는 서로 완전히 다른 기술과 사고방식을 사용하도록 구성되어 있다.

---

## 🧩 문제별 요약

**A – Minimum-Variance Subarray**  
통계 기반 연산을 대규모 연속 배열에서 안전하고 정확하게 수행해야 하는 문제. E[x²] - E[x]² 구조를 prefix로 최적화하는 Apple식 ML 프로세싱 모델이 반영됨.

**B – Swift Tokenizer Emulation**  
Swift 스타일의 문자 타입 분류(문자/숫자/심볼)에 기반한 최소 cost 토큰 분리 문제. Apple 언어 설계 철학이 그대로 담김.

**C – Battery-Constrained Scheduling**  
Apple 기기 특유의 에너지 제약 모델을 반영한 2D knapsack 구조. CPU time budget + battery budget의 조합은 Apple 문제에서 자주 등장하는 형태.

**D – Immutable Queue with Snapshot/Load**  
Swift의 값 타입·참조 투명성과 유사한 불변 queue를 구현하는 문제. Functional 자료구조 감각과 persistent stack 모델링이 요구됨.

---

## 📁 폴더 설명

| 파일 | 설명 |
|------|------|
| `A.cpp` | Minimum Variance Subarray — prefix 기반 통계 최적화 |
| `B.cpp` | Swift-like Tokenizer — 문자열 상태 전이 최적화 |
| `C.cpp` | Battery-Constrained Scheduling — 2D knapsack |
| `D.cpp` | Immutable Functional Queue — persistent 자료구조 |

---

## 🏁 마무리

이 문제들은 Apple이 실전 엔지니어 채용에서 중요하게 생각하는 개념들을 모두 포함하고 있다: 안정성, 계산 모델링, functional 구조, 자원 제약, 문자열 엔진, 통계 기반 분석 등 실무적 요소들이 고르게 등장한다.  

2025 Round 2는 알고리즘 대회의 형태를 띠고 있지만, 실제로는 “Apple 엔지니어링 철학을 기술적으로 얼마나 흡수했는가”를 측정하는 라운드이며, 이 문제 세트는 그러한 특성을 가장 잘 반영하는 형태로 구성되었다.
