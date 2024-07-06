# Project Portfolio

![Unreal Engine](https://img.icons8.com/color/48/000000/unreal-engine.png) ![C++](https://img.icons8.com/color/48/000000/c-plus-plus-logo.png) ![C#](https://img.icons8.com/color/48/000000/c-sharp-logo.png) ![Visual Studio](https://img.icons8.com/color/48/000000/visual-studio.png) ![MySQL](https://img.icons8.com/color/48/000000/mysql-logo.png)

## Career

### Mantisco (11.22.33 ~ 11.22.33)

#### 프로젝트: Carrieverse (11.22.33 ~ 11.22.33)

- 게임 서버 통신
- 서버 패킷 작성
- DB 수정
- 빌드 배포
- 빌드 자동화 및 Slack연동 (Jenkins)
- UI 기반 작업
- 리소스 관리
- 게임 컨텐츠 개발
  - 하우징

#### 프로젝트: Hunter's Arena (11.22.33 ~ 11.22.33)

- 게임 컨텐츠 개발
  - Steam, PS4, PS5 도전 과제
  - 키 가이드 
  - 전투 특성
  - 랭크

- 유지 보수 및 기타
  - 게임 매칭 시스템 리팩토링 및 구현
  - 프로필
  - 컬렉션

## Motivation

- **Objective:** 전 회사에서 근무하며 작업 했던 내용을 바탕으로 동작가능한 적당한 코드를 작성한다.
- **Portfolio:** 해당 포트폴리오는 Carrieverse 프로젝트를 진행 했을 때 작업했던 내용들이 일반적인 클라이언트 프로그래머가 하지 않는 일이라 그 일에 대한 리마인드의 성격을 띈다.
- **Server Integration & Unreal Slate UI:** 서버 연동 작업과 Unreal Slate UI에 대한 이해도를 나타내기 위함이다.
  - 회사에 재직하는 동안 WidgetBlueprint를 많이 사용 했기에 자주 쓰지 않았던 Slate를 주로 이용.

## Platforms

![Windows](https://img.icons8.com/color/48/000000/windows-10.png) ![Ubuntu](https://img.icons8.com/color/48/000000/ubuntu--v1.png) ![Android](https://img.icons8.com/color/48/000000/android-os.png)

- Windows 
- Ubuntu 
- Android 

## Tools

![Unreal Engine](https://img.icons8.com/color/48/000000/unreal-engine.png) ![Visual Studio](https://img.icons8.com/color/48/000000/visual-studio.png) ![VS Code](https://img.icons8.com/color/48/000000/visual-studio-code-2019.png) ![MySQL](https://img.icons8.com/color/48/000000/mysql-logo.png)

- Unreal Engine 5.4.2
- Visual Studio 2022
- Visual Studio Code
- MySQL Workbench 8.0 CE

## Languages

- C++
- C#

## Objectives

- 데디 서버와 게임 서버, 게임 서버와 클라이언트와 통신
  - 직렬화는 Google.Protobuf를 이용
  - 게임 서버와 데디 서버는 AWS의 EC2를 이용
  - DB는 AWS의 RDS를 이용

- 클라이언트는 서버와 통신을 수행하는 동작을 구현
  - 로그인 / 로그아웃
  - 컬렉션 수집
  - 데디 이동
  - 데이터 저장 (DB)
    - 계정 정보
    - 캐릭터 위치, 이름
    - 컬렉션

- Slate를 통한 UI 조작

## Game Flow Chart

![Game Flow Chart](link_to_your_image)

## Server Arch

### Module

- **GameServer**
  - TCP
  - Protocol
  - Messages
  - Serialize / Deserialize
    - using Google.Protobuf
  - Interface
    - Responser
    - Handler
      - Notify Handler
      - Request Handler
  - Database
    - using MySql

- **Tool**
  - Common
    - CommandLineArguments
  - Publish
    - scp
    - ssh
  - Generator
    - CSharp
    - Unreal

## Unreal Project Arch

### Module

- **ZeeNet**
  - Private
    - Protocol
    - Messages
    - Serialize / Deserialize
      - using Google.Protobuf
    - Convert (Proto to Unreal)
  - Public 
    - Interface
      - Responser
      - Handler
        - Notify Handler
        - Request Handler
    - Unreal Messages
      - generated by Server.Generator
    - TCP Client

- **ZeeUI**
  - Public 
    - SlateStyles
    - Lobby
      - LoginWidget
      - CharacterSelectWidget
    - Common
      - Popup

- **ProjectPlayground**
  - ZeeUI, ZeeNet
  - Lobby
    - GameMode
    - PlayerController
    - Character
  - InGame
    - GameMode
    - PlayerController
    - Character
