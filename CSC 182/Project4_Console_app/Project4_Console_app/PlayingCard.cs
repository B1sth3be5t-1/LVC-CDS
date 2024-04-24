using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project4_Console_app
{
    class PlayingCard
    {
        public string suit { get; set; }
        public int value { get; set; }



        public override string ToString()
        {
            string val = "";
            if (value == 1) val = "Ace";
            else if (value == 11) val = "Jack";
            else if (value == 12) val = "Queen";
            else if (value == 13) val = "King";
            else val = value.ToString();
            return "The " + val + " of " + this.suit;
        }

        public PlayingCard(int val, string s)
        {
            this.suit = s;
            this.value = val;
        }


        public static int operator +(PlayingCard a, PlayingCard b)
            => a.value + b.value;

        public static bool operator ==(PlayingCard a, PlayingCard b) => (a.value == b.value && a.suit == b.suit);

        public static bool operator !=(PlayingCard a, PlayingCard b) => !(a.value == b.value && a.suit == b.suit);
    }
}
