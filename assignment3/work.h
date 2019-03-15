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
public:
	int hits = 0;
	int misses = 0;
	

	//the max that filledPages can be is the cache size
	int cacheSize;
	//may not need this, just use cacheF.size()
	int filledPages;
	int page;
	//list<int>::iterator clockhand;
	int clockhand;
	list<int>::iterator cachehand;

	queue<int> Q;
	int cache[100];
	//int Fido[100];
	list<int> cacheF;
	list<int> Fido;
	//add things to the list. whenever you miss, check to see if its filled. If it is, replace a page, otherwise add it
	//std::vector<int> cache;
	//std::vector<int> pages;

	work(int); //temp for now, idk what this'll have to do yet

	void read(int);
	int search(int);
	int searchF(int);
	void replaceF(int, int);

	void hit();
	void miss();
	int gethits();
	int getmisses();

	void fifo(int);// uses a queue (Q)
	void random(int);
	void LRU(int);
	void clock(int);// uses an array (Fido) Fido[i] = cache[i].recentlyused()
			  // also uses clockhand to remember where the clockhand is
	void OPT(int,list<int>);

};

#endif
