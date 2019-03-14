#include "work.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

using namespace std;

work::work(){
	this->clockhand = 0;
	cacheF = new list<int>();
}


void work::hit(){
	this->hits += 1;
}

void work::miss(){
	this->misses += 1;no
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

int work::searchF(int p){
	std::list<int>::iterator itr = cacheF.begin();
	for(int i = 0; i<cacheF.size();i++){
		if(itr == NULL){
			//dont think we need this case, but will wait until we test to take it out
			return 101;
		if(*itr == p){	
			return i;
		}
		itr++;
	}
	return 101;
}

void work::replaceF(int p, int index){
	std::list<int>::iterator itr = cacheF.begin();
	for(int i = 0; i<index; i++){
		itr++;
	}
	*itr = p;
}
			

//---------------|| PAGE EJECTION ALGORITHMS ||--------------------------

void work::fifo(int p){
	//if(search(p) == 101){ //MISS
	if(searchF(p) == 101){ //MISS
		if(cacheF.size()<cacheSize){
			cacheF.push_back(p);
			return;
		}else{
			cacheF.pop_front();
			cacheF.push_back(p);
			miss();
		}

		/*int replaceThis = Q.pop();
		cache[search(replaceThis)] = p;
		Q.push(p);
		miss();*/
	}
	//if(search(p) < 100){ //HIT
	if(searchF(p)<cacheSize){ //HIT
		hit();
	}else(
		cout << "search(int p) is not working";
	}
}

void work::random(int p){
	/*if(search(p) == 101){ //MISS
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
	}*/
	
	if(searchF(p) == 101){ //MISS
		if(cacheF.size() < cacheSize){
			cacheF.push_back(p);
			return;
		}
		srand(time(NULL));
		int temp = rand() % cacheSize;
		replaceF(p,temp);
		miss();
	}
	if(searchF(p)<cacheSize){//HIT
		hit();
	}else{
		cout<<"searchF(int p) is not working"<<endl;
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

void work::LRU(int p){
	if(searchF(p) == 101){ //MISS
		if(cacheF.size() < cacheSize){
			cacheF.push_back(p);
			return;
		}
		cacheF.pop_front;
		cacheF.push_back(p);
		miss();
	}
	if(searchF(p) < cacheSize){ //HIT
		cacheF.remove(p);
		cacheF.push_back(p);
		hit();
	}
	else{
		cout<<"Smth not working"<<endl;
	}
}

void work::OPT(int p,list<int> access,

