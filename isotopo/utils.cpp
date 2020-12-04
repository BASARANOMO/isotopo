#include "utils.h"

map<string, int> nameCounter(const vector<Town> towns) {
	map<string, int> counter;
	for (auto it = towns.begin(); it != towns.end(); it++) {
		counter[it->name()]++;
	}
	return counter;
}

map<Point2D, int> coorCounter(const vector<Town> towns) {
	map<Point2D, int> counter;
	for (auto it = towns.begin(); it != towns.end(); it++) {
		counter[it->point()]++;
	}
	return counter;
}

set<Town> sameNameSet(const vector<Town> towns, map<string, int> counter) {
	set<Town> setName;
	for (auto it = towns.begin(); it != towns.end(); it++) {
		if (counter[it->name()] >= 2) setName.insert(*it);
	}
	return setName;
}

set<Town> sameCoorSet(const vector<Town> towns, map<Point2D, int> counter) {
	set<Town> setCoor;
	for (auto it = towns.begin(); it != towns.end(); it++) {
		if (counter[it->point()] >= 2) setCoor.insert(*it);
	}
	return setCoor;
}

set<Town> townSetIntersection(const set<Town> setName, const set<Town> setCoor) {
	vector<Town> intersected(min(setName.size(), setCoor.size()));
	vector<Town>::iterator end = set_intersection(setName.begin(), setName.end(), setCoor.begin(), setCoor.end(), intersected.begin());
	intersected.resize(end - intersected.begin());
	return set<Town>(intersected.begin(), intersected.end());
}