#include <iostream>

#include "botdisp.h"

using namespace std;

BotDisp::BotDisp(int w, int h)
    : width{w}, height{h}, world(h, vector<char>(w, '.'))
{
}

void BotDisp::add_obstacle(int r, int c) 
{
    // error checking would be a grand idea...
    world[r][c] = '#';
}

void BotDisp::add_bot(char s, int r, int c)
{
    // error checking would be a grand idea...
    world[r][c] = s;
}

void BotDisp::add_goal(int r, int c)
{
    // error checking would be a grand idea...
    world[r][c] = 'G';
}

void BotDisp::clear_bots() 
{
    // slow, but it works. Certainly something we should rethink, if 
    // performance becomes an issue.
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (world[i][j] != '.' && world[i][j] != '#' && world[i][j] != 'G') {
                world[i][j] = '.';
            }
        }
    }
}

void BotDisp::show() const
{
    // magic -- clears the console unix-y terminals.
    // This calls the "clear" command in the terminal. You might need to 
    // change this on your OS -- for instance, I think it's "cls" on windows.
    // Dunno about macOS.
    std::system("clear");
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cout << world[i][j];
        }
        cout << endl;
    }
}
