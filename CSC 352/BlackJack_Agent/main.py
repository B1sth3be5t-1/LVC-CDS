from deck import Deck
from card import Card
from agent import BlackJackAgentTerrible
from environment import BlackjackEnvironment

for _ in range(20):
    env = BlackjackEnvironment()
    agent = BlackJackAgentTerrible()
    res = env.run_game(agent)
    print(res)
    agent.show_percept()
    print()
