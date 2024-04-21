from deck import Deck

class BlackjackEnvironment:
    def __init__(self):
        self.deck = Deck()
        self.player_hand = []
        self.dealer_hand = []
        self.reset()

    def reset(self):
        self.deck.shuffle()
        self.player_hand = [self.deck.draw(), self.deck.draw()]
        self.dealer_hand = [self.deck.draw()]

    def get_percept(self):
        return get_hand_value(self.player_hand), get_hand_value(self.dealer_hand), sum(1 for card in self.player_hand if card.rank == "Ace")

    def step(self, action):
        if action == 'hit':
            self.player_hand.append(self.deck.draw())
            player_total = get_hand_value(self.player_hand)
            if player_total > 21:
                return -1, True  # Player busted
            else:
                return 0, False  # Player didn't bust
        elif action == 'hold':
            while get_hand_value(self.dealer_hand) < 17:
                self.dealer_hand.append(self.deck.draw())
            dealer_total = get_hand_value(self.dealer_hand)
            player_total = get_hand_value(self.player_hand)
            if dealer_total > 21 or dealer_total < player_total:
                return 1, True  # Player wins
            elif dealer_total > player_total:
                return -1, True  # Dealer wins
            else:
                return 0, True  # Tie


def get_hand_value(hand):
    num_aces = sum(1 for card in hand if card.rank == "Ace")
    s = 0
    if num_aces > 1:
        s += 11 + num_aces - 1

    for card in hand:
        if card.rank in ['Jack', 'Queen', 'King']:
            s += 10
        elif card.rank == "Ace":
            s += 0
        else:
            s += int(card.rank)

    return s

