#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

	int randomPivot = 0;
	int numOfRandomNumbers = 0;
	long sum = 0;
	long primeCounter = 0;
	static pthread_mutex_t the_lock = PTHREAD_MUTEX_INITIALIZER;

int isPrime(int n){
	// Corner cases
	if (n <= 1){
		return 0;
	}

	if (n <= 3){
		return 1;
	}

	// This is checked so that we can skip
	// middle five numbers in below loop
	if (n % 2 == 0 || n % 3 == 0){
		return 0;
	}

	for (int i = 5; i * i <= n; i = i + 6){
		if (n % i == 0 || n % (i + 2) == 0){
			return 0;
		}
	}

	return n;
}


void* call_isPrime(){
	//generate random numbers
	for (int i=0;i<(numOfRandomNumbers/4);i++){
		int random = rand();
        	//check if the number is prime
		if (isPrime(random)){
			//if do, add up it's sum, and increment counter
			pthread_mutex_lock(&the_lock); //from "syncronize"
			sum = sum + random; 
			primeCounter++;
			pthread_mutex_unlock(&the_lock);
		}	
    }
}


int main(int argc, char *argv[]){

	if(argc != 3) {
	    printf("Too few arguments ");
	    printf("USAGE: ./primeCalc <prime pivot> <num of random numbers>");
            exit(0);
    	}

	randomPivot = atoi(argv[1]);
	numOfRandomNumbers = atoi(argv[2]);
	sum = 0;
	primeCounter = 0;
	//init rundom generator
    	srand(randomPivot);


	pthread_t threads[4];
	for(int i=0; i<4; i++){
	pthread_create(&threads[i],NULL,&call_isPrime,NULL);
	
	}
	for(int i=0; i<4; i++){
		pthread_join(threads[i],NULL);
	}
	
	//keep the out format as this!!
	printf("%ld,%ld\n",sum,primeCounter);

    exit(0);
}