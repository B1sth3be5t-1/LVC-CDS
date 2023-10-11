#include <iostream>
#include <vector>

using namespace std;
struct blok {
    int width;
    int height;
};

int best(vector<blok>& blocks, int curBlok, int max_width, int best_height, vector<int>& breakTotals) {
    int remaining = max_width;
    int cur_line_height = 0;

    best_height = 150 * 5000;

    for (int i = curBlok; i < blocks.size(); ++i) {
        auto blk = blocks[i];
        //if blk doesn't fit
        //return best_height
        if (remaining < blk.width)
            return best_height;

        //add block to line
        //adjust remaining width and line height
        remaining -= blk.width;
        if (blk.height > cur_line_height) cur_line_height = blk.height;

        //BASE CASE
        if (i == blocks.size() - 1) return cur_line_height;

        //try a line break
        int rest = best(blocks, i + 1, max_width, best_height, breakTotals);
        if (rest + cur_line_height < best_height) {
            best_height = rest + cur_line_height;
        }
    }
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
    }

    int maxH = 150 * 5000;

    vector<int> breakTotals;
    breakTotals.assign(5000, -1);

    int min_height = best(blocks, 0, width, maxH, breakTotals);


    cout << min_height << endl;

}
