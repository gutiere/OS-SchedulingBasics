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
