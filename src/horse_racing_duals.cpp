#include "horse_racing_duals.h"

int diff_of_closest_elements(vector<int> elements) {
    int minDiff = INT_MAX;
    sort(elements.begin(), elements.end());
    for (int i = 0; i < elements.size() - 1; i++) {
        const int diff = elements[i + 1] - elements[i];
        if (diff < minDiff) {
            minDiff = diff;
        }
    };
    return minDiff;
}


