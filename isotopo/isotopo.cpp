#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "town.h"

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

    // That's all folks
    return 0;
}
