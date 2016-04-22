#include "FIFO.h"
#include "PCB.h"
#include <stdio.h>
#include <stdlib.h>

int SysStack;

int main() {
	int loopCount = 1;
	int SysStack = 0;
	unsigned int pcValue = pcRand();
	FIFO processQueue = FIFO_construct();
	FIFO_init(processQueue);


	while (loopCount) {
	// function that creates a random number of new processes, between 0 and 5 and puts them in the list


		printf("Random Int %lu " + pcRand());
		printf("Random Int %lu " + pcRand());
		printf("Random Int %lu " + pcRand());
	}

}


void createProcesses() {


}

unsigned int pcRand() {
	return (rand() % 1000 + 3000);
}
