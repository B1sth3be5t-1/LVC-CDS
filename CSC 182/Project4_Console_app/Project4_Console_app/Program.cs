using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project4_Console_app
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Person p1 = new Person("Brian", "Myers");
            Person p2 = new Person("Benjamin", "Miller");
            Person p3 = new Person("Hannah", "Michael");
            Person p4 = new Person("Harvard", "RandomLastNameHere");
            Person p5 = new Person("IDK", "Anymore");
            Person p6 = new Person("Ivan", "Alspaugh");

            List<Person> people = new List<Person>();
            people.Add(p1);
            people.Add(p2);
            people.Add(p3);
            people.Add(p4);
            people.Add(p5);
            people.Add(p6);


            var groups = people.AsEnumerable()
                .GroupBy(p => p.getInits())
                .Where(g => g.Count() >= 2)
                .Select(x => x);

            foreach (var group in groups)
            {
                Console.WriteLine(group.Key);
                foreach (var person in group.ToList())
                {
                    Console.WriteLine("\t" + person.ToString());
                }
            }


            Console.WriteLine("\n\n--------------------------POKER TIME--------------------------\n\n");



            Random rand = new Random();
            string[] suits = { "Hearts", "Diamonds", "Clubs", "Spades" };

            List<List<PlayingCard>> pokerHands = new List<List<PlayingCard>>();

            int numberOfHands = 10000;

            for (int j = 0; j < numberOfHands; j++)
            {
                List<PlayingCard> PokerHand1 = new List<PlayingCard>();
                while (PokerHand1.Count() < 5)
                {
                    int value = rand.Next(1, 14); // Random value between 1 and 13 (inclusive)
                    int suitIndex = rand.Next(0, 4); // Random suit index
                    string suit = suits[suitIndex];
                    PlayingCard newCard = new PlayingCard(value, suit);
                    bool inHand = false;
                    foreach (var card in PokerHand1)
                    {
                        if (card == newCard)
                        {
                            inHand = true;
                            break;
                        }
                    }

                    if (!inHand) PokerHand1.Add(newCard);
                }

                pokerHands.Add(PokerHand1);
            }


            var fullHouseHands =
                from hand in pokerHands
                let firstCard = hand.ElementAt(0)
                let firstCardRankCount =
                    (hand.AsEnumerable()
                        .Where(c => c.value == firstCard.value)
                        .Select(c => c).Count())
                let sub_hand =
                    (hand.AsEnumerable()
                        .Where(c => c.value != firstCard.value)
                        .Select(c => c)).ToList()
                let secondCard = sub_hand.ElementAt(0)
                let secondCardRankCount =
                    (sub_hand.AsEnumerable()
                        .Where(c => c.value == secondCard.value)
                        .Select(c => c).Count())
                where (firstCardRankCount == 2 && secondCardRankCount == 3) || (firstCardRankCount == 3 && secondCardRankCount == 2)
                select hand;


            foreach (List<PlayingCard> hand in fullHouseHands)
            {
                Console.WriteLine("Full House Hand: ");
                foreach (var card in hand)
                {
                    Console.WriteLine("\t" + card);
                }
            }
        }
    }
}
