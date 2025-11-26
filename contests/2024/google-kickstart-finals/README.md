# Google Kick Start Finals 2024

이 폴더는 2024 Google Kick Start Finals에서 출제되는 난이도와 유사한 형태의 A/B/C/D 네 문제 솔루션을 포함한다. Kick Start Finals는 문제 건마다 핵심 알고리즘이 명확하고, 제한 조건이 빡빡해 빠른 수학적 모델링·상태 압축·DP·매트릭스 거듭제곱 등 복합적 사고가 필수적이다. 이 문제 세트는 대회 특유의 일관된 주제를 피하고, 각 문제마다 완전히 다른 알고리즘 영역을 사용하도록 구성해 중복을 제거했다.

A는 “임계값을 만족하는 K개의 segment를 고르는 최대 threshold”를 구하는 이분 탐색 + DP 문제로, Kick Start 특유의 “값에 대한 이분 탐색 + 가능성 검증” 스타일을 반영했다. 
B는 interval covering을 최적화하는 고전적 그리디 문제지만, Finals 난도를 고려하여 interval 정렬 방식과 최소 배치 전략을 더 정교하게 구성했다. 
C는 DAG 위에서 penalty 기반으로 longest path를 구하는 문제로, 간선 상태성(parity), penalty 삽입, DAG 위상 순서 최적화 등 Finals에서 자주 등장하는 “상태 추가형 그래프 DP”를 재현했다. 
D는 상태 전이가 있는 오토마톤을 K번 적용하는 문제로, Kick Start에서 반복적으로 등장했던 matrix exponentiation 기반 카운팅 문제의 Finals 확장판이다.

각 파일은 독립된 알고리즘 문제로 구성되어 있으며, 입력 크기와 구조는 실제 Finals 수준의 제약을 반영한다.
