#include work.h"
#include <iostream>
#include <list>
#include <time.h>

using namespace std;

int main(int argc, char *argv[]){


  
  //-----------------NO LOCALITY---------------------

  list <int> noLocality;

  srand (time(NULL));
  int page;
  for(int i=0; i < 10000; i++){
    page = rand()% 100;
    noLocality.push_back(page)
  }

  

  
  //--------------------80-20-----------------------

  list <int> eightTwo;

  srand(time(NULL));
  int chance;
  for(int i=0; i < 10000; i++){
    chance = rand() % 10 +1;
    if(chance > 2){
      page = rand()% 20;
      eightTwo.push_back(page);
    }else{
      page = rand()% 80 +20;
      eightTwo.push_back(page);
    }
  }


  //---------------Looping-Sequential--------------

  list <int> loopSeq;

  int counter = 0;
  for(int i=0; i < 10000; i++){
    loopSeq.push_back(counter);
    counter += 1;
    if(counter = 50){
      counter = 0;
    }
  }





  //Testing the various page dropping alogirthms we've designed

  work Gree = work(5);
  int temp;
  for(int i = 10; i=<100; i+= 5){
    //check different workloads
	//PRINT CACHE SIZE HERE

	printf("Random Page Ejection\n");
	for(int j = 0; j < 10000; j++){
	  //Random first
	  temp = noLocality.pop_front();
	  Gree.random(temp);
	  noLocality.push)back(temp); //this way, the List remains the same after looping through it
	}

	printf("Hits: %d          ", Gree.gethits());
	printf("Misses: %d\n", Gree.getmisses());
	Gree.cacheF.clear();

	printf("FIFO Page Ejection\n");
	for(int j = 0; j < 10000; j++){
	  //FIFO
	  temp = noLocality.pop_front();
	  Gree.fifo(temp);
	  noLocality.push_back(temp);
	}

	printf("Hits: %d          ", Gree.gethits());
	printf("Misses: %d\n", Gree.getmisses());
	Gree.cacheF.clear();

	printf("LRU Page Ejection\n");
	for(int j = 0; j < 10000; j++){
	  //LRU
	  temp = noLocality.pop_front();
	  Gree.LRU(temp);
	  noLocality.push_back(temp);
	}

	printf("Hits: %d          ", Gree.gethits());
	printf("Misses: %d\n", Gree.getmisses());
	Gree.cacheF.clear();

	printf("Clock Page Ejection\n");
	for(int j = 0; j < 10000; j++){
	  //Clock
	  temp = noLocality.pop_front();
	  Gree.clock(temp);
	  noLocality.push_back(temp);
	}

	printf("Hits: %d          ", Gree.gethits());
	printf("Misses: %d\n", Gree.getmisses());
	Gree.cacheF.clear();

	printf("Optimized Page Ejection\n");
	for(int j = 0; j < 10000; j++){
	  //OPT
	  

	}

    //then increment cache size
	


  }

  
  
  
  
}
