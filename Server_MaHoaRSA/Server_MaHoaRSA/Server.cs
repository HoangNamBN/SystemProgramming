using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Net;
using System.Text;
using System.Threading.Tasks;

namespace Server_MaHoaRSA
{
    class Server
    {
        private const int BUFFER_SIZE = 1024;
        private const int PORT_NUMBER = 9999;
        private const int p = 257;
        private const int q = 259;
        public const int e = 35; //ucln(35,256*257)=1
        //public const int n = p * q;
        

        static ASCIIEncoding encoding = new ASCIIEncoding();

        static int soDu(int a, int b)
        {
            if (b < 0)
            {
                b = -b;
            }
            while (a < 0)
            {
                a += b;
            }
            return (a % b);
        }//soDu
        static int ucln(int a, int b)
        {
            if (a == b) return a;
            if (a > b) return ucln(a - b, b);
            if (a < b) return ucln(a, b - a);
            return 0;
        }//ucln
        static int nghichDaoModul(int a, int m) //thuat toan Enclid mo rong
        {
            if (m < 0) m = -m;
            if (ucln(a, m) > 1) return -1;
            if (m == 1) return -1;
            a = a % m; //1 <= a <= m-1

            int r, q, yo, y1, y = 0;
            yo = 0;
            y1 = 1;
            int org_m = m;
            while (true)
            {
                r = m % a;
                if (r == 0) return soDu(y, org_m);
                q = (int)(m / a);
                y = yo - y1 * q;
                yo = y1;
                y1 = y;
                m = a;
                a = r;
            }//while 
        }//nghichDaoModul
        static int soDuLuyThua(int a, int b, int c)
        {
            int d=0;
            if (b == 0) return 1;
            if (b == 1) return (a % c);
            if (b % 2 == 0) return soDuLuyThua(((a % c) * (a % c)) % c, (b / 2), c);
            if (b % 2 == 1)
            {
                d = soDuLuyThua(((a % c) * (a % c)) % c, ((b - 1) / 2), c);
                d = (d * a) % c;
            }//if
            return d;
        }//soDuLuyThua
        static int giaiMaRSA(int y, int d, int n)
        {
            return soDuLuyThua(y, d, n);
        }

        public static void Main(string[] args)
        {
            try
            {
                IPAddress address = IPAddress.Parse("127.0.0.1");

                TcpListener listener = new TcpListener(address, PORT_NUMBER);

                //1. Listen
                listener.Start();

                Console.WriteLine("Server start on " + listener.LocalEndpoint);
                Console.WriteLine("Waiting for connection...");

                Socket socket = listener.AcceptSocket();
                Console.WriteLine("Connection recieve from " + socket.RemoteEndPoint);

                //2.Recieve
                byte[] data = new byte[BUFFER_SIZE];
                socket.Receive(data);

                String str = encoding.GetString(data);
                Console.WriteLine("Receive: " + str);

                int d = nghichDaoModul(e, (p - 1) * (q - 1));
                Console.WriteLine("d = " + d);
                int y = Int32.Parse(str);
                Console.WriteLine("y = " + y);
                char x = (char)giaiMaRSA(y, d, p*q);
                string str_x = Convert.ToString(x);
                Console.WriteLine(str_x);

                //3. Send
                socket.Send(encoding.GetBytes("Sever: " + x));

                //4.Close
                socket.Close();
                listener.Stop();
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex);
            }
            Console.Read();

        }
    }
}
