#ifndef WORK_H
#define WORK_H
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class work{
private:
	int hits;
	int misses;
	
public:
	int page;

	queue<int> Q;
	int cache[100];
	//std::vector<int> cache;
	//std::vector<int> pages;

	work(); //temp for now, idk what this'll have to do yet

	void read(int p);
	int search(int p);

	void hit();
	void miss();
	int gethits();
	int getmisses();

	void fifo(int p);
	void random(int p);
	void lru(int p);
	void clock(int p);
	void opt(int p);

};

#endif
