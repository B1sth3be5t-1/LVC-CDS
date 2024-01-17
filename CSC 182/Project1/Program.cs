using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project1
{
    internal class Program
    {
  
        static void Main(string[] args)
        {

            List<string> names = new List<string> { "Sophia", "Nicolas", "Zahirah", "Jeong" };

            List<int> Sophia = new List<int> {93,87,98,95,100};
            List<int> Nicolas = new List<int> { 80, 83, 82, 88, 85 };
            List<int> Zahirah = new List<int> { 84, 96, 73, 85, 79 };
            List<int> Jeong = new List<int> { 90, 92, 98, 100, 97 };

            List<List<int>> students = new List<List<int>> { Sophia, Nicolas, Zahirah, Jeong };

            List<int> studentSums = new List<int> { 0, 0, 0, 0};

            for (int i = 0; i < studentSums.Count; i++) 
            { 
                foreach (int j in students[i])
                {
                    studentSums[i] += j;
                }
            }

            List<decimal> studentAverages = new List<decimal> { 0, 0, 0, 0 };

            for (int i = 0; i < studentAverages.Count;i++)
            {
                studentAverages[i] = (decimal) studentSums[i] / students[i].Count;
            }

            string getLetter(decimal d)
            {
                if (d >= 97 && d <= 100) return "A+";
                else if (d >= 93) return "A";
                else if (d >= 90) return "A-";
                else if (d >= 87) return "B+";
                else return "B";
            }

            Console.WriteLine("Student\t\tGrade\tLetter\n");

            for (int i = 0; i < studentAverages.Count; i++)
            {
                Console.WriteLine($"{names[i]}:{((i == 0 || i == 3) ? "\t\t" : "\t")} {studentAverages[i]}\t{getLetter(studentAverages[i])}");
            }




            Console.WriteLine("\n\n-------------------- Problem 2 below ---------------------\n\n");

            //problem 2
            Console.WriteLine($"Apple is an alphabetical order word: {isWordAlpha("Apple")}");
            Console.WriteLine($"Biopsy is an alphabetical order word: {isWordAlpha("biopsy")}");
            Console.WriteLine($"Lost is an alphabetical order word: {isWordAlpha("Lost")}");
            Console.WriteLine($"Chintz is an alphabetical order word: {isWordAlpha("Chintz")}");
            Console.WriteLine($"\"\" is an alphabetical order word: {isWordAlpha("")}");
            Console.ReadLine();
        }


        // PROBLEM 2 ----------------

        static bool isWordAlpha(string word)
        {
            word = word.ToLower();

            for (int i = 0; i < word.Length - 1; i++)
            {
                if (word[i] > word[i + 1]) return false;
            }


            return true;
        }
    }
}
