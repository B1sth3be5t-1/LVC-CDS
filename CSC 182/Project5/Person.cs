using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project5
{

    public delegate bool FilterDelegate(Person p);

    public class Person
    {

        public string name { get; set; }

        public int age { get; set; }

        public Person(string s, int i)
        {
            name = s;
            age = i;
        }


        public override string ToString()
        {
            return name + " is " + age + " years old.";
        }

        public static void DisplayPeople(Person[] people, FilterDelegate filter)
        {
            foreach (Person p in people)
            {
                if (filter(p))
                {
                    Console.WriteLine(p.ToString());
                }
            }
        }
    }
}
