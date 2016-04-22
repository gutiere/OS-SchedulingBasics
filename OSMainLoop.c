#include "PCB.h"
#include "FIFO.h"
#include <stdio.h>
#include <stdlib.h>


int SysStack;

enum Interrupts {
    TIMER
};

PCB_p dispatch(FIFO queue) {
    PCB_p pcb = dequeue(queue);
    SysStack = pcb->pc;
    return pcb;
}

PCB_p reschedule(FIFO queue, PCB_p pcb, enum Interrupts interrupt) {
    if (interrupt == TIMER) {
        pcb->state = ready;
        enqueue(queue, pcb);
        return dispatch(queue);
    }
	return NULL;
}

PCB_p timerInterrupt(FIFO queue, PCB_p pcb, int pc) {
    pcb->state = interrupted;
    pcb->pc = pc;
    return reschedule(queue, pcb, TIMER);
}

unsigned int pcRand() {
	return (rand() % 1000 + 3000);
}

void createProcesses(FIFO theQ) {
	int i;
	for (i = 0; i < (rand() % 5) + 1; i++) {
		PCB_p randomPCB = PCB_construct();
		PCB_init(randomPCB);
		enqueue(theQ, randomPCB);
	}
}

int main() {
	int loopCount = 1;
	int SysStack = 0;
	unsigned long systemStack;
	int loopCount
	int loopCount2;
	char* testString = malloc(50);
	char* testString2 = malloc(1000);

	PCB_p idl = PCB_construct();
	PCB_init(idl);
	PCB_set_pid(idl, 0xFFFFFFFF);
	PCB_set_state(idl, running);

	PCB_p currentPCB = idl;
	FIFO createFIFO = FIFO_construct();
	FIFO readyFIFO = FIFO_construct();
	
	for (loopCount = 0; i < 6; i++) {
		int newProcess = rand() % 6;
		for (loopCount2 = 0; loopCount2 < newProcess; loopCount2++) {
			PCB_p p = PCB_construct();
			PCB_init(p);
			PCB_set_pid(p, (i << 4) + loopCount2);
			enqueue(createFIFO, p);
			//printf("Created:    ");
			//printf(PCB_toString(p, testString);
		}
	}

	if (PCB_get_pid(currentPCB) != 0xFFFFFFFF) {
		systemStack += pcRand();
	}

	//printf("Switching from PCB  ");
	//printf(PCB_toString(currentPCB, testString);

	timerInterupt();
	//printf(FIFO_toString(readyQueue, testString2);



	/*
	loopCount = 1;
	SysStack = 0;
	unsigned int pcValue = pcRand();
	FIFO processQueue = FIFO_construct();
	FIFO_init(processQueue);


	while (loopCount) {
	// function that creates a random number of new processes, between 0 and 5 and puts them in the list
	*/


		printf("Random Int %lu " + pcRand());
		printf("Random Int %lu " + pcRand());
		printf("Random Int %lu " + pcRand());
	} 

	return 0;

}
