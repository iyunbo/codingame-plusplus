#include <iostream>
#include <defibrillators.h>
#include <math.h>
#include <sstream>
#include <float.h>

const vector<Location> toLocations(const vector<string> &defibrillators) {
    vector<Location> locations(defibrillators.size());
    transform(defibrillators.begin(), defibrillators.end(), locations.begin(), toLocation);
    return locations;
}

const string nearest(const vector<string> &defib_list, const string &lon, const string &lat) {
    const Location target = {toRdians(lon), toRdians(lat), "User"};
    const vector<Location> locations = toLocations(defib_list);
    return nearestLocation(target, locations).name;
}


const Location nearestLocation(const Location &target, const vector<Location> &locations) {
    double min = DBL_MAX;
    Location nearest;
    auto lambda = [&](Location loc) {
        findNearest(nearest, min, target, loc);
    };
    for_each(locations.begin(), locations.end(), lambda);
    return nearest;
}

void findNearest(Location &nearest, double &min, const Location &target, const Location &loc) {
    double d = distance(target, loc);
    if (d < min) {
        min = d;
        nearest = loc;
    }
}

const double distance(const Location &a, const Location &b) {
    const double x = (b.longitude - a.longitude) * cos((a.latitude + b.latitude) / 2l);
    const double y = b.latitude - a.latitude;
    return sqrt(x * x + y * y) * EARTH_RADIUS;
}

const Location toLocation(const string &line) {
    const vector<string> fields = split(line, ';');
    return (Location) {toRdians(fields[4]), toRdians(fields[5]), fields[1]};
}

const double toRdians(const string &degree) {
    return stod(replace(degree, ",", ".")) * static_cast<double>(M_PI) / HALF_CIRCLE_DEGREES;
}

const vector<string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

const vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

const string replace(const string &str, const string &from, const string &to) {
    string new_str = str;
    const size_t start_pos = new_str.find(from);
    if (start_pos == string::npos) return new_str;
    new_str.replace(start_pos, from.length(), to);
    return new_str;
}
