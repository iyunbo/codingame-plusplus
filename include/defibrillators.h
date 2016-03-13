#include <string>
#include <vector>

static const double EARTH_RADIUS = 6371l;
static const double HALF_CIRCLE_DEGREES = 180l;
using namespace std;

struct Location {
    double longitude;
    double latitude;
    string name;

    bool operator==(const Location &rhs) const {
        return rhs.name.compare(this->name) == 0;
    }
};

const string nearest(const vector<string> &defib_list, const string &lon, const string &lat);

const double distance(const Location &a, const Location &b);

const Location toLocation(const string &line);

const vector<string> &split(const string &s, char delim, vector<string> &elems);

const vector<string> split(const string &s, char delim);

const string replace(const string &str, const string &from, const string &to);

const double toRdians(const string &degree);

const Location nearestLocation(const Location &target, const vector<Location> &locations);

void findNearest(Location &nearest, double &min, const Location &target, const Location &loc);