#pragma once

#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include "town.h"
#include "point2d.h"

using namespace std;

map<string, int> nameCounter(const vector<Town>);  // count the number of occurrences of town names
map<Point2D, int> coorCounter(const vector<Town>);

// histogram of nameCounter/coorCounter
template<typename T>
void counterHistogram(const map<T, int> counter) {
	map<int, int> hist;
	for (auto it = counter.begin(); it != counter.end(); it++) {
		hist[it->second]++;
	}
	for (auto it = hist.begin(); it != hist.end(); it++) {
		printf("%d: %d\n", it->first, it->second);
	}
}

set<Town> sameNameSet(const vector<Town>, map<string, int>);
set<Town> sameCoorSet(const vector<Town>, map<Point2D, int>);
set<Town> townSetIntersection(const set<Town>, const set<Town>);

int confusedTownCounter(set<Town>);