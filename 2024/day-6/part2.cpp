#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};

int main () {
    int H = 130;
    vector<string> grid(H);
    for (int i = 0; i < H; i++) {
        cin >> grid[i];
    }
    int W = grid[0].length();

    pair<int, int> start_me {-1, -1};
    for (int row = 0; row < H; row++) {
        for (int col = 0; col < W; col++) {
            if (grid[row][col] == '^') {
                start_me = {row, col};
                grid[row][col] = '.';
            }
        }
    }

    auto solveCycle = [&]() {
        pair<int, int> me = start_me;
        int dir = 0;
        set<vector<int>> visit;
        int turns = 0;
        while (true) {
            turns++;
            if (turns == 100'000) {
                return true;
            }
            int r2 = me.first + dirs[dir].first;
            int c2 = me.second + dirs[dir].second;

            if (!(0 <= r2 && r2 < H && 0 <= c2 && c2 < W)) {
                return false;
            }

            if (grid[r2][c2] == '.') {
                me = {r2, c2};
            } else {
                dir = (dir + 1) % 4;
            }
        }
    };

    int answer = 0;
    for (int row = 0; row <H; row++) {
        for (int col = 0; col < W; col++) {
            if (grid[row][col] == '.' && start_me != make_pair(row, col)) {
                grid[row][col] = '#';

                if (solveCycle()) {
                    answer++;
                }

                grid[row][col] = '.';
            }
        }

    }

    cout << answer << "\n";
}
