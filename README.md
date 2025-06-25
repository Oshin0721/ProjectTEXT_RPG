<br/>

# ⚔️ 텍스트 RPG 게임 - "TEXT-RPG"

턴제 전투, 성장, 아이템, 상점 시스템이 포함된 텍스트 RPG 게임입니다.
<br/>
플레이어는 영웅이 되어 다양한 몬스터를 쓰러뜨리고, 드래곤을 물리쳐 세계를 구해야 합니다.

<br/>

## 📑 목차
1. 주요 기능
2. 실행 방법
3. 팀 소개 및 역할
4. 기술 스택
5. 폴더 구조
6. 개선 사항

<br/>

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
- 처치 실패 시 게임 오버

<br/>

## 2️⃣ 실행 방법

### 요구 환경
- Visual Studio 2022
- C++17 지원
- 빌드 시스템: MSVC (Debug / Release)

### 실행 방법
1. main.cpp에서 프로그램 시작
2. Visual Studio 기준: Ctrl + F5 또는 디버깅 없이 시작

<br/>

## 3️⃣ 팀 소개

| 이름 | 역할 | 주요 담당 | 깃허브 주소 |
|------|------|-----------|-------------|
| 신동하 | 팀장 | Item / 발표 자료 준비 | <img src="https://github.com/Oshin0721.png" width="25px;"/> <a href="https://github.com/Oshin0721">Oshin0721 |
| 강탁완 | 부팀장 | GameManager | <img src="https://github.com/KANGTAKWAN.png" width="25px;"/> <a href="https://github.com/KANGTAKWAN">KANGTAKWAN |
| 곽준상 | 팀원 | Monster | <img src="https://github.com/jerrykwak.png" width="25px;"/> <a href="https://github.com/jerrykwak">jerrykwak |
| 이예빈 | 팀원 | Character / README 작성 | <img src="https://github.com/Billie-0.png" width="25px;"/> <a href="https://github.com/Billie-0">Billie-0 |
| 정성현 | 팀원 | Shop, Main / 발표자 | <img src="https://github.com/gussen33.png" width="25px;"/> <a href="https://github.com/gussen33">gussen33 |
| 조정원 | 팀원 | GameManager, LogManager | <img src="https://github.com/gardencho59.png" width="25px;"/> <a href="https://github.com/gardencho59">gardencho59 |

<br/>

## 4️⃣ 기술 스택
<img src="https://img.shields.io/badge/c++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"> <img src="https://img.shields.io/badge/github-181717?style=for-the-badge&logo=github&logoColor=white"> <img src="https://img.shields.io/badge/git-F05032?style=for-the-badge&logo=git&logoColor=white"> ![Visual Studio Code](https://img.shields.io/badge/Visual%20Studio%20Code-0078d7.svg?style=for-the-badge&logo=visual-studio-code&logoColor=white) ![Visual Studio](https://img.shields.io/badge/Visual%20Studio-5C2D91.svg?style=for-the-badge&logo=visual-studio&logoColor=white)
### 🤝 협업 툴
![Discord](https://img.shields.io/badge/Discord-%235865F2.svg?style=for-the-badge&logo=discord&logoColor=white) <img src="https://img.shields.io/badge/ZEP-5C57F2?style=for-the-badge&logo=ZEP&logoColor=white">

- OOP (객체지향 프로그래밍)
- Git & GitHub
- UML 다이어그램 기반 설계
- STL 컨테이너, 디자인 패턴 적용

<br/>

## 5️⃣ 폴더 구조
```
TEXT-RPG
├TEXT-RPG┌Character (Character.h, Character.cpp)
│        ├GameManager (GameManager.h, GameManager.cpp)
│        ├Item (Item.h, HealthPotion.h, AttackBoost.h, HealthPotion.cpp, AttackBoost.cpp)
│        ├LogManager (LogManager.h, LogManager.cpp)
│        ├Monster (Monster.h, Monster.cpp)
│        ├shop (shop.h, shop.cpp)
│        └main.cpp
│
└TEXT-RPG.sln
```

<br/>

## 6️⃣ 개선 사항 (향후 추가하고 싶은 기능)

### 🎁 아이템 시스템 확장
- 무의미한 아이템(예: 가죽 조각)도 드롭되어 상점에서 판매 가능하도록 개선
- 캐릭터 장비창 시스템 도입 예정 (무기, 방어구 장착 기능 포함)
- 일부 몬스터는 일정 확률로 장비 아이템을 드롭하며, 장착 또는 판매 가능하게 구현 예정

### ☑️ 전투 선택지 다양화
- 전투 중 도망가기, 협상하기 등 비전투적 선택지를 추가하여 전략적 요소 강화

### 🏹 전투 시스템 강화
- 확률 기반의 방어 시스템 도입 (일정 확률로 공격 무효화)
- 치명타(Critical) 시스템 구현으로 전투의 고점 및 변수 제공
- 추후 무한 모드(Infinite Battle Mode)를 통해 반복 플레이 지원 예정

### 📜 스토리 및 직업 시스템 도입
- 간단한 프롤로그 및 세계관 추가로 몰입감 있는 RPG 경험 제공
- 캐릭터 생성 시 직업 선택 기능 도입 (예: 전사, 마법사, 도적 등)
- 직업별 능력치/스킬 차별화로 다양한 플레이 스타일 지원
