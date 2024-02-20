using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ex01_05
{
    class Program
    {
        // $G$ DSN-999 (-0) The Main method should only be an access point to the program. Should look something like:
        // public static void Main() { new UI().Run(); }
        public static void Main()
        {
            string userInput = "";
            GetInputFromUser(ref userInput);
            NumOfDivInFour(userInput);
            NumOfBigDigitsFromUnityNum(userInput);

            System.Console.WriteLine("\nTo exit please press Enter");
            System.Console.ReadLine();
        }
        // $G$ CSS-999 (-0) Private methods should start with a lowercase letter.
        // $G$ CSS-015 (-3) Bad variable name (should be in the form of ref io_PascalCase).
        // $G$ CSS-028 (-0) A method should not include more than one return statement.
        private static void GetInputFromUser(ref string userInput)
        {
            bool isUserInputCurrect = false;
            System.Console.WriteLine("Please enter a number contains only 9 digits.\n");
            while (isUserInputCurrect == false)
            {
                userInput = System.Console.ReadLine();
                isUserInputCurrect = CheckUserInput(userInput);
                if (isUserInputCurrect == true)
                {
                    BiggestAndSmallestDigInNum(userInput);
                }
                else System.Console.WriteLine("Please enter a number contains only 9 digits.\n");
            }
        }

        // $G$ CSS-999 (-0) Private methods should start with a lowercase letter.
        // $G$ CSS-028 (-0) A method should not include more than one return statement.
        // $G$ CSS-999 (-0) Missing blank line, before return statement.

        private static bool CheckUserInput(string i_userInput)
        {
            int numberLength = i_userInput.Length;
            while (numberLength != 0)
            {
                if (i_userInput.Length != 9 || (i_userInput[numberLength - 1] < ('0' - '0')))
                {
                    System.Console.WriteLine("Sorry, you typed wrong number. Please type again!");
                    return false;
                }
                numberLength--;
            }
            return true;
        }
        // $G$ CSS-999 (-0) Missing blank line, after local variable.
        // $G$ CSS-013 (-0) Bad variable name (should be in the form of i_PascalCase).
        private static void BiggestAndSmallestDigInNum(string i_userInput)
        {
            int userInputLength = i_userInput.Length - 1;
            int parseNumberToInt = int.Parse(i_userInput);
            int minDigInNum = parseNumberToInt % 10;
            int maxDigInNum = minDigInNum;
            while (userInputLength > 0)
            {
                parseNumberToInt = parseNumberToInt / 10;
                if (parseNumberToInt % 10 > maxDigInNum)
                {
                    maxDigInNum = parseNumberToInt % 10;
                }
                else if (parseNumberToInt % 10 < minDigInNum)
                {
                    minDigInNum = parseNumberToInt % 10;
                }
                userInputLength--;
            }
            Console.WriteLine("The minimum digit of your number is: {0}", minDigInNum);
            Console.WriteLine("The maximum digit of your number is: {0}", maxDigInNum);
        }
        // $G$ CSS-999 (-0) Private methods should start with a lowercase letter.
        // $G$ CSS-999 (-0) Missing blank line, after local variable.
        // $G$ CSS-013 (-0) Bad variable name (should be in the form of i_PascalCase).
        private static void NumOfDivInFour(string i_userInput)
        {
            short numOfDivisionsBy4 = 0;
            int parseNumberToInt = int.Parse(i_userInput);
            for (int i = 0; i < i_userInput.Length; i++)
            {
                if ((parseNumberToInt % 10) % 4 == 0)
                {
                    numOfDivisionsBy4++;
                }
                parseNumberToInt = parseNumberToInt / 10;
            }
            System.Console.WriteLine("The number of digits that are divisible by four without a remainder is {0}", numOfDivisionsBy4);
        }

        // $G$ CSS-999 (-0) Missing blank line, after local variable.
        // $G$ CSS-013 (-0) Bad variable name (should be in the form of i_PascalCase).
        private static void NumOfBigDigitsFromUnityNum(string i_userInput)
        {
            short numOfBigDigFromUnity = 0;
            int parseNumberToInt = int.Parse(i_userInput);
            int unityDig = parseNumberToInt % 10;
            for (int i = 0; i < i_userInput.Length; i++)
            {
                if (parseNumberToInt % 10 > unityDig)
                {
                    numOfBigDigFromUnity++;
                }
                parseNumberToInt = parseNumberToInt / 10;
            }
            // $G$ NTT-001 (-5) You should have used string.Format here.
            System.Console.WriteLine("The number of digits that are greater than the unity number: " + numOfBigDigFromUnity);
        }
    }
}
