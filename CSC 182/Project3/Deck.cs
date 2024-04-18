using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Project3;


namespace Project3
{
    class Deck<T>
    {

        public T[] cards { get; set; }

        public T this[int i]
        {
            get => cards[i];
            set => cards[i] = value;
        }

        public Deck(T[] cards)
        {
            this.cards = cards;
        }

        public override string ToString() {
            string outp = "";
            foreach (var card in cards)
            {
                outp += card.ToString() + "\n";
            }

            return outp;
        
        }

        public void shuffle()
        {
            T[] newCards = new T[cards.Length];
            
            List<T> cList = cards.ToList();

            Random rnd = new Random();
            for (int i = 0; i < 52; i++) {
                int index = rnd.Next(52 - i);
                newCards[i] = cList[index];
                cList.RemoveAt(index);
            }

            cards = newCards;
        }


    }
}
