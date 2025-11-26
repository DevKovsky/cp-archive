# Meta Hacker Cup 2024 – Round 2

이 폴더는 Meta Hacker Cup Round 2(2024)의 스타일에 맞춰 구성된 A/B/C/D 네 문제의 솔루션을 포함한다. Meta R2 문제의 특징은 “구조가 단순해 보이지만 내부 제약에서 난도가 폭발하는 유형”이 많으며, 트리 분해·상태 기반 그래프 탐색·고성능 세그먼트제이션·수학 기반 대규모 점프 계산 등 다양한 영역을 다룬다. 또한 Kick Start나 Codeforces Finals와 달리 Meta는 “대규모 입력 + 비정형 제약 + 자료구조 혼합”을 매우 선호한다.

A는 XOR 관점에서 prefix 성질을 활용하는 세그먼트 분할 문제로, Meta 특유의 XOR 단조성 활용을 담았다. B는 centroid decomposition 기반 트리 경로 카운팅 문제로, Meta R2의 정석 난도인 “트리 전체 경로를 제한 조건과 함께 세는 문제”를 반영한다. C는 window constraint 기반 job scheduling 문제로, 스위프 라인과 우선순위 스케줄링을 섞는 Meta식 greedy 구조를 사용한다. D는 Berlekamp–Massey + 고속 점프 조합으로 구성된 선형점화 대규모 항 계산 문제로, Facebook·Meta 계열 대회에서 반복적으로 출제되는 linear recurrence 테마를 Finals급 난도로 재현했다.

문제들은 서로 알고리즘 영역이 완전히 달라 중복 없이 구성되어 있으며, 각 풀이 코드는 실제 Round 2 환경에서 제출 가능한 수준의 복잡도와 성능을 만족한다.
