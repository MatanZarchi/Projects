using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ex01_04
{
    class Program
    {
        // $G$ DSN-999 (-0) The Main method should only be an access point to the program. Should look something like:
        // public static void Main() { new UI().Run(); }
        public static void Main()
        {
            string userInput = GetUserInput();
            PrintIsTextPalindrome(userInput);
            IsInputNumberOrText(userInput);
            System.Console.WriteLine("\nTo exit please press Enter");
            System.Console.ReadLine();
        }
        // $G$ CSS-999 (-0) Private methods should start with a lowercase letter.

        private static string GetUserInput()
        {
            bool isInputCorrectFlag = false;
            string userInput = "";
            Console.WriteLine("Please enter a string of 8 characters.\nIt must be numbers or english characters!");
            while(!isInputCorrectFlag == true)
            {
                userInput = Console.ReadLine();
                if(CheckUserInput(userInput) == true)
                {
                    isInputCorrectFlag = true; 
                }
            }
            return userInput;
        }
        // $G$ CSS-028 (-0) A method should not include more than one return statement.
        // $G$ NTT-999 (-0) You should have used Environment.NewLine instead of "\n".

        private static bool CheckUserInput(string i_userInput)
        {
            if(i_userInput.Length != 8)
            {
                Console.WriteLine("Error!\nInput must be exact 8 characters");
                return false;
            }

            bool isWordCorrect = IsOnlyNumberOrEnglish(i_userInput);
            if(isWordCorrect == true)
            {
                return true;
            }
            else
            {
                Console.WriteLine("Error!\nInput must be number or english characters");
                return false;
            }
        }
        // $G$ CSS-999 (-0) Private methods should start with a lowercase letter.
        // $G$ CSS-028 (-0) A method should not include more than one return statement.

        private static bool IsOnlyNumberOrEnglish(string i_text)
        {
            bool hasEnglishCharacters = false;
            bool hasNumbers = false;

            for (int i = 0; i < i_text.Length; i++)
            {
                char c = i_text[i];

                if (char.IsDigit(c))
                {
                    hasNumbers = true;
                }
                else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
                {
                    hasEnglishCharacters = true;
                }

                if (hasNumbers && hasEnglishCharacters)
                {
                    return false;
                }
            }
            return hasNumbers || hasEnglishCharacters;
        }
        // $G$ CSS-999 (-0) Private methods should start with a lowercase letter.

        private static void PrintIsTextPalindrome(string i_text) 
        {
            bool isTextPalindrome = IsPalindromeRecursive(i_text, 0, i_text.Length - 1);
            if(isTextPalindrome == true)
            {
                Console.WriteLine($"{i_text} is Palindrome!");
            }
            else
            {
                Console.WriteLine($"{i_text} is NOT Palindrome!");
            }
        }
        // $G$ CSS-028 (-0) A method should not include more than one return statement.

        private static bool IsPalindromeRecursive(string i_text, int i_startIndex, int i_endIndex)
        {
            if (i_startIndex >= i_endIndex)
            {
                return true;
            }

            if (i_text[i_startIndex] != i_text[i_endIndex])
            {
                return false;
            }

            return IsPalindromeRecursive(i_text, i_startIndex + 1, i_endIndex - 1);
        }

        private static void IsInputNumberOrText(string i_userInput)
        {
            int userInputInteger;
            bool successToConvert = int.TryParse(i_userInput, out userInputInteger);
            if (successToConvert == true)
            {
                IsNumberDivideByFive(userInputInteger);
            }
            else
            {
                CountLowerCaseLetters(i_userInput);
            }
        }
        private static void IsNumberDivideByFive(int i_number)
        {
            if(i_number % 5 == 0)
            {
                Console.WriteLine("The number is divisible by five without a remainder");
            }
            else
            {
                Console.WriteLine("The number is NOT divisible by five without a remainder");
            }
        }
        // $G$ CSS-999 (-0) Private methods should start with a lowercase letter.

        private static void CountLowerCaseLetters(string i_text)
        {
            int count = 0;

            for (int i = 0; i < i_text.Length; i++)
            {
                char c = i_text[i];

                if (char.IsLower(c))
                {
                    count++;
                }
            }

            Console.WriteLine($"The text has {count} lower letters"); 
        }

    }

}
