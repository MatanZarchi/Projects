using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Ex01_02;

namespace Ex01_03
{
    class Program
    {
        // $G$ CSS-999 (-0) Missing blank line, after local variable.
        // $G$ DSN-999 (-5) The Main method should only be an access point to the program. Should look something like:
        // public static void Main() { new UI().Run(); }
        public static void Main()
        {
            int rhombusHeight = GetInputFromUser();
            if(rhombusHeight % 2 == 0)
            {
                rhombusHeight--;
            }
            // $G$ NTT-999 (-0) You should have used Environment.NewLine instead of "\n".

            Ex01_02.Program.PrintRecursiveRhombus(rhombusHeight);
            System.Console.WriteLine("\nTo exit please press Enter");
            System.Console.ReadLine();
        }
        // $G$ CSS-999 (-0) Missing blank line, after local variable.
        // $G$ CSS-999 (-0) Missing blank line, before return statement.
        private static int GetInputFromUser()
        {
            bool isInputCorrectFlag = false;
            Console.WriteLine("To draw Rhombus, please enter the height.");
            string userInput = "";
            while (isInputCorrectFlag != true)
            {
                userInput = Console.ReadLine();
                bool correctInput = CheckUserInput(userInput);
                if (correctInput == true)
                {
                    isInputCorrectFlag = true;
                }
            }
            return int.Parse(userInput);
        }
        // $G$ CSS-028 (-0) A method should not include more than one return statement.
        // $G$ CSS-999 (-0) Missing blank line, before return statement.

        private static bool CheckUserInput(string i_userInput)
        {
            int userInputInteger = 0;
            bool successToConvert = int.TryParse(i_userInput,out userInputInteger);
            if(successToConvert == true && userInputInteger > 2)
            {
                return true;
            }
            else
            {
                Console.WriteLine("Incorrect input!\nPlease enter a number.");
                return false;
            }
        }
    }
}
