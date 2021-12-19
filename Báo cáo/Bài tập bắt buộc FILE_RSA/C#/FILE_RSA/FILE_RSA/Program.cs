using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;

namespace TestSocket2
{
    class Program
    {
       static int sodu(int a, int b)
        {
            if (b < 0) b = -b;
            while (a < 0)
                a += b;
            return (a % b);
        }
        static int ucln(int a, int b)
        {
            if (a == b) return a;
            if (a > b) return ucln(a - b, b);
            if (b > a) return ucln(a, b - a);
            return -1;
        }
        static int NghichDaoModun(int a, int m)
        {
            if (m < 0) m = -m;
            if (ucln(a, m) > 1) return -1;
            if (m == 1) return -1;
            a = a % m;
            int r, q, y0, y1, y;
            y0 = 0;
            y1 = 1;
            int m_org = m;
            while (true)
            {
                r = m % a;
                if (r == 0)
                    return sodu(y, m_org);
                q = (int)(m / a);
                y = y0 - y1 * q;
                y0 = y1;
                y1 = y;
                m = a;
                a = r;
            }
        }
       static int soduluythua(int a, int b, int c) // a^b*(mod c)
        {
            if (b == 0) return 1;
            if (b == 1) return a % c;
            if (b % 2 == 0)
                return soduluythua(((a % c) * (a % c)) % c, b / 2, c);
            if (b % 2 == 1)
            {
                int d = soduluythua(((a % c) * (a % c)) % c, (b - 1) / 2, c);
                d = (a * d) % c;
                return d;
            }
            return -1;
        }
        static int giaimaRSA(int y, int d, int n)
        {
            return soduluythua(y, d, n);
        }
        static ASCIIEncoding encoding = new ASCIIEncoding();
        static void Main(string[] args)
        {


            Console.OutputEncoding = Encoding.UTF8;
            try
            {
                IPAddress ipAdd = IPAddress.Parse("127.0.0.1");
                TcpListener listener = new TcpListener(ipAdd, 100);
                listener.Start();
                Console.WriteLine("Waitting for connect to client");
                Socket server = listener.AcceptSocket();
                Console.WriteLine("Connect successfully");
                //Lay tong so chuoi RSA
                byte[] dataKT = new byte[100];
                server.Receive(dataKT);
                string KT = encoding.GetString(dataKT);
                int ktRSA = int.Parse(KT);
                //Lay ma RSA
                string[] sRSA = new string[ktRSA];
                int[] intRSA = new int[ktRSA];
                Console.WriteLine("Chuoi ma hoa RSA: ");
                for (int i = 0; i < ktRSA; i++)
                {
                    byte[] data = new byte[100];
                    server.Receive(data);
                    sRSA[i] = encoding.GetString(data);
                    intRSA[i] = int.Parse(sRSA[i]);
                    Console.Write("{0}", sRSA[i]);

                }
                //Lay khoa cong khai
                Console.WriteLine("Lay khoa cong khai tu client");
                byte[] data1 = new byte[100];
                server.Receive(data1);
                string resultKey1 = encoding.GetString(data1);
                int d = int.Parse(resultKey1);
                byte[] data2 = new byte[100];
                server.Receive(data2);
                string resultKey2 = encoding.GetString(data2);
                int n = int.Parse(resultKey2);
                // Giai ma RSA
                Console.WriteLine("Giai ma RSA: ");
                for (int i = 0; i < ktRSA; i++)
                {
                    char X = (char)giaimaRSA(intRSA[i], d, n);
                    Console.Write("{0} ", X);
                }




                server.Shutdown(SocketShutdown.Both);
                server.Close();


            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }
            finally
            {

            }
            Console.ReadKey();
        }
    }
}
