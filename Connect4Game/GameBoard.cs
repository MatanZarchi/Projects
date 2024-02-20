using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A24_Ex02_Eran_203606736_Matan_208389999
{
    class GameBoard
    {
        private short m_Rows;
        private short m_Cols;
        private short[,] m_Board;
        
        public GameBoard()
        {

        }

        public GameBoard(short i_Rows, short i_Cols)
        {
            this.m_Rows = i_Rows;
            this.m_Cols = i_Cols;
            InitBoard();
        }

        public short Rows
        {
            get { return m_Rows; }
            set { m_Rows = value; }
        }
        public short Cols
        {
            get { return m_Cols; }
            set { m_Cols = value; }
        }

        public short[,] Board
        {
            get { return m_Board; }
            set { m_Board = value; }
        }

        public void PrintBoard()
        {
            string underLine = "=========";
            for (int index = 1; index <= m_Cols; index++)
            {
                Console.Write($" {index}");
            }
            Console.WriteLine();
            for (short i = 0; i < Rows; i++)
            {
                Console.Write("|");
                for (short j = 0; j < m_Cols; j++)
                {
                    if(m_Board[i,j] == 0)
                    {
                        Console.Write("X");
                    }
                    else if(m_Board[i, j] == 1)
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
                if (m_Cols > 4)
                {
                    int _Columns = m_Cols - 4;
                    while (_Columns > 0)
                    {

                        underLinesCounter += "==";
                        _Columns--;
                    }
                }
                Console.WriteLine(underLinesCounter + underLine);
            }
        }

        private void InitBoard()
        {
            m_Board = new short[m_Rows, m_Cols];
            for (int i = 0; i < m_Rows; i++)
            {
                for (int j = 0; j < m_Cols; j++)
                {
                   m_Board[i, j] = -1;
                }
            }
        }
    }
}
