using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A24_Ex02_Eran_203606736_Matan_208389999
{
    internal class Program
    {
        public static void Main()
        {
            UI ui = new UI();
            Logic logic = new Logic();
            CleanGameManager m = new CleanGameManager(logic,ui);
            m.StartGame();
        }
    }
}
