#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int M, S;
    std::cin >> M;
    std::cin >> S;

    vector<vector<int>> map;
    for (int i = 0; i < M; i++) {
        vector<int> lis;
        for (int j = 0; j < S; j++) {
            int in;
            cin >> in;
            lis.push_back(in);
        }
        map.push_back(lis);
    }


    std::map<int, int> numSongs;
    int numberOfSongs = 0;

    for (int i = 0; i < S; i++) {
        for (vector<int> lis : map) {
            for (int r = i; r <= i; r++) {
                int songNum = lis[r];
                numSongs[songNum]++;

                if (numSongs[songNum] == 1)
                    numberOfSongs++;
            }
        }

        if (numberOfSongs == i + 1) {

            cout << numSongs.size() << "\n";
            vector<int> songs;

            std::map<int, int>::iterator it = numSongs.begin();

            while(it != numSongs.end()) {
                songs.push_back(it->first);
                ++it;
            }

            std::sort(songs.begin(), songs.end());
            string out = "";
            for (int num = 0; num < songs.size(); num++) out.append(to_string(songs[num]) + " ");

            cout << out.substr(0, out.length() - 1);
            return 0;
        }
    }
}
