# Capstone_Design

시내버스 좌석 이용 조회 시스템

### 제작동기
현재 시내버스의 승차 인원을 파악하여 혼잡도를 표시해주는 시스템은 있으나 시내버스 안의 빈 좌석을 안내해주는 시스템은 없다.
버스를 탈 때 앉아서 가고 싶지만, 빈좌석이 있는 버스가 오기만을 마냥 기다릴 수는 없다.
이럴 때 내가 타고 싶은 버스의 내부 상황을 알 수 있다면 정말 편하지 않을까 라는 생각이 들어 제작하게 되었다.

- 초안
<img src="https://raw.githubusercontent.com/sso-o22/Capstone_Design/main/Images/초안.jpg" width=700>


### 과제목적
1. 편리성 증진
    - 실시간으로 버스 내의 잔여 좌석을 파악하여 버스를 편안하게 이용하고자 함.
    - 시내버스 내의 혼잡도 정보를 알려주고자 함.
2. 하차 지점 지나침 방지
   - 버스에서 졸음 등으로 인해 하차 지점을 놓치는 일이 빈번하여 알림 서비스의 필요성을 느낌

### 작품구성 및 상세내용
<img src="https://raw.githubusercontent.com/sso-o22/Capstone_Design/main/Images/구성도.jpg" width=700>

1. 압력센서
   - 압력센서 -> LCD 출력 (빈 좌석 수 표시)
     <img src="https://raw.githubusercontent.com/sso-o22/Capstone_Design/main/Images/RFID_free.png" width=700> 
   - 압력센서 -> 블루투스 통신을 사용하여 전송 -> 스마트폰
     <img src="https://raw.githubusercontent.com/sso-o22/Capstone_Design/main/Images/압력센서.png" width=700>
     
2. RFID -> LCD
    - 입력확인 -> LCD 출력 (혼잡도 확인)
    - 앞문 태그 +1
    - 뒷문 태그 -1
    - 0 ~ 7 : free (여유)
    - 8 ~ 11 : normal (보통) 
    - 12 : full (혼잡)

      <img src="https://raw.githubusercontent.com/sso-o22/Capstone_Design/main/Images/RFID_normal.png" width=700> 

3. GPS -> 스마트폰
  - 현재 위치와 정류장의 위치 일치 여부 -> 블루투스 통신을 사용하여 전송 -> 스마트폰
  - 예약 : 원하는 정류장 예약 -> 정류장 도착 시 알림 발생

    <img src="https://raw.githubusercontent.com/sso-o22/Capstone_Design/main/Images/앱_정류장체크.jpg" width=300 height=600>
     
    [GPS 기능 시연 영상](https://github.com/sso-o22/Capstone_Design/blob/main/Video/GPS_%EC%8B%9C%EC%97%B0%EC%98%81%EC%83%81.mp4)
    
