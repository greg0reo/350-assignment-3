#include "work.h"

using namespace std;

void work::hit(){
	this->hits += 1;
}

void work::miss(){
	this->misses += 1;
}

int work::gethits(){
	return this->hits;
}

int work::getmisses(){
	return this->misses;
}



void work::read(int p){
	this->page = p;
}

int work::search(int p){
	for(int i=0; i < 100; i++){
		if(p == cache[i]){
			return i;
		}
	}
	return 101;
}

//---------------|| PAGE EJECTION ALGORITHMS ||--------------------------

void work::fifo(int p){
	if(search(p) == 101){ //MISS
		int replaceThis = Q.pop();
		cache[search(replaceThis)] = p;
		Q.push(p);
		miss();
	}
	if(search(p) < 100){ //HIT
		hit();
	}else(
		cout << "search(int p) is not working";
	}
}


