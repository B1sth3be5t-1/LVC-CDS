#include <iostream>
#include <vector>

using namespace std;
struct blok {
    int width;
    int height;
};

vector<int> breakTotals;

int best(vector<blok>& blocks, int curBlok, int max_width) {
    int remaining = max_width;
    int cur_line_height = 0;

    //BASE CASE
    if (curBlok == blocks.size())
        return 0;

    if (breakTotals[curBlok] != -1)
        return breakTotals[curBlok];

    int best_height = 150 * 5000;

    for (int i = curBlok; i < blocks.size(); ++i) {
        auto blk = blocks[i];
        //if blk doesn't fit
        //return best_height
        if (remaining < blk.width)
        {
            breakTotals[curBlok] = best_height;
            return best_height;
        }

        //add block to line
        //adjust remaining width and line height
        remaining -= blk.width;
        if (blk.height > cur_line_height) cur_line_height = blk.height;


        //try a line break
        int rest = best(blocks, i + 1, max_width);
        if (rest + cur_line_height < best_height) {
            best_height = rest + cur_line_height;
        }
    }

    breakTotals[curBlok] = best_height;
    return best_height;
}

int main() {
    int numBlocks, width;

    vector<blok> blocks;

    string inp;
    getline(cin, inp);

    numBlocks = stoi(inp.substr(0, inp.find(' ')));
    width = stoi(inp.substr(inp.find(' ') + 1));

    for (int i = 0; i < numBlocks; i++) {
        getline(cin, inp);
        blocks.push_back(std::move(blok{stoi(inp.substr(0, inp.find(' '))), stoi(inp.substr(inp.find(' ') + 1))}));
        //cout << blocks[i].width << ": height: " << blocks[i].height << endl;
    }


    breakTotals.assign(numBlocks, -1);

    int min_height = best(blocks, 0, width);


    cout << min_height << endl;

}
