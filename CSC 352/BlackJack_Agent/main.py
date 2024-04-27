from deck import Deck
from card import Card
from agent import BlackJackAgentTerrible, BlackJackAgentLearned
from environment import BlackjackEnvironment

agent = BlackJackAgentLearned()
for _ in range(1000000):
    env = BlackjackEnvironment()
    res = env.run_game(agent)

print(agent.Q)