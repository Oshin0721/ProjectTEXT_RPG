# ⚔️ 텍스트 RPG 게임 - "TEXT-RPG"

턴제 전투, 성장, 아이템, 상점 시스템이 포함된 텍스트 RPG 게임입니다.
플레이어는 영웅이 되어 다양한 몬스터를 쓰러뜨리고, 드래곤을 물리쳐 세계를 구해야 합니다.


## 📑 목차
1. 주요 기능
2. 실행 방법
3. 팀 소개 및 역할
4. 기술 스택
5. 폴더 구조
6. 개선 사항


## 1️⃣ 주요 기능

### 🔹 캐릭터 생성 및 성장
- 원하는 이름으로 캐릭터 생성 가능, 초기 능력치 고정
- 이름, 체력, 공격력, 레벨, 경험치 등 상태 확인 가능
- 레벨업 시 능력치 증가, 최대 10레벨

### 🔹 전투 시스템
- 랜덤하게 등장하는 몬스터
- 턴제 전투, 아이템 자동 사용(캐릭터의 남은 체력 기준)
- 경험치/골드/아이템 획득
  - 경험치 : 몬스터 처치 시 경험치 50 획득
  - 골드 : 몬스터에 따라 달라지는 골드 획득량
  - 아이템 : 몬스터에 따라 달라지는 아이템 드랍률

### 🔹 상점 시스템
- 골드로 아이템 구매 및 판매 가능

### 🔹 보스 몬스터(드래곤)
- 레벨 10에 도달 시 등장
- 처치 시 게임 클리어
- 비처치 시 게임 오버


## 2️⃣ 실행 방법

### 요구 환경
- Visual Studio 2022
- C++17 지원
- 빌드 시스템: MSVC (Debug / Release)

### 실행 방법
1. main.cpp에서 프로그램 시작
2. Visual Studio 기준: Ctrl + F5 또는 디버깅 없이 시작


## 🧑‍🤝‍🧑 팀 소개

| 이름 | 역할 | 주요 담당 |
|------|------|-----------|
| 신동하 | 팀장 | Item / 발표 자료 준비 |
| 강탁완 | 부팀장 | GameManager |
| 곽준상 | 팀원 | Monster |
| 이예빈 | 팀원 | Character / README 작성 |
| 정성현 | 팀원 | Shop, Main / 발표자 |
| 조정원 | 팀원 | GameManager, LogManager |


## 📚 기술 스택
<img src="https://img.shields.io/badge/c++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"> <img src="https://img.shields.io/badge/github-181717?style=for-the-badge&logo=github&logoColor=white"> <img src="https://img.shields.io/badge/git-F05032?style=for-the-badge&logo=git&logoColor=white"> ![Visual Studio Code](https://img.shields.io/badge/Visual%20Studio%20Code-0078d7.svg?style=for-the-badge&logo=visual-studio-code&logoColor=white) ![Visual Studio](https://img.shields.io/badge/Visual%20Studio-5C2D91.svg?style=for-the-badge&logo=visual-studio&logoColor=white)
- OOP (객체지향 프로그래밍)
- Git & GitHub
- UML 다이어그램 기반 설계
- STL 컨테이너, 디자인 패턴 적용
### 🤝 협업 툴
![Discord](https://img.shields.io/badge/Discord-%235865F2.svg?style=for-the-badge&logo=discord&logoColor=white) <img src="https://img.shields.io/badge/ZEP-5C57F2?style=for-the-badge&logo=ZEP&logoColor=white">


## 📁 폴더 구조
```
TEXT-RPG
├TEXT-RPG┌Character (Character.h, Character.cpp)
│                  ├GameManager (GameManager.h, GameManager.cpp)
│                  ├Item (Item.h, HealthPotion.h, AttackBoost.h, HealthPotion.cpp, AttackBoost.cpp)
│                  ├LogManager (LogManager.h, LogManager.cpp)
│                  ├Monster (Monster.h, Monster.cpp)
│                  ├shop (shop.h, shop.cpp)
│                  └main.cpp
│
└TEXT-RPG.sln
```


## 📌 개선 사항
- (아직 작성중...)
