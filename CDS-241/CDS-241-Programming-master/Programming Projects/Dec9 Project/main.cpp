#include <iostream>
#include <memory>

#include "botworld.h"
#include "smart_bot.h"
#include "drunk_bot.h"
#include "follow_bot.h"

using namespace std;


// Since those subclasses are NOT part of the library, they should 
// go out here, separate from it. This separation helps keep clear
// what is library code and what is application code.

int main()
{

    
    BotWorld bw(10, 30, 0.12);

    bw.add_bot(make_unique<smartBot>(smartBot('S')));
    bw.add_bot(make_unique<drunkBot>(drunkBot('D')));
    bw.add_bot(make_unique<smartBot>(smartBot('S')));
    bw.add_bot(make_unique<drunkBot>(drunkBot('D')));
    bw.add_bot(make_unique<followBot>(followBot('F')));
    bw.add_bot(make_unique<followBot>(followBot('F')));

    

    bw.run_sim(1000);

}
