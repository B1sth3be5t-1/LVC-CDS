using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project5
{

    class DataAnalysis
    {
        public static double get_min(double[] inp)
        {
            return inp.Min();
        }

        public static double get_max(double[] inp)
        {
            return inp.Max();
        }

        public static double get_med(double[] inp)
        {
            if (inp.Length == 0) return 0;

            Array.Sort(inp);
            if (inp.Length % 2 == 0)
            {
                double a = inp[inp.Length / 2];
                double b = inp[(inp.Length / 2) - 1];

                return a * 1.0 + b / 2;
            }
            else
            {
                return inp[(inp.Length - 1) / 2];
            }
        }


        public static double get_mean(double[] inp)
        {
            return inp.Average();
        }

        public static double get_stddev(double[] inp)
        {
            double avg = inp.Average();
            return Math.Sqrt(inp.Average(v => Math.Pow(v - avg, 2)));
        }

    }
}
