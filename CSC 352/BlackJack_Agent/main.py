from agent import *
from environment import BlackjackEnvironment

agent = BlackJackAgentLearned()
agent.loadQ()
wins = 0
num_episodes = 100
for _ in range(num_episodes):
    env = BlackjackEnvironment()
    res = env.run_game(agent)
    if res == 1:
        wins += 1

agent.saveQ()
print(agent.Q)

print(wins * 1.0 / num_episodes)