using System.Net;
using System.Net.Sockets;

namespace NetworkPractice
{
    class TCP_Program
    {
        static Socket m_listener;     
        static Socket m_socket;       

        static void Main(string[] args)
        {

        }

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
