1.1 목적(Purpose)

- 본 문서는 ‘시스템 프로그래밍’ 3조에서 채팅 프로그램을 설계 및 구현하기 위한 것으로 이를 위한 요구사항을 정리, 분석, 기재한 내용을 바탕으로 시스템을 설계 및 구현한다.
- 본 문서는 전반적인 요구사항을 서술하여, 완성도 높은 프로그램을 개발하는 것을 최우선 목적으로 한다.

1.2 범위(Scope)

- (기능 1) 다수를 상대로 보내는 전체 채팅 기능
- (기능 2) 특정 개인을 상대로 1:1 채팅을 보내는 기능
- (기능 3) 선택한 유저의 채팅을 보지 않게 하는 기능
- (기능 4) 명령어 정보를 한 화면에 출력하는 기능

1.3 용어 및 약어 정리 (Definitions, Acronyms, and Abbreviations)

1.4 참고 문헌 (References)

1.5 개요(Overview)

- 본 문서는 2장에서 종합적인 기술사항을 서술하고, 3장에서는 기능 및 UI의 상세한 요구사항에 대해서 설명한다.
1. 종합 기술사항 (Overall Description)

2.1 프로젝트 결과물 전망 (Project Result Perspective)

2.1.1 시스템 인터페이스 (System Interface)

시스템은 리눅스 터미널로 구동되며, 사용자의 입력은 User Interface의 키보드 입력으로 이루어진다. 클라이언트 입력에 맞추어 Server에서 해당 입력에 대한 처리를 한다.

2.1.2 사용자 인터페이스(User Interfaces)

사용자 인터페이스는 curses.h, terminfo와 같은 라이브러리를 활용하여 사용자의 편리성을 중점으로 구성한다.

2.1.3 소프트웨어 인터페이스 (Sofrware Interfaces)

개발 환경 : Linux 18.04

2.1.4 운영(Operations)

프로그램을 배포하지는 않으며 서버의 데이터는 csv 엑셀 파일을 통해 관리한다.

2.2 제품의 기능 (Project Functions)

본 프로그램은 다음과 같은 기능을 수행한다.

- (기능 1) 다수를 상대로 보내는 전체 채팅 기능

사용자가 서버에 존재하는 모든 유저들에게 메시지를 보낸다.

- (기능 2) 특정 개인을 상대로 1:1 채팅을 보내는 기능

사용자가 특정 유저를 대상으로 메시지를 보낸다.

- (기능 3) 선택한 유저의 채팅을 보지 않게 하는 기능
- (기능 4) 명령어 정보를 한 화면에 출력하는 기능

2.3 제약사항 (Constraints)

- User의 사용을 고려하여 최대한 사용자에게 친화적인 인터페이스를 개발한다.
- 협업이 필요한 내용은 코드를 공유하여 신속하게 해결한다.
1. 상세 요구사항 (Specific Requirements)

3.1 기능 요구사항 (Functional Requirements)

3.1.1 데이터베이스 요구사항 (DataBase Requirements)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/d7d877d7-544f-4439-85f1-61dbf8376e62/Untitled.png)

- User TB

사용자의 정보(IP, Name, Ban정보)를 저장하여 관리하는 테이블입니다.

- Chat TB

채팅 기록을 저장하여 관리하는 테이블입니다.

3.1.2 정보 흐름(Information flow)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/55912504-cde4-4ebd-8304-b6ab7958d426/Untitled.png)

사용자가 프로그램 첫 사용시 사용할 닉네임을 입력한다. 서버는 닉네임이 유효한지 검사 후 해당 사용자의 정보를 데이터 베이스에 저장한다.

사용자A가 사용자B에게 1:1 채팅 서비스를 요청하면 서버는 사용자B에게 메시지를 보낸다.(A의 채팅 요청을 수락하시겠습니까?) B가 요청을 수락하면 서버는 A와 B의 DM 채팅방을 개설한다.

사용자 A가 사용자B를 Ban하는 서비스를 요청하면 서버는 데이터 베이스에 해당 사용자의 정보를 저장(업데이트)한다. B가 A에게 DM 요청을 보내면 서버는 사용자A에게 메시지를 보내지 않는다.

3.1.3 유즈 케이스(Use case)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/eb156d98-dceb-45a2-9941-299bcaa68cc2/Untitled.png)

- Login, Direct Message, Ban 기능은 사용자 검색 기능을 포함한다.

3.1.3 알고리즘 요구사항 (Algorithm Requirements)

3.1.3.1 Direct Message 알고리즘

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/f657938f-611f-4e8e-b57d-79d56b62ff9f/Untitled.png)

- 서버
1. socket()

통신을 위한 소켓을 생성한다.

1. bind()

서버의 ip주소와 포트를 소켓에 할당한다.

1. listen()

클라이언트의 연결을 기다리는 대기 상태로 만든다.

1. accept()

클라이언트의 연결 요청이 오면 수락한다.

1. read() / write()

두 컴퓨터 사이의 데이터를 전송하고 받는다.

1. close()

연결을 종료한다.

- 클라이언트
1. socket()

통신을 위한 소켓을 생성한다.

1. connect()

서버에 연결을 요청한다.

1. read() / write()

서버에서 데이터를 받고 전송한다.

1. close()

연결을 종료한다.

3.2 외부 요구사항

3.2.1 UI 요구사항(User Interface)

3.2.1.1 초기 화면

![ui 초기화면.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/83328fcd-a705-4f6d-9460-029e33fa2691/ui_초기화면.png)

3.3 성능 요구사항 (Performance Requirements)

본 프로그램은 Linux 터미널에서 작동하며 사용자의 요청으로부터 안정적인 응답속도를 유지할 수 있도록 한다. 또한 사용자의 정보를 데이터베이스에 저장하므로 정보를 안전하게 보관할 수 있도록 한다.

3.4 설계 제약조건 (Design Constraints) 팀프로젝트의 짧은 기간을 고려하여 프로토타입 개발 방법론을 선택하여 기본적인 기능의 빠른 구현을 추구한다. 또한, 팀원과 함께 협업을 진행할 수 있도록 프로그래밍 소스에 주석을 포함하고 변수명은 쉽게 이해할 수 있는 이름을 사용한다.

3.5 기능별 구현 우선순위 (Functional Development Priority)

3.5.1 최우선 구현 사항

- (기능 1) 다수를 상대로 보내는 전체 채팅 기능
- (기능 2) 특정 개인을 상대로 1:1 채팅을 보내는 기능

3,5,2 우선 구현 사항

- (기능 3) 선택한 유저의 채팅을 보지 않게 하는 기능
- (기능 4) 명령어 정보를 한 화면에 출력하는 기능

3.5.3 선택 구현 사항

-