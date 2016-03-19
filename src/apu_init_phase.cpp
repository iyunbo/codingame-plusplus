#include <sstream>
#include "apu_init_phase.h"

const int closest_right(const string &line, const int &x) {
    if (x + 1 >= line.size()) return -1;
    if (line[x + 1] == '0')
        return (x + 1);
    else
        return closest_right(line, x + 1);
}

const int closest_bottom(const vector<string> &grids, const int &x, const int &y) {
    if (y + 1 >= grids.size()) return -1;
    if (grids[y + 1][x] == '0')
        return y + 1;
    else
        return closest_bottom(grids, x, y + 1);
}


const string to_str(int number) {
    stringstream out;
    out << number;
    return out.str();
}

const vector<string> closest_neighbors(const vector<string> &grids) {
    vector<string> answer;
    for (int x = 0; x < grids[0].size(); x++) {
        for (int y = 0; y < grids.size(); y++) {
            if (grids[y][x] == '0') {
                string line("");
                line += to_str(x);
                line += " ";
                line += to_str(y);
                line += " ";
                int right_neighbor = closest_right(grids[y], x);
                line += to_str(right_neighbor);
                line += " ";
                line += to_str(right_neighbor == -1 ? -1 : y);
                line += " ";
                int bottom_neighbor = closest_bottom(grids, x, y);
                line += to_str(bottom_neighbor == -1 ? -1 : x);
                line += " ";
                line += to_str(bottom_neighbor);
                answer.push_back(line);
            }
        }
    }
    return answer;
}
