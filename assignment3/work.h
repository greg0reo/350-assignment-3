#ifndef WORK_H
#define WORK_H
#include <iostream>
#include <vector>


using namespace std;

class work{
private:
	int hits;
	int misses;
public:
	std::vector<int> cache;
	//std::vector<int> pages;

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
