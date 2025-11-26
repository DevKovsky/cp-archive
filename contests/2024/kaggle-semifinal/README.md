# Kaggle Competition 2024 — Semifinal Round

이 폴더는 **2024 Kaggle Semifinal Round**에서 다루는 핵심적인 데이터 전처리·통계 분석·피처 최적화 문제들을 기반으로 구성되었습니다.  
실제 Kaggle 준결승에서 측정되는 능력은 아래 네 가지입니다:

1. 대규모 데이터 처리 속도  
2. 수치 안정성(Numerical Stability)  
3. 복합 피처 최적화(Feature Optimization)  
4. 상관관계·이상치 탐지(EDA 핵심 능력)

---

## 📌 포함된 문제

### **A — Sparse Feature Aggregation**
대규모 sparse vector 기반 데이터에서  
각 feature의 합계, 최댓값, 등장 횟수를 효율적으로 계산.

- Sparse 구조 최적화  
- 메모리 접근 패턴 개선  
- Kaggle-style preprocessing

---

### **B — Drift-Resistant Normalization**
Training → Test로 분포가 살짝 변하는 drift 상황에서  
Normalization 후 안정적인 clipping 수행.

- mean/std 기반 z-score 변환  
- drift 대비한 clipping  
- 수치 안정성 확보(division safeguard)

---

### **C — Dual-Budget Feature Selection**
Compute 비용 + Memory 비용을 동시에 고려한  
멀티 제약 피처 선택 문제.

- 2D knapsack  
- Feature Ranking  
- Budget-aware optimization

---

### **D — Correlation Matrix + Outlier Detection**
M개 feature의 상관 계수를 계산하고  
Z-score 기반으로 outlier flagging.

- Pearson correlation  
- Variance stability  
- Robust Z-score thresholding

---

## 🧠 기술 스택 및 수행 전략

- C++ 기반 고성능 구현  
- 메모리 최적화, branch cut, boundary-safe normalization  
- Kaggle-style preprocessing pipeline의 핵심 요소 반영

---

## 📁 파일 구성

| 파일 | 설명 |
|------|------|
| `A.cpp` | Sparse feature aggregation |
| `B.cpp` | Normalization + drift handling |
| `C.cpp` | Multi-budget feature selection |
| `D.cpp` | Correlation + outlier check |
| `review.md` | (요청 시 생성) 팀 백그라운드·성장 포인트·협업 구조 |

---

## 📌 비고

준결승 라운드에서는 단순한 정답 구현이 아닌  
- 안정성  
- 확장성  
- 성능  
을 종합적으로 테스트하는 특성이 있습니다.

이번 문제 세트는 해당 철학을 그대로 반영해 제작된 구조입니다.
