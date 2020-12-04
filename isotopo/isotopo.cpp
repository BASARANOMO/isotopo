#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "town.h"
#include "utils.h"

using namespace std;

#ifndef srcPath
#define srcPath "."
#endif
// The path and name of the town file
const string townFile = srcPath "/villes-UTF8.txt";

// Study French isotoponyms
int main() {
    vector<Town> towns;
    // Read file
    cout << "Reading town file: " << townFile << endl;
    clock_t time1 = clock();
    int nb_towns = Town::read_file(townFile, towns);
    clock_t time2 = clock();
    // Sanity check
    if (nb_towns < 0) {
        cout << "Error while reading file" << endl;
        return 2;
    }
    if (nb_towns == 0) {
        cout << "No town found" << endl;
        return 1;
    }

    srand(time(NULL));
    // Say how many towns have been read
    cout << "File read in: "
         << ((float)(time2-time1)/CLOCKS_PER_SEC) << " s" << endl;
    cout << "Number of towns in file: "
         << towns.size() /* same as nb_towns */ << endl;
    cout << "A random town, using format \"name[lat,lon](x,y)\": "
         << towns[rand() % towns.size()] << endl;

    // Histogram of repeted town names
    map<string, int> nameCounterMap;
    nameCounterMap = nameCounter(towns);
    printf("\nHistogram of repeted town names (Number of town names used by exactly i town(s)): \n");
    counterHistogram<string>(nameCounterMap);

    // Histogram of repeted coordinates
    map<Point2D, int> coorCounterMap;
    coorCounterMap = coorCounter(towns);
    printf("\nHistogram of repeted coordinates (Number of coordinates shared by exactly i town(s)): \n");
    counterHistogram<Point2D>(coorCounterMap);
    printf("\n");

    // Set of towns whose names are shared with other town(s)
    set<Town> setName;
    setName = sameNameSet(towns, nameCounterMap);
    printf("Number of towns whose names are shared with other town(s): %d\n", setName.size());
    // Set of towns whose coordinates are shared with other town(s)
    set<Town> setCoor;
    setCoor = sameCoorSet(towns, coorCounterMap);
    printf("Number of towns whose coordinates are shared with other town(s): %d\n", setCoor.size());
    // Intersection O(|N| + |C|)
    set<Town> intersected;
    intersected = townSetIntersection(setName, setCoor);
    printf("Number of towns in the intersection of set N and set C: %d\n", intersected.size());
    return 0;
}
