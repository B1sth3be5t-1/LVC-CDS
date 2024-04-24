class BlackJackAgentTerrible:

    def __init__(self):
        self.Q = {((0, 2, 0), "hit"): 0, ((0, 2, 0), "hold"): 0,
                  ((0, 3, 0), "hit"): 0, ((0, 3, 0), "hold"): 0, }  # etc
        self.N_sa = {}
        self.s = {'player_total': 0, 'has_ace': False,
                  'dealer_card': 0, 'state_of_game': 'continue',
                  'reward': 0}
        self.a = None

        # todo in other class: stuff with rewards and updating

    def show_percept(self):
        print(self.s)

    def decide_action(self, percept):
        player_total, has_ace, dealer_card, state_of_game, reward = percept

        self.s = {'player_total': player_total, 'has_ace': has_ace,
                  'dealer_card': dealer_card, 'state_of_game': state_of_game,
                  'reward': reward}
        if self.s['player_total'] <= 18:
            self.a = "hit"
        elif self.s['state_of_game'] not in ['win', 'lose']:
            self.a = "hold"
        else:
            self.a = None
        return self.a


class BlackJackAgentLearned:
    def __init__(self):
        self.Q = {}

# a' = argmax of a' (Q(s', a')) with probability p, do other action with probability 1-p
