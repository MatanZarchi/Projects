using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace A24_Ex02_Eran_203606736_Matan_208389999
{
    class UI
    {
        public void WelcomeMessage()
        {
            Console.WriteLine("Welcome to CONNECT FOUR game!");
        }
        public PlayerType GetUserInputSelectionPlayer()
        {
            Console.WriteLine("Please choose who do you want to play with. Press:\n" +
                "1. Computer\n" +
                "2. Friend");
            string userInputPlayerSelection = "";
            bool isUserInputValid = false;
            while (!isUserInputValid)
            {
                userInputPlayerSelection = Console.ReadLine();
                if (PlayerSelectionValidation(userInputPlayerSelection) == true)
                {
                    isUserInputValid = true;
                }
                else
                {
                    Console.WriteLine("You have entered wrong input.\nYou must enter a number 1 or 2");
                }
            }
            return int.Parse(userInputPlayerSelection) == 1 ? PlayerType.Computer : PlayerType.Human;
        }

        private bool PlayerSelectionValidation(string i_UserInput)
        {
            int parsedUserInput = 0;
            bool isParseSuccess = int.TryParse(i_UserInput, out parsedUserInput);
            if ((parsedUserInput == 1 || parsedUserInput == 2) && (isParseSuccess == true))
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public bool Rematch()
        {
            Console.WriteLine("Do you want to play again?\nPress Y to play again\nPress N to quite");
            bool correctInput = false;
            bool userChoice = false;
            string userInput;
            while (!correctInput)
            {
                userInput = Console.ReadLine();
                if (userInput.ToLower() == "y")
                {
                    correctInput = true;
                    userChoice = true;
                }
                else if (userInput.ToLower() == "n")
                {
                    correctInput = true;
                    userChoice = false;
                }
                else
                {
                    Console.WriteLine("Wrong Input!\nPlease enter Y or N");
                }
            }
            return userChoice;
        }

        public void PrintBoard(GameBoard i_Board)
        {
            string underLine = "=========";
            for (int index = 1; index <= i_Board.Cols; index++)
            {
                Console.Write($" {index}");
            }
            Console.WriteLine();
            for (short i = 0; i < i_Board.Rows; i++)
            {
                Console.Write("|");
                for (short j = 0; j < i_Board.Cols; j++)
                {
                    if (i_Board.Board[i, j] == 0)
                    {
                        Console.Write("X");
                    }
                    else if (i_Board.Board[i, j] == 1)
                    {
                        Console.Write("O");
                    }
                    else
                    {
                        Console.Write(" ");
                    }
                    Console.Write("|");
                }
                Console.WriteLine();
                string underLinesCounter = "";
                if (i_Board.Cols > 4)
                {
                    int _Columns = i_Board.Cols - 4;
                    while (_Columns > 0)
                    {

                        underLinesCounter += "==";
                        _Columns--;
                    }
                }
                Console.WriteLine(underLinesCounter + underLine);
            }
        }

        public void GetColsAndRowsFromUser(ref short i_Rows, ref short i_Cols)
        {
            string userInputRows = "";
            string userInputCols = "";
            bool isRowsInputValid = false;
            bool isColsInputValid = false;

            Console.WriteLine("Enter the number of rows for the matrix, must be between 4 to 8");
            while (!isRowsInputValid == true)
            {
                userInputRows = Console.ReadLine();
                if (IsMatrixInputValid(userInputRows) == true)
                {
                    isRowsInputValid = true;
                }
                else
                {
                    Console.WriteLine("Wrong input!\nRows must be between 4 - 8!");
                }
            }

            Console.WriteLine("Enter the number of columns for the board, must be between 4 to 8");

            while (!isColsInputValid == true)
            {
                userInputCols = Console.ReadLine();
                if (IsMatrixInputValid(userInputCols) == true)
                {
                    isColsInputValid = true;
                }
                else
                {
                    Console.WriteLine($"Wrong input!\nColumns must be between 4 - 8!");
                }
            }

            i_Rows = short.Parse(userInputRows);
            i_Cols = short.Parse(userInputCols);
            Console.WriteLine($"Excellent choice! Board size {userInputRows}x{userInputCols}");
        }

        private bool IsMatrixInputValid(string i_UserInput)
        {
            int parsedUserInput = 0;
            bool isParseSuccess = int.TryParse(i_UserInput, out parsedUserInput);
            if ((parsedUserInput >= 4 && parsedUserInput <= 8) && (isParseSuccess == true))
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public string GetPlayerColumnChoice(GamePlayer i_Player, short i_BoardCols)
        {
            string columnChoice = "";
            bool isUserInputValid = false;
            if (i_Player.Player == PlayerType.Human)
            {
                Console.WriteLine("Choose the column you want to insert");
                columnChoice = Console.ReadLine();
                while (!isUserInputValid)
                {
                    if (columnChoice.ToLower() == "q")
                    {
                        return columnChoice;
                    }
                    if (CheckInputValidation(columnChoice) == true)
                    {
                        isUserInputValid = true;
                    }
                    else
                    {
                        Console.WriteLine("Invalid input!\nYou must chose only numbers!");
                        columnChoice = Console.ReadLine();
                    }
                }
            }
            else
            {
                Thread.Sleep(1200);
                Random random = new Random();
                columnChoice = random.Next(1, i_BoardCols - 1).ToString();
            }
            return columnChoice;
        }
        private bool CheckInputValidation(string i_UserInput)
        {
            int parsedUserInput = 0;
            bool isParseSuccess = int.TryParse(i_UserInput, out parsedUserInput);
            if (isParseSuccess == true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public int ComputerDrop(GameBoard i_Board, GamePlayer i_Player) //by random.
        {
            Random random = new Random();
            int randDropChoice = random.Next(0, i_Board.Cols - 1);

            return randDropChoice;
        }

        public void PrintMessage(string i_InputErrorMsg)
        {
            Console.WriteLine(i_InputErrorMsg);
        }

        public void PrintTableScore(GamePlayer i_PlayerA, GamePlayer i_PlayerB)
        {
            string underLinesCounter = "";
            if (i_PlayerA.Score > 9 || i_PlayerB.Score > 9)
            {
                underLinesCounter += "==";
            }
            Console.WriteLine(" =======================================" + underLinesCounter);
            Console.WriteLine($" | Score PlayerA: {i_PlayerA.Score} | Score PlayerB: {i_PlayerB.Score} |");
            Console.WriteLine(" =======================================" + underLinesCounter);
            }
        }
}
