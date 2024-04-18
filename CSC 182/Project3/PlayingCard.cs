using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection.Metadata.Ecma335;
using System.Text;
using System.Threading.Tasks;

namespace Project3
{
    class PlayingCard
    {
        public required string suit { get; set; }
        public required int value { get; set; }



        public override string ToString() 
        {
            string val = "";
            if (value == 1) val = "Ace";
            else if (value == 11) val = "Jack";
            else if (value == 12) val = "Queen";
            else if (value == 13) val = "King";
            else val = value.ToString();
            return "The " +  val + " of " + this.suit + "s";
        }


        public static int operator +(PlayingCard a, PlayingCard b)
            => a.value + b.value;
    }
}
