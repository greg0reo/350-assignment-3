
#include "work.h"
#include <iostream>
#include <list>
#include <time.h>

using namespace std;

int main(int argc, char *argv[]){


  work Gree = work(5);
  //-----------------NO LOCALITY---------------------

  list<int> noLocality;

  srand(time(NULL));
  int page;
  for(int i=0; i < 100; i++){
    page = rand()% 100;
    noLocality.push_back(page);
		//noLocality.push_back(rand()%10);
  }

  

  
  //--------------------80-20-----------------------

  list <int> eightTwo;

  srand(time(NULL));
  int chance;
  for(int i=0; i < 10000; i++){
    chance = (rand() % 100);
    if(chance < 20){
      page = rand()% 80;
      eightTwo.push_back(page);
    }else{
      page = (rand()% 20) +80;
      eightTwo.push_back(page);
    }
  }


  //---------------Looping-Sequential--------------

  list <int> loopSeq;

  int counter = 0;
  for(int i=0; i < 10000; i++){
    loopSeq.push_back(counter);
    counter += 1;
    if(counter == 50){
      counter = 0;
    }
  }





  //Testing the various page dropping alogirthms we've designed

  /*int temp;
	for(int j = 0; j < 10000; j++){
	  //Random first
	  temp = noLocality.front(); 
	  noLocality.pop_front();
		cout<<"we are looking for page number " << temp << endl;
	  Gree.random(temp);
	  noLocality.push_back(temp); //this way, the List remains the same after looping through it
	}
	printf("Hits: %d          ", Gree.gethits());
	printf("Misses: %d\n", Gree.getmisses());
	Gree.cacheF.clear();
	Gree.misses = 0;
	Gree.hits = 0;*/
/*
int temp;
printf("Clock Page Ejection\n");
	for(int j = 0; j < 10000; j++){
	  //Clock
	  temp = eightTwo.front();
	  eightTwo.pop_front();
	  Gree.clock(temp);
	  eightTwo.push_back(temp);
	}

	printf("Hits: %d          ", Gree.gethits());
	printf("Misses: %d\n", Gree.getmisses());
	Gree.cacheF.clear();
	Gree.misses = 0;
	Gree.hits = 0;
*/
  
  

	int temp;
  printf("Cache Size: 5\n\n");
  for(int i = 10; i<=106; i+= 5){
    //check different workloads
	//PRINT CACHE SIZE HERE

    /*
    for(int i=0; i < 10000; i++){
      page = rand()% 100;
      noLocality.push_back(page);
    }*/


     for(int i=0; i < 10000; i++){
    chance = (rand() % 100);
    if(chance < 20){
      page = rand()% 80;
      eightTwo.push_back(page);
    }else{
      page = (rand()% 20) +80;
      eightTwo.push_back(page);
    }
  }



/*


  counter = 0;
    for(int i=0; i < 10000; i++){
      loopSeq.push_back(counter);
      counter += 1;
      if(counter == 50){
        counter = 0;
      }
    }
*/
	printf("Random Page Ejection\n");
	for(int j = 0; j < 10000; j++){
	  //Random first
	  //temp = noLocality
	  temp = eightTwo.front(); 
	  //noLocality
	  eightTwo.pop_front();
	  Gree.random(temp);
	  //noLocality
	  eightTwo.push_back(temp); //this way, the List remains the same after looping through it
	}

	printf("Hits: %d          ", Gree.gethits());
	printf("Misses: %d\n", Gree.getmisses());
	Gree.cacheF.clear();
	Gree.misses = 0;
	Gree.hits = 0;


	printf("FIFO Page Ejection\n");
	for(int j = 0; j < 10000; j++){
	  //FIFO
	  //temp = noLocality
	  temp = eightTwo.front();
	  //noLocality
	  eightTwo.pop_front();
	  Gree.fifo(temp);
	  //noLocality
	  eightTwo.push_back(temp);
	}

	printf("Hits: %d          ", Gree.gethits());
	printf("Misses: %d\n", Gree.getmisses());
	Gree.cacheF.clear();
	Gree.misses = 0;
	Gree.hits = 0;

	printf("LRU Page Ejection\n");
	for(int j = 0; j < 10000; j++){
	  //LRU
	  //temp = noLocality
	  temp = eightTwo.front();
	  //noLocality
	  eightTwo.pop_front();
	  Gree.LRU(temp);
	  //noLocality
	  eightTwo.push_back(temp);
	}

	printf("Hits: %d          ", Gree.gethits());
	printf("Misses: %d\n", Gree.getmisses());
	Gree.cacheF.clear();
	Gree.misses = 0;
	Gree.hits = 0;

	printf("Clock Page Ejection\n");
	for(int j = 0; j < 10000; j++){
	  //Clock
	  //temp = noLocality
	  temp =eightTwo.front();
	  //noLocality
	  eightTwo.pop_front();
	  Gree.clock(temp);
	  //noLocality
	  eightTwo.push_back(temp);
	}

	printf("Hits: %d          ", Gree.gethits());
	printf("Misses: %d\n", Gree.getmisses());
	Gree.cacheF.clear();
	Gree.misses = 0;
	Gree.hits = 0;

	printf("Optimized Page Ejection\n");
	for(int j = 0; j < 10000; j++){
	  //OPT
	  //temp = noLocality
	  temp = eightTwo.front();
	  //noLocality
	  eightTwo.pop_front();
	  Gree.OPT(temp, noLocality); //may be wrong implementation of OPT
	  //noLocality.push_back(temp);
	}

	printf("Hits: %d          ", Gree.gethits());
	printf("Misses: %d\n", Gree.getmisses());
	Gree.cacheF.clear();
	//noLocality
	eightTwo.clear();
	Gree.misses = 0;
	Gree.hits = 0;


    //then increment cache size
	Gree.cacheSize = i;
	printf("\n--------------------\n\nCache Size: %d\n", i);


  for(int i=0; i < 10000; i++){
    page = rand()% 100;
    noLocality.push_back(page);
		//noLocality.push_back(rand()%10);
  }


  }



  
  
  
  
}
