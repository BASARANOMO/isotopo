#include "utils.h"

map<string, int> nameCounter(const vector<Town> towns) {
	map<string, int> counter;
	for (auto it = towns.begin(); it != towns.end(); ++it) {
		counter[it->name()]++;
	}
	return counter;
}

map<Point2D, int> coorCounter(const vector<Town> towns) {
	map<Point2D, int> counter;
	for (auto it = towns.begin(); it != towns.end(); ++it) {
		counter[it->point()]++;
	}
	return counter;
}

set<Town> sameNameSet(const vector<Town> towns, map<string, int> counter) {
	set<Town> setName;
	for (auto it = towns.begin(); it != towns.end(); ++it) {
		if (counter[it->name()] >= 2) setName.insert(*it);
	}
	return setName;
}

set<Town> sameCoorSet(const vector<Town> towns, map<Point2D, int> counter) {
	set<Town> setCoor;
	for (auto it = towns.begin(); it != towns.end(); ++it) {
		if (counter[it->point()] >= 2) setCoor.insert(*it);
	}
	return setCoor;
}

set<Town> townSetIntersection(const set<Town> setName, const set<Town> setCoor) {
	set<Town> intersection;
	set_intersection(setName.begin(), setName.end(), setCoor.begin(), setCoor.end(), inserter(intersection, intersection.end()));
	return intersection;
}

// don't use set.find
int confusingTownCounter(const set<Town> intersection) {
	int count = 0;
	for (auto it1 = intersection.begin(); it1 != intersection.end(); it1++) {
		set<Town> sameCoorTowns;
		set<Town> sameNameTowns;

		// search all towns having the same coordinates or having the same names
		for (auto it2 = intersection.begin(); it2 != intersection.end(); it2++) {
			if (it1 != it2) {
				if (it1->x() == it2->x() && it1->y() == it2->y()) {
					sameCoorTowns.insert(*it2);
				}
				if (it1->name() == it2->name()) {
					sameNameTowns.insert(*it2);
				}
			}
		}
		if (sameCoorTowns.size() == 0 || sameNameTowns.size() == 0) continue;

		// for each town in sameNameTowns, find its neighbors
		for (auto it3 = sameNameTowns.begin(); it3 != sameNameTowns.end(); it3++) {
			for (auto it4 = intersection.begin(); it4 != intersection.end(); it4++) {
				if (it4->name() != it3->name() && (it4->x() == it3->x() && it4->y() == it3->y())) {
					for (auto it5 = sameCoorTowns.begin(); it5 != sameCoorTowns.end(); it5++) {
						if (it5->name() == it4->name()) count++;
					}
				}
			}
		}
	}
	return count;
}