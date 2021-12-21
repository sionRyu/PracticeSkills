﻿/*
 * 2.1 : 피해갈 수 없는 통신의 구조
 * 
 * 단말 안의 데이터를 패킷에 담아 라우터와 케이블을 통해 통신 상대의 단말에 보낸다 . 
 * 이때 송신할 데이터가 없을 때까지 패킷을 보내는데 패킷 안에는 IP주소와 포트번호를 실어서 보낸다. 
 * ip주소는 특정 컴퓨터를 찾을 때 , 포트 번호는 컴퓨터 안에서 프로그램을 찾을 때 필요하다.
 * 
 * 일부 기기가 고장나거나 성능이 너무 안좋아서 패킷에 담긴 일부 정보를 유실하거나 패킷 자체가 파괴되는 경우가 있음 
 * 
 * 어떻게 대처해야할지 알기 위해서 우선 프로토콜의 개념을 배우자!
 * 
 * 
 * 
 * 2.2 : 프로토콜 이해하기
 * 
 * TCP vs UDP
 * 짐 배달 업무로 의인화 해서 설명하자면?
 * tcp 군은 택배기사
 * 1. 짐을 배달해도 되는지 배송지에 미리 묻는다(접속처리)
 * 2. 배송지에서 배달해도 된다고 한다
 * 3. 짐을 가지고 배달한다
 * 4. 도착해서 수령했다는 사인까지 받아온다.
 * 5. 만일 배달하다 잃어버리면 재배달 한다. ( 송신한 단말에 오래도록 확인 응답이 되돌아 오지 않을 경우)
 * 
 * tcp는 용량이 크면 세그먼트라는 데이터로 작게 분할 및 tcp가 다룰 수 있는 헤더를 세그먼트에 붙여서 전달.
 * tcp는 결국 애플리케이션이 지시한 타이밍보다 지연되어 송신됨.
 * 
 * udp군은 빠른 택배
 * 1. 그냥 묻지마 배달
 * 2. 짐 잃어버려도 그냥 감
 * 3. 재배달 없음
 * 
 * udp는 전달 순서를 고려하지 않기 때문에 애플리케이션에서 바꿔야함 
 * 
 * 
 * 하지만 게임에서는 안전한 tcp보다 udp를 이용하는데 턴제 게임에서는 tcp를 사용해도 되겠지만 실시간 게임에서는 udp가 훨씬 낫다.
 * 좀 더 실력이 쌓이면 udp 방식에 재전송 기능을 추가하는 등 자신의 입맛대로 만들어서 쓰면 훨씬 이득이다..
 * 
 * 
 * 2.3 : 알아두면 좋을 기초지식 
 * 지연 시간 (레이턴시) 
 * 레이턴시 못느끼게 하기 (송신할 정보를 줄이거나 하긴 힘드니깐 다른 방법으로 아니면 정보 자체를 꼭 필요한 것만)
 * 통신량 고려해서 만들기
 */