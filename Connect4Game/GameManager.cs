using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using Ex02.ConsoleUtils;

namespace A24_Ex02_Eran_203606736_Matan_208389999
{
    enum PlayerType
    {
        Computer,
        Human,
    }
    class CleanGameManager
    {
        private GameBoard m_GameBoard;
        private GamePlayer m_CurrentPlayer;
        private GamePlayer m_PlayerA = new GamePlayer(PlayerType.Human, "Player A", PlayerSign.O);
        private GamePlayer m_PlayerB;
        private short m_Round = 1;
        private readonly Logic m_Logic;
        private readonly UI m_UI;

        public CleanGameManager(Logic i_Logic, UI i_UI)
        {
            this.m_Logic = i_Logic;
            this.m_UI = i_UI;
        }

        public void StartGame() {
            short rows = 0;
            short cols = 0;
            bool endGame = false;

            m_UI.WelcomeMessage();
            m_Logic.SetPlayerB(m_UI.GetUserInputSelectionPlayer(), ref m_PlayerB);
            m_UI.GetColsAndRowsFromUser(ref rows, ref cols);
            m_Logic.CreateGameBoard(ref m_GameBoard, rows, cols);
            m_UI.PrintBoard(m_GameBoard);
            m_CurrentPlayer = m_PlayerA;

            while (!endGame)
            {
                while (true)
                {
                    string columnChoice = "";
                    columnChoice = m_UI.GetPlayerColumnChoice(m_CurrentPlayer, m_GameBoard.Cols);
                    if (columnChoice.ToLower() == "q")
                    {
                        m_UI.PrintMessage("You have quite the game");
                        m_Logic.UpdatePlayerScore(ref m_CurrentPlayer);
                        m_UI.PrintTableScore(m_PlayerA, m_PlayerB);
                        break;
                    }
                    while (m_Logic.IsColumnInBoardRange(columnChoice, m_GameBoard.Cols) != true)
                    {
                        m_UI.PrintMessage($"Input Error!\nYou must choose column between {1} - {m_GameBoard.Cols}");
                        columnChoice = m_UI.GetPlayerColumnChoice(m_CurrentPlayer, m_GameBoard.Cols);
                    }
                    while (m_Logic.IsColumnFull(columnChoice, m_GameBoard) != false)
                    {
                        m_UI.PrintMessage("This column is full, please choose other one");
                        columnChoice = m_UI.GetPlayerColumnChoice(m_CurrentPlayer, m_GameBoard.Cols);
                    }
                    m_Logic.SetSelectionOnBoardColumn(columnChoice, ref m_GameBoard, m_CurrentPlayer);
                    Screen.Clear();

                    m_UI.PrintBoard(m_GameBoard);

                    if(m_Round >= 7)
                    {
                        if(m_Logic.CheckForWin(m_GameBoard) == true)
                        {
                            m_UI.PrintMessage($"### {m_CurrentPlayer.Name} WINS! ###");
                            m_Logic.UpdatePlayerScore(ref m_CurrentPlayer);
                            m_UI.PrintTableScore(m_PlayerA, m_PlayerB);

                            if(m_UI.Rematch() == true)
                            {
                                InitializeGame(rows,cols);
                                break;
                            }
                            else
                            {
                                endGame = true;
                                break;
                            }
                        }
                    }
                    m_Round++;
                    m_CurrentPlayer = m_Logic.ChangeTurn(m_CurrentPlayer, m_PlayerA, m_PlayerB);
                }
            }
            m_UI.PrintMessage("ByeBye");
            Thread.Sleep(3000);
        }

        private void InitializeGame(short i_Rows, short i_Cols) {
            m_Logic.CreateGameBoard(ref m_GameBoard, i_Rows, i_Cols);
            m_UI.PrintBoard(m_GameBoard);
            m_CurrentPlayer = m_PlayerA;
            m_Round = 1;
            Screen.Clear();
            m_UI.PrintBoard(m_GameBoard);
        }
    }
}
