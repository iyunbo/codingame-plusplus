#include <string>
#include <list>

using namespace std;

struct Location {
    double x;
    double y;
};

string nearest(list<string> defib_list, string lon, string lat);

double distance(Location a, Location b);