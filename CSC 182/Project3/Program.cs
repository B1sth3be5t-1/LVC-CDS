using Project3;

PlayingCard test1 = new PlayingCard() { value = 1, suit = "Spade" };
PlayingCard test2 = new PlayingCard() { value = 2, suit = "Club" };
PlayingCard test3 = new PlayingCard() { value = 11, suit = "Heart" };

//toString test for playing cards
Console.WriteLine(test1.ToString());
Console.WriteLine(test2.ToString());

//getter test for playing card
string card3Suit = test3.suit;
int card3Value = test3.value;

Console.WriteLine(card3Suit);
Console.WriteLine(card3Value);

//adding test
Console.WriteLine(test1 + test2);

//creating a deck of playing cards
PlayingCard[] c = new PlayingCard[52];

int count = 0;
for (int i = 0; i < 4; i++)
{
    for (int j = 1; j <= 13; j++)
    {
        string suit = "";
        if (i == 0) suit = "Spade";
        else if (i == 1) suit = "Club";
        else if (i == 2) suit = "Diamond";
        else suit = "Heart";

        c[count++] = new() { suit = suit, value = j }; ;
    }
}

Deck<PlayingCard> deck = new Deck<PlayingCard>(c);

Console.WriteLine("--------------DECK TESTING-------------");
Console.WriteLine(deck.ToString());
Console.WriteLine("--------------AFTER SHUFFLE------------");
deck.shuffle();
Console.WriteLine(deck.ToString());
Console.WriteLine("--------------Get first two cards and add them------------");
PlayingCard card = deck[0];
PlayingCard card2 = deck[1];
Console.WriteLine(card.ToString());
Console.WriteLine(card2.ToString());
Console.WriteLine(card + card2);

Console.WriteLine("--------------Test getter for deck------------");
PlayingCard[] returnList = deck.cards;
Console.WriteLine(returnList.Length);

Console.WriteLine("--------------Test setter for deck------------");
deck.cards = c;
PlayingCard[] standardDeck = deck.cards;
Console.WriteLine(standardDeck[0].ToString());
Console.WriteLine(standardDeck[1].ToString());
Console.WriteLine(standardDeck[2].ToString());


Console.ReadLine();