#include "work.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

using namespace std;

work::work(){
	this->clockhand = 0;
}


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

void work::random(int p){
	if(search(p) == 101){ //MISS
		int temp;
		srand(time(NULL)); //copied code from cplusplus.com
		temp = rand() % 100;
		cache[temp] = p;
		miss();
	}
	if(search(p) < 100){ //HIT
		hit();
	}else{
		cout << "search(int p) is not working";
	}
}

void work::clock(int p){
	if(search(p) == 101){ //MISS
		while(Fido[clockhand] != 0){
			Fido[clockhand] = 0;
			clockhand++;
			if(clockhand == 100){
				this->clockhand = 0;
			}
		}
		cache[clockhand] = p;
		miss();
	}
	if(search(p) < 100){ //HIT
		Fido[search(p)] = 1;
		hit();
	}else{
		cout << "search(int p) is not working";
	}
}

