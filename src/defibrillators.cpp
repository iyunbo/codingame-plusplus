#include <iostream>
#include <defibrillators.h>
#include <math.h>
#include <sstream>
#include <float.h>

const vector<Location> toLocations(const vector<string> &defibrillators) {
    vector<Location> locations;
    for (string defibrillator : defibrillators) {
        locations.push_back(toLocation(defibrillator));
    }
    return locations;
}

const string nearest(const vector<string> &defib_list, const string &lon, const string &lat) {
    const Location target = {toRdians(lon), toRdians(lat), "User"};
    const vector<Location> locations = toLocations(defib_list);
    return nearestLocation(target, locations).name;
}

const Location nearestLocation(const Location &target, const vector<Location> &locations) {
    Location nearest = {0.0, 0.0, "N/A"};
    double min = DBL_MAX;
    double d;
    for (Location loc : locations) {
        d = distance(target, loc);
        if (d < min) {
            min = d;
            nearest = loc;
        }
    }
    return nearest;
}

const double distance(const Location &a, const Location &b) {
    const double x = (b.longitude - a.longitude) * cos((a.latitude + b.latitude) / 2l);
    const double y = b.latitude - a.latitude;
    return sqrt(x * x + y * y) * EARTH_RADIUS;
}

const Location toLocation(const string &line) {
    vector<string> fields = split(line, ';');
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

const string &replace(const string &str, const string &from, const string &to) {
    string newstr = str;
    size_t start_pos = newstr.find(from);
    if (start_pos == string::npos)
        return newstr;
    newstr.replace(start_pos, from.length(), to);
    return newstr;
}
