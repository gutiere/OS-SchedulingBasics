#include "PCB.h"
#include "FIFO.h"
#include <stdio.h>
#include <stdlib.h>

unsigned long systemStack;
int loopCount;
int loopCount2;
unsigned int pc;

enum Interrupts {
    TIMER
};

PCB_p dispatch(FIFO queue) {
    PCB_p pcb = dequeue(queue);
    systemStack = pcb->pc;
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

PCB_p timerInterrupt(FIFO queue, PCB_p pcb, unsigned int pc) {
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
	FILE *output = fopen("sceduleTrace.txt", "w");
	fprintf(output, "Antonio V. Alvillar\n");
	fprintf(output, "Elijah (didnt look up your name LOL)\n\n");
	printf("\n");
	pcValue = pcRand();
	int loopCount;
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
	
	for (loopCount = 0; loopCount < 6; loopCount++) {
		int newProcess = rand() % 6;
		for (loopCount2 = 0; loopCount2 < newProcess; loopCount2++) {
			PCB_p p = PCB_construct();
			PCB_init(p);
			PCB_set_pid(p, (loopCount << 4) + loopCount2);
			enqueue(createFIFO, p);
			printf("Created:    ");
			PCB_toString(p, testString);
			printf(testString);
			fprintf(output, "Created:  %s", testString);
		}

		if (PCB_get_pid(currentPCB) != 0xFFFFFFFF) {
			systemStack += pcRand();
		}
		printf("Switching: ");
		PCB_toString(currentPCB, testString);
		printf(testString);
		fprintf(output, "Switching:  %s", testString);
		PCB_p timerPCB = timerInterrupt(readyFIFO, currentPCB, pc);
		printf("\nQueue: ");
		FIFO_toString(readyFIFO, testString2);
		printf(testString2);
		printf("\n");
		fprintf(output, "\nQueue:  %s\n", testString2);
	}

	fclose(output);
	printf("\n");
	return 0;

}
