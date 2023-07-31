# Capstone_Design

시내버스 좌석 이용 조회 시스템

### 제작동기
현재 시내버스의 승차 인원을 파악하여 혼잡도를 표시해주는 시스템은 있습니다. 
그러나 시내버스 안의 빈 좌석을 안내해주는 시스템은 없습니다. 
버스를 탈 때 앉아서 가고 싶지만, 빈좌석이 있는 버스가 오기만을 마냥 기다릴 수는 없습니다. 
이럴 때 내가 타고 싶은 버스의 내부 상황을 알 수 있다면 정말 편하지 않을까 이런 생각이 들었습니다. 
쾌적한 버스를 이용하기 위하여 버스 선택을 위한 의사결정에 필요한 정보 제공의 필요성을 느꼈습니다.
- 초안
<img src="https://raw.githubusercontent.com/sso-o22/Capstone_Design/main/Images/초안.jpg">


### 과제목적
1. 편리성 증진
    - 실시간으로 버스 내의 잔여 좌석을 파악하여 버스를 편안하게 이용하고자 함.
    - 시내버스 내의 혼잡도 정보를 알려주고자 함.
2. 하차 지점 지나침 방지
   - 버스에서 졸음 등으로 인해 하차 지점을 놓치는 일이 빈번하여 알림 서비스의 필요성을 느낌

### 작품구성 및 상세내용
<img src="https://raw.githubusercontent.com/sso-o22/Capstone_Design/main/Images/구성도.jpg" width=700>

1. 압력센서
(1) 압력센서 -> LCD
    압력센서 -> LCD 출력
(2) 압력센서 -> 스마트폰
    압력센서 -> 블루투스 통신을 사용하여 전송 -> 스마트폰

2. RFID -> LCD
   입력확인 -> LCD 출력 (혼잡도 확인)

3. GPS -> 스마트폰
  - 현재 위치와 정류장의 위치 일치 여부 -> 블루투스 통신을 사용하여 전송 -> 스마트폰
  - 예약 : 원하는 정류장 예약 -> 정류장 도착 시 알림 발생

<img src="https://raw.githubusercontent.com/sso-o22/Capstone_Design/main/Images/앱_좌석현황.jpg">
<img src="https://raw.githubusercontent.com/sso-o22/Capstone_Design/main/Images/앱_정류장체크.jpg">
    
