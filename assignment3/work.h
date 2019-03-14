#ifndef WORK_H
#define WORK_H
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <iterator>

using namespace std;

class work{
private:
	int hits;
	int misses;
	
public:
	//the max that filledPages can be is the cache size
	int cacheSize;
	//may not need this, just use cacheF.size()
	int filledPages;
	int page;
	int clockhand;

	queue<int> Q;
	int cache[100];
	int Fido[100];
	list<int> cacheF;
	//add things to the list. whenever you miss, check to see if its filled. If it is, replace a page, otherwise add it
	//std::vector<int> cache;
	//std::vector<int> pages;

	work(); //temp for now, idk what this'll have to do yet

	void read(int p);
	int search(int p);

	void hit();
	void miss();
	int gethits();
	int getmisses();

	void fifo(int p);// uses a queue (Q)
	void random(int p);
	void lru(int p);
	void clock(int p);// uses an array (Fido) Fido[i] = cache[i].recentlyused()
			  // also uses clockhand to remember where the clockhand is
	void opt(int p);

};

#endif
