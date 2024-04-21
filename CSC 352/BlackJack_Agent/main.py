from deck import Deck
from card import Card
from agent import BlackJackAgentTerrible
from environment import BlackjackEnvironment


# Example usage:
env = BlackjackEnvironment()
agent = BlackJackAgentTerrible()
percept = env.get_percept()
print("Percept:", percept)
action = agent.decide_action(percept)
print("Action chosen by agent:", action)
reward, done = env.step(action)
print("Reward:", reward)
print("Game over?", done)
