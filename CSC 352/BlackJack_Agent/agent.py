class BlackJackAgentTerrible:

    def __init__(self):
        Q = {((0, 2, 0), "hit"): 0, ((0, 2, 0), "hold"): 0,
             ((0, 3, 0), "hit"): 0, ((0, 3, 0), "hold"): 0, }  # etc
        N_sa = {}
        s = None
        a = None

    def decide_action(self, percept):
        player_total, dealer_card, num_aces = percept

        s = (player_total, dealer_card, num_aces)
        if player_total <= 18:
            a = "hit"
        else:
            a = "hold"
        return a
