#ifndef BOTDISP_H
#define BOTDISP_H

#include <vector>

class BotDisp {
public:
    BotDisp(int width, int height);

    // Add an obstacle to the display at position (r,c).
    // Represented by the character '#'. Obstacles don't 
    // move once added.
    void add_obstacle(int r, int c);

    // Add a bot to the display, using symbol s when displayed.
    // No error checking is done! s should not be '.', '#', or 'G'.
    void add_bot(char s, int r, int c);

    // Add goal to the display at position (r, c). The goal doesn't
    // move.
    void add_goal(int r, int c);
    
    // remove all bot symbols from the display.
    void clear_bots();

    // clear the console and display the world.
    void show() const;

private:
    int width;
    int height;

    std::vector<std::vector<char>> world;
};

#endif
