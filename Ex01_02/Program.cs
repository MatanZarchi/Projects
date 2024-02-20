using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
// $G$ NTT-006 (-5) You should have used StringBuilder here.

namespace Ex01_02
{
   public class Program
    {
        // $G$ NTT-999 (-0) You should have used Environment.NewLine instead of "\n".

        public static void Main() {
            PrintRecursiveRhombus(7);
            Console.ReadLine();
            Console.WriteLine("\nTo exit please press Enter");
        }

        public static void PrintRecursiveRhombus(int i_starts) {
            PrintUpperRhombus(i_starts);
            PrintBottomRhombus(i_starts - 1);
        }
        // $G$ CSS-999 (-0) Private methods should start with a lowercase letter.

        private static void PrintUpperRhombus(int i_stars, int i_rows = 1)
        {
            if(i_rows > i_stars)
            {
                return;
            }
            PrintSpaces(i_stars - i_rows);
            PrintStars(i_rows);
            Console.WriteLine();

            PrintUpperRhombus(i_stars, i_rows + 1);
        }
        // $G$ CSS-999 (-0) Private methods should start with a lowercase letter.
        // $G$ CSS-027 (-0) Unnecessary blank line

        private static void PrintBottomRhombus(int i_stars, int i_rows = 1)
        {
            if(i_rows > i_stars)
            {
                return;
            }

            PrintSpaces(i_rows);
            PrintStars(i_stars - i_rows + 1);
            Console.WriteLine();

            PrintBottomRhombus(i_stars, i_rows + 1);
        }
        // $G$ NTT-999 (-0) You should have used Environment.NewLine instead of "\n".

        private static void PrintStars(int i_starts)
        {
            for(int i = 0; i < i_starts; i++)
            {
                Console.Write("* ");
            }
            Console.Write("\n");
        }

        private static void PrintSpaces(int i_spaces)
        {
            for (int i = 0; i < i_spaces; i++)
            {
                Console.Write(" ");
            }
        }
    }
}
