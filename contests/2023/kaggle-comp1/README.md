# Kaggle Competition 2023 — Feature Engineering & Data Processing

이 폴더는 **2023 Kaggle Competition 1**을 기반으로 한  
데이터 전처리, 피처 엔지니어링, 통계 분석 문제들을 정리한 공간입니다.

Kaggle 대회는 단순 알고리즘이 아닌  
대규모 데이터 처리·통계·특징 최적화 구조가 핵심이기 때문에  
문제 스타일 또한 이를 반영하여 구성했습니다.

팀 구성:
- **최홍열 (Hongyeol Choi)**
- **Benjamin Watson**
- **Timothy Lee**

---

## 📌 포함된 문제 요약

### **A — Sliding Window Maximum Feature Extraction**
N 길이의 시계열 데이터에 대해,  
윈도우 크기 W가 주어졌을 때 모든 구간의 최대값을 O(N)에 구하는 문제.  
Kaggle의 feature extraction에서 매우 자주 등장하는 패턴.

핵심 기술:
- Monotonic Deque  
- Rolling feature 계산  
- Large-scale input 처리

---

### **B — Data Normalization Pipeline Simulation**
StandardScaler, MinMaxScaler, RobustScaler 등의  
실제 머신러닝 전처리 스케일링 방식을 그대로 시뮬레이션하는 문제.

핵심 기술:
- 평균, 표준편차, 분위수 계산  
- 대규모 데이터 정규화  
- 수치 안정성(Numerical Stability)

---

### **C — Feature Selection Optimization (0/1 Knapsack)**
각 피처의 계산 비용과 모델 성능 점수를 고려해  
총 계산 시간 Budget 내에서 최적의 피처 조합을 고르는 문제.

핵심 기술:
- Knapsack DP  
- 대규모 상태값 처리  
- Feature engineering 최적화의 Kaggle 감성 반영

---

### **D — Pearson Correlation & Outlier Detection**
N×M 데이터셋에서 피처 간 상관관계(피어슨 상관계수)를 계산하고  
Z-score 기반으로 outlier를 판정하는 문제.

핵심 기술:
- 통계량 계산(평균, 표준편차)  
- 상관계수 행렬 생성  
- Z-score 기반 이상치 탐지

---

## 📁 파일 구성

| 파일명 | 설명 |
|--------|-------|
| `A.cpp` | 슬라이딩 윈도우 최대값 활용 피처 추출 |
| `B.cpp` | 머신러닝 스케일러 시뮬레이션 |
| `C.cpp` | 예산 제한 피처 선택 최적화 |
| `D.cpp` | 상관 분석 + 이상치 탐지 |
| `review.md` | 대회 회고 및 개선 포인트 |

---

## ✨ 참고 사항

대회 스타일은 ‘실전 Kaggle preprocessing & feature engineering’을 그대로 반영했으며,  
대규모 데이터에 대해 빠르고 안정적인 처리 방식에 중점을 두었습니다.

온라인 머신러닝 대회를 준비하는 개발자에게 매우 유익한 문제 구조입니다.
