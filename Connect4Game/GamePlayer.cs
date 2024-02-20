using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A24_Ex02_Eran_203606736_Matan_208389999
{
    enum PlayerSign
    {
        X,
        O
    }
    class GamePlayer
    {
        private PlayerType m_PlayerType;
        private PlayerSign m_Sign;
        private string m_Name;
        private short m_Score;

        public GamePlayer(PlayerType i_PlayerType, string i_Name, PlayerSign i_PlayerSign)
        {
            this.m_PlayerType = i_PlayerType;
            this.m_Name = i_Name;
            this.m_Sign = i_PlayerSign;
        }

        public PlayerType Player
        {
            get { return m_PlayerType; }
            set { m_PlayerType = value; }
        }

        public string Name
        {
            get { return m_Name; }
            set { m_Name = value; }
        }

        public short Score
        {
            get { return m_Score; }
            set { m_Score = value; }
        }

        public PlayerSign Sign
        {
            get { return m_Sign; }
        }

        public string GetPlayerColumnChoice()
        {
            string columnChoice = "";
            bool isUserInputValid = false;
            if (this.m_PlayerType == PlayerType.Human)
            {
                Console.WriteLine("Choose the column you want to insert");
                columnChoice = Console.ReadLine();
                while (!isUserInputValid)
                {
                    if(columnChoice.ToLower() == "q")
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
    }
}
