#include <vector>
#include <string>
#include <limits.h>

using namespace std;

const int closest_right(const string &line, const int &x);

const int closest_bottom(const vector<string> &line, const int &x, const int &y);

const vector<string> closest_neighbors(const vector<string> &line);