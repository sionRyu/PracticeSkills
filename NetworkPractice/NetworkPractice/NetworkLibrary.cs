using System.Net;
using System.Net.Sockets;

namespace NetworkPractice
{
    class NetworkLibrary
    {
        // 대기 시작, 대기 종료 
        public bool StartServer(int port,int connectionNum);
        public bool StopServer();

        // 접속, 접속 종료
        // Connect 함수는 리모트 단말의 엔드포인트가 필요함. 예제 게임의 IP 주소는 문자열로 받음 따라서 접속 시엔 IP 주소와 포트 번호를 인수로 가짐.
        // Shutdown 함수(TCP만), Close 함수로 접속을 종료함. 

        public bool Connect(string address, int port);
        public bool Disconnect();

        // 송신, 수신
        // Socket 클래스에서 TCP통신으로 송수신할 때는 Send 함수와 Receive 함수를 사용함.
        // UDP 통신일 경우엔 SendTo 함수와 ReceiveFrom 함수를 사용, 이 함수들은 같은 인수를 사용하는데 이는 예제 프로그램 초기이기때문에 

        public int Send(byte[] data, int size);
        public int Receive(ref byte[] buffer, int size);


        // 이벤트 정의

        public enum NetEventType {
            Connect = 0,   // 접속 이벤트
            Disconnect,    // 접속 종료 이벤트
            SendError,     // 송신 오류
            ReceiveError,  // 수신 오류
        }

        // 이벤트 결과 

        public enum NetEventResult
        {
            Failure = -1, // 실패
            Success = 0,  // 성공
        }

        // 알림 이벤트의 상태

        public class NetEventState
        {
            public NetEventType type;      // 이벤트 타입
            public NetEventResult result;  // 이벤트 결과
        }

        // 이벤트 알림 델리게이트 정의 

        public delegate void EventHandler(NetEventState state);

        // 이벤트 등록과 등록해제는 RegisterEventHandler, UnregisterEventHandler
        // 델리게이트의 변수에 등록하고 해제할 수 있음 


        
    }
}
