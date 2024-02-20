using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
// $G$ THE-001 (-10) The file is a PE, because it is a .NET assembly, and it can be executed.
// $G$ THE-001 (-10) The file is an assembly because it can be analysed by ILDASM.

//Relevant to the entire solution:
// $G$ DSN-999 (-10) The Main method should only be an access point to the program. Should look something like:
// public static void Main() { new UI().Run(); } 
// $G$ CSS-028 (-10) A method should not include more than one return statement.
// $G$ NTT-999 (-10) You should have used Environment.NewLine instead of "\n".
// $G$ CSS-013 (-10) Bad variable name (should be in the form of i_PascalCase).
// $G$ CSS-999 (-10) Private methods should start with a lowercase letter.


namespace Ex01_01
{
    class Program
    {
        // $G$ DSN-999 (-0) The Main method should only be an access point to the program. Should look something like:
        // public static void Main() { new UI().Run(); }
        // $G$ NTT-999 (-0) You should have used Environment.NewLine instead of "\n".

        public static void Main()
        {
            string firstUserInput= "";
            string secondUserInput= "";
            string thirdUserInput= "";
            GetInputFromUser(ref firstUserInput,ref secondUserInput,ref thirdUserInput);
            PrintAvgOfNumbersZeroAndOne(firstUserInput, secondUserInput, thirdUserInput);
            PrintNumbersPowerOfTwo(firstUserInput, secondUserInput, thirdUserInput);
            PrintAcendingNumbers(firstUserInput, secondUserInput, thirdUserInput);
            PrintTheBiggestAndSmallestNumbers(firstUserInput, secondUserInput, thirdUserInput);

            Console.WriteLine("\nTo exit please press Enter");
            Console.ReadLine();
        }
        // $G$ CSS-999 (-0) Private methods should start with a lowercase letter.
        // $G$ CSS-028 (-0) A method should not include more than one return statement.

        private static bool CheckUserInput(string i_binaryNumber)
        {
            int binaryNumberLength = i_binaryNumber.Length;
            while (binaryNumberLength != 0)
            {
                if (i_binaryNumber.Length != 9 || (i_binaryNumber[binaryNumberLength - 1] != '0' && i_binaryNumber[binaryNumberLength - 1] != '1'))
                {
                    Console.WriteLine("Sorry, you typed wrong number. Please type again!");
                    return false;
                }
                binaryNumberLength--;
            }
            return true;
        }
        // $G$ CSS-999 (-0) Private methods should start with a lowercase letter.
        // $G$ CSS-999 (-0) Missing blank line, after local variable.
        // $G$ CSS-006 (-0) Missing blank line, after "if / else" blocks.
        // $G$ DSN-004 (-5) Unnecessary code duplication
        private static void GetInputFromUser(ref string i_firstUserInput, ref string i_secondUserInput, ref string i_thirdUserInput)
        {
            short loopIndex = 0;
            bool isUserInputCurrect = false;
            Console.WriteLine("Please enter 3 binary numbers, each number must be 9 digits.\n");
            while(loopIndex < 3)
            {
                if(loopIndex == 0)
                {
                    Console.WriteLine("Please enter the first binary number:");
                    i_firstUserInput = Console.ReadLine();
                    isUserInputCurrect = CheckUserInput(i_firstUserInput);
                    if (isUserInputCurrect == true)
                    {
                        loopIndex++;
                    }
                } else if (loopIndex == 1){
                    Console.WriteLine("Please enter the second binary number:");
                    i_secondUserInput = Console.ReadLine();
                    isUserInputCurrect = CheckUserInput(i_secondUserInput);
                    if (isUserInputCurrect == true)
                    {
                        loopIndex++;
                    }
                } else if( loopIndex == 2) {
                    Console.WriteLine("Please enter the third binary number:");
                    i_thirdUserInput = Console.ReadLine();
                    isUserInputCurrect = CheckUserInput(i_thirdUserInput);
                    if (isUserInputCurrect == true)
                    {
                        loopIndex++;
                    }
                }
            }
        }
        // $G$ CSS-999 (-0) Private methods should start with a lowercase letter.
        // $G$ CSS-006 (-0) Missing blank line, after "if / else" blocks.
        // $G$ DSN-004 (-5) Unnecessary code duplication
        // $G$ NTT-999 (-5) You should have used verbatim string(@)

        private static void PrintNumbersPowerOfTwo(string i_firstNumber, string i_secondNumber, string i_thirdNumber)
        {
            StringBuilder sb = new StringBuilder("", 70);
            int sumOfPowerTwoNumbers = 0;

            if (IsPowerOfTwo(i_firstNumber) == true)
            {
                sumOfPowerTwoNumbers++;
            }
            if (IsPowerOfTwo(i_secondNumber) == true)
            {
                sumOfPowerTwoNumbers++;
            }
            if (IsPowerOfTwo(i_thirdNumber) == true)
            {
                sumOfPowerTwoNumbers++;
            }
            if(sumOfPowerTwoNumbers == 0)
            {
                sb.AppendFormat("There is no number that is a power of two");
            }
            else
            {
                sb.AppendFormat($"There {(sumOfPowerTwoNumbers > 1 ? "are" : "is")} ");
                sb.AppendFormat($"{sumOfPowerTwoNumbers} ");
                sb.AppendFormat($"number{(sumOfPowerTwoNumbers > 1 ? "s" : " ")}");
                sb.AppendFormat($"that {(sumOfPowerTwoNumbers > 1 ? "are" : "is")} power of TWO");
            }
            Console.WriteLine(sb.ToString() + "\n");
        }
        // $G$ CSS-999 (-0) Private methods should start with a lowercase letter.
        // $G$ CSS-999 (-0) Missing blank line, before return statement.
        // $G$ CSS-013 (-0) Bad variable name (should be in the form of i_PascalCase).

        private static bool IsPowerOfTwo(string i_binaryNumber)
        {
            int countOnes = 0;
            for(int i = 0;  i < i_binaryNumber.Length; i++)
            {
                if(i_binaryNumber[i] == '1')
                {
                    countOnes++;
                }
            }
            return countOnes == 1;
        }
        // $G$ CSS-999 (-0) Private methods should start with a lowercase letter.
        // $G$ CSS-013 (-0) Bad variable name (should be in the form of i_PascalCase).
        // $G$ CSS-006 (-0) Missing blank line, after "if / else" blocks.

        private static void PrintAvgOfNumbersZeroAndOne(string i_firstNumber, string i_secondNumber, string i_thirdNumber)
        {
            int firstNumber = int.Parse(i_firstNumber);
            int secondNumber = int.Parse(i_secondNumber);
            int thirdNumber = int.Parse(i_thirdNumber);
            int countOfDigitZero = 0;
            int countOfDigitOne = 0;

            for(int i =0; i < i_firstNumber.Length; i++)
            {
                if ((firstNumber / 10) % 10 == 0)
                {
                    countOfDigitZero++;
                }
                else
                {
                    countOfDigitOne++;
                } 
                if ((secondNumber / 10) % 10 == 0)
                {
                    countOfDigitZero++;
                }
                else
                {
                    countOfDigitOne++;
                }
                if ((thirdNumber / 10) % 10 == 0)
                {
                    countOfDigitZero++;
                }
                else
                {
                    countOfDigitOne++;
                }
            }
            float avgOfDigitZero = (float)countOfDigitZero / 3;
            float avgOfDigitOne = (float)countOfDigitOne / 3;
            string outputMsg = $"The average occurrences of number 1: {avgOfDigitOne} \nThe average occurrences of number 0: {avgOfDigitZero}\n";
            Console.WriteLine(outputMsg);
        }
        // $G$ CSS-999 (-0) Private methods should start with a lowercase letter.
        // $G$ CSS-006 (-0) Missing blank line, after "if / else" blocks.
        // $G$ DSN-004 (-0) Unnecessary code duplication
        private static void PrintAcendingNumbers(string i_firstNumber, string i_secondNumber, string i_thirdNumber)
        {
            int countAcendingNumbers = 0;
            int firstNumberConverted = ConvertBinaryToDecimal(i_firstNumber);
            int secondNumberConverted = ConvertBinaryToDecimal(i_secondNumber);
            int thirdNumberConverted = ConvertBinaryToDecimal(i_thirdNumber);

            if(IsNumberAcending(firstNumberConverted) == true)
            {
                countAcendingNumbers++;
            }
            if (IsNumberAcending(secondNumberConverted) == true)
            {
                countAcendingNumbers++;
            }
            if (IsNumberAcending(thirdNumberConverted) == true)
            {
                countAcendingNumbers++;
            }
            // $G$ NTT-999 (-0) You should have used Environment.NewLine instead of "\n".

            Console.WriteLine($"The number of acending numbers is: {countAcendingNumbers}\n");
        }
        // $G$ CSS-999 (-0) Private methods should start with a lowercase letter.
        // $G$ CSS-999 (-0) Missing blank line, after local variable.

        private static int ConvertBinaryToDecimal(string i_number)
        {
            int decimalNumber = 0;
            for(int i = 0; i < i_number.Length; i++)
            {
                char digit = i_number[i];
                decimalNumber = (decimalNumber << 1) | (digit - '0');
            }
            return decimalNumber;
        }
        // $G$ CSS-028 (-0) A method should not include more than one return statement.

        private static bool IsNumberAcending(int i_number)
        {
            string numberStr = i_number.ToString();
            
            for(int i = 0; i < numberStr.Length - 1; i++)
            {
                if(numberStr[i] >= numberStr[i + 1])
                {
                    return false;
                }
            }
            return true; 
        }
        // $G$ CSS-999 (-0) Private methods should start with a lowercase letter.
        // $G$ CSS-027 (-2) Unnecessary blank line.
        // $G$ NTT-999 (-0) You should have used verbatim string(@)

        private static void PrintTheBiggestAndSmallestNumbers(string i_firstNumber, string i_secondNumber, string i_thirdNumber)
        {
            int decimalFirstNumber = ConvertBinaryToDecimal(i_firstNumber);
            int decimalSecondNumber = ConvertBinaryToDecimal(i_secondNumber);
            int decimalThirdNumber = ConvertBinaryToDecimal(i_thirdNumber);

            int biggestNumber = Math.Max(Math.Max(decimalFirstNumber, decimalSecondNumber), decimalThirdNumber);
            int smallestNumber = Math.Min(Math.Min(decimalFirstNumber, decimalSecondNumber), decimalThirdNumber);

            Console.WriteLine($"The Biggest number is: {biggestNumber}\nThe Smallest number is: {smallestNumber}\n");
        }
    }
}
