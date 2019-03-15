#include "work.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <list>

using namespace std;

work::work(int size){
	cacheSize = size;
	//list<int> cacheF;
	for(int i = 0; i<cacheSize; i++){
		Fido.push_back(0);
	}
	clockhand = 0;
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

int work::searchF(int p){
	std::list<int>::iterator itr = cacheF.begin();
	for(int i = 0; i<cacheF.size();i++){
		if(itr == cacheF.end()){
			//dont think we need this case, but will wait until we test to take it out
			return 101;
		}
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
			miss();
			return;
		}else{
			cacheF.pop_front();
			cacheF.push_back(p);
			miss();
			return;
		}

		/*int replaceThis = Q.pop();
		cache[search(replaceThis)] = p;
		Q.push(p);
		miss();*/
	}
	//if(search(p) < 100){ //HIT
	if(searchF(p)<cacheSize){ //HIT
		hit();
	}else{
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
		cout<<"MISS"<<endl;
		if(cacheF.size() < cacheSize){
			cacheF.push_back(p);
			miss();
			return;
		}
		srand(time(NULL));
		int temp = rand() % cacheSize;
		replaceF(p,temp);
		miss();
		return;
	}
	if(searchF(p)<cacheSize){//HIT
		cout<<"HIT"<<endl;
		hit();
	}else{
		cout<<"searchF(int p) is not working"<<endl;
	}
}

/*void work::clock(int p){
	if(searchF(p) == 101){ //MISS
		while(Fido[clockhand] != 0){
			Fido[clockhand] = 0;
			clockhand++;
			if(clockhand == 100){
				this->clockhand = 0;
			}
		}
		cache[clockhand] = p;
		miss();
		return;
	}
	if(search(p) < 100){ //HIT
		Fido[search(p)] = 1;
		hit();
	}else{
		cout << "search(int p) is not working";
	}
}*/

void work::clock(int p){
	int index = searchF(p);
	if(index == 101){ //MISS
		if(cacheF.size() < cacheSize){
			cacheF.push_back(p);
			miss();
			return;
		}
		list<int>::iterator clocker = Fido.begin();
		list<int>::iterator cacher = cacheF.begin();
		for(int i = 0 ; i< clockhand;i++){
			clocker++;
			if(clocker == Fido.end()) clocker = Fido.begin();
			cacher++;
			if(cacher == cacheF.end()) cacher = cacheF.begin();
		}
		while(*clocker != 0){
			*clocker = 0;
			clocker++;
			cacher++;
			clockhand++;
		}
		*cacher = p;
		*clocker = 1;
		clockhand++;
		//if(clockhand < cacheSize) this->clockhand -= cacheSize;		
		clockhand= (clockhand+1)%cacheSize;
		miss();
		return;
	}
	if(index < cacheSize){ //HIT
		list<int>::iterator cacher = cacheF.begin();
		for(int i = 0; i<index; i++){
			cacher++;
		}
		*cacher = 1;
		hit();
	}else{
		cout<<"SMTHWNG"<<endl;
	}
}
			
		
		
		
void work::LRU(int p){
	if(searchF(p) == 101){ //MISS
		if(cacheF.size() < cacheSize){
			cacheF.push_back(p);
			miss();
			return;
		}
		cacheF.pop_front();
		cacheF.push_back(p);
		miss();
		return;
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

void work::OPT(int p,list<int> access){
	if(searchF(p) == 101){ //MISS
		if(cacheF.size() < cacheSize){
			cacheF.push_back(p);
			miss();
			return;
		}
		list<int> temp = *(new list<int>(cacheF));
		list<int>::iterator itr = access.begin();
		list<int>::iterator itr2 = temp.begin();
		for(itr;itr != access.end(); itr++){
			if(temp.size() == 1){
				break;
			}
			
			temp.remove(*itr);
		}
		cacheF.remove(*(temp.begin()));
		cacheF.push_back(p);
		//free(&temp);
		miss();
		return;
	}
	if(searchF(p) < cacheSize){ //HIT
		hit();
	}else{
		cout<< "Sum Ting Wong" << endl;
	}
}
			
		 
	







