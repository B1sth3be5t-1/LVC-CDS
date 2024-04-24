using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project4_Console_app
{
    class Person
    {
        public string first_name { get; set; }
        public string last_name { get; set; }

        public Person(string f, string l)
        {
            first_name = f;
            last_name = l; 
        }

        public override string ToString()
        {
            return "This person is: " + first_name + " " + last_name;
        }

        public string getInits()
        {
            return first_name.Substring(0,1).ToUpper() + last_name.Substring(0,1).ToUpper();
        }
    }
}
