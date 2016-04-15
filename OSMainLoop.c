#include "FIFO.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	int loopCount = 1;
	int SysStack = 0;
	unsigned int pcValue = pcRand();
	FIFO processQueue = FIFO_construct();
	FIFO_init(processQueue);


	printf("Random Int %lu " + pcRand());
	printf("Random Int %lu " + pcRand());
	printf("Random Int %lu " + pcRand());

}

while (loopCount) {
	// function that creates a random number of new processes, between 0 and 5 and puts them in the list

}

void createProcesses() {


}

unsigned int pcRand() {
	return (rand() % 1000 + 3000);
}
