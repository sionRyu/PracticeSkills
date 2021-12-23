using System.Net;
using System.Net.Sockets;

namespace NetworkPractice
{
    class TCP_Program
    {
        // 대기 시작, 대기 종료 
        public bool StartServer(int port, int connectionNum);
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

        public enum NetEventType
        {
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

        // 여기까진 NetworkLibrary 클래스에 있는 내용 복붙 변수들은 다음에 따로 만들어주기





        static Socket m_listener;     
        static Socket m_socket;       

        void StartListener(int port)
        {
            m_listener = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);  // 대기할 리스닝 소켓 생성 
            m_listener.Bind(new IPEndPoint(IPAddress.Any, port));//소켓에 인수 port로 지정된 포트번호 할당 Bind 함수를 통해 연관지을 endpoint(일반적으로는 네트워크 단말을 가리키지만 여기서는 네트워크 주소를 가리킴) 지정

            m_listener.Listen(1); // listen 함수를 호출해서 리스닝 소켓을 대기상태로 만듦

            m_state = State.AcceptClient;
        } // 이와 같은 과정을 거치면 리스닝 소켓은 클라이언트에서 오는 접속 요청을 기다리는 상태가 됨. 

        void AcceptClient() {
            if (m_listener != null && m_listener.Poll(0, SelectMode.SelectRead)
            {
                //클라이언트가 접속했다.
                m_socket = m_listener.Accept(); // 클라이언트가 접속을 요청할 때까지 블로킹 {블로킹이란? 호출한 함수를 처리할 때까지 처리의 제어가 돌아오지 않는 것}
                // Accept함수를 호출하면 클라이언트가 접속할 때까지 이 함수 안에서 처리를 계속하고 그 동안 애플리케이션은 정지 그러나 이렇게 되면 안되므로 위의 if문 안에 Poll 함수로 클라가 보내는 데이터를 감시해서 
                // 데이터를 수신했을 때만 Accept함수를 호출   ><><><>< 클라가 접속 요청하면 Accept함수는 요청한 클라와 통신하기 위해 Socekt 클래스의 인스턴스 반환 이후 새로 생성한 소켓 인스턴스를 사용해서 클라와 통신
                m_isConnected = true;

                if (m_handler != null)
                {
                    NetEventState state = new NetEventState();
                    state.type = NetEventType.Connect;
                    state.result = NetEventResult.Success;
                    m_handler(state);
                }
            } // 클라이언트의 접속 요청을 받아들이기 위한 과정
        }// 서버는 준비 완료!


        void ClientProcess()
        {
            // 서버에 접속하는 부분만 발췌 {
            m_socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp); // 소켓 클래스의 인스턴스 생성 
            m_socket.NoDelay = true;         // 작은 패킷을 버퍼링 하지 않도록 
            m_socket.SendBufferSize = 0;     // 작은 패킷을 버퍼링 하지 않도록 
            m_socket.Connect(m_address, m_port);  // 서버의 ip주소와 포트 번호를 지정해서 접속을 요청함. 
            // 단 Connect함수는 블로킹 함수라서 접속을 완료할 때까지 다른 처리를 실행할 수 없음. 접속에 실패하면 SocketException이라는 대기 예외를 던짐.
            // Socket.Blocking 속성을 false로 지정하면 Connect 함수를 블로킹하지 않지만, 접속이 완료될 때까지 기다리지 않으므로 통신 상대의 접속이 완료 되었는지 애플리케이션에서 감시해야함.그러나 여기선 그러지 않음.
            // 그러므로 블로킹 되지 않도록 대처
            // 발췌 여기까지 }

            // 송신 부분만 발췌 {
            byte[] buffer = System.Text.Encoding.UTF8.GetBytes("Hello, this is client.");
            m_socket.Send(buffer, buffer.Length, SocketFlags.None); // 데이터 송신 
            // 발췌 여기까지 }

            // 접속 종료 부분만 발췌 {
            m_socket.Shutdown(SocketShutdown.Both);
            m_socket.Close();

            Debug.Log("End client communication.");
            // 발췌 여기까지}
        }

        void ServerCommunication() 
        {
            byte[] buffer = new byte[1400]; // 수신 단말의 버퍼에 저장 - >  Receive함수를 호출해서 버퍼에 저장된 데이터를 가져올 수 있다.
            int recvSize = m_socket.Receive(buffer, buffer.Length, SocketFlags.None);
            if (recvSize > 0)
            {
                string message = System.Text.Encoding.UTF8.GetString(buffer);
                Debug.Log(message); // 유니티에서 이뤄지는 서버통신이기 때문에 콘솔창에 띄울려고 debug.log
                m_state = State.StopListener;
            }
        }// 애플리케이션이 Receive 함수를 호출할 때까지 데이터는 시스템의 버퍼에 게속 저장됨, 그래서 Receive 함수를 호출하지 않은 채 내버려 두면 수신 버퍼의 공간이 없어져 더는 수신 불가,
         // 애플리케이션에서 적절히 Receive 함수를 호출하여 수신 버퍼를 비워줍시당~~.

        //통신 종료할 때는 <<<<Shutdown>>>> 함수로 패킷 송수신을 차단한 다음, <<<<Close>>>> 함수로 접속을 끊는다! -- ClientProcess 함수에 있음

        void StopListener()
        {
            if (m_listener != null)
            {
                m_listener.Close();
                m_listener = null;
            }

            m_state = State.EndCommunication;

            Debug.Log("End server communication.");
        }

    }
}
