using System.Net;
using System.Net.Sockets;

namespace NetworkPractice
{
    class UDP_Program
    {
        Socket m_socket;

        void SendMessage()
        {
            // 서버에 접속 
            m_socket = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);

            // 메시지 송신
            byte[] buffer = System.Text.Encoding.UTF8.GetBytes("Hello, this is client.");
            IPEndPoint endpoint = new IPEndPoint(IPAddress.Parse(m_address, m_port));
            m_socket.SendTo(buffer, buffer.Length, SocketFlags.None, endpoint);

            // 접속 종료
            m_socket.Close();

            m_state = State.EndCommunication;

            Debug.Log("End client communication");
        }
    }// UDP로 송수신할 때는 SendTo 함수, ReceiveFrom 함수를 사용. 접속 절차가 없으므로 보낼 곳의 IP 주소와 포트 번호를 지정해서 메시지를 보내면 됨. 
     // SendTo 함수로 송신할 대마다 IP주소와 포트 번호를 지정하므로 소켓 하나로 여러 곳에 데이터를 보낼 수 있음
     // 수신할 때 ReceiveFrom 함수를 사용하여 IP주소와 포트 번호를 가져와서 보낸 곳 식별
     // Close 함수를 호출하여 통신 종료 , Close 함수 호출 후 생성한 소켓 닫으면 통신 완료
}
