/*
 * Group 1
 * Spring 2016
 * Authors: Edgardo Gutierrez Jr. & Antonio V. Alvillar
 * GitHub: https://github.com/gutiere/OS-SchedulingBasics.git
 */

#include "PCB.h"
#include "FIFO.h"
#include <stdio.h>
#include <stdlib.h>

typedef enum interrupt_type {
    TIMER
} Interrupt;

int CYCLES = 100;           // Number of cycles to execute
unsigned long systemStack;  // "can just be a global integer as it will be accessed from multiple locations"
unsigned int pc;            // "use an unsigned int in C for the PC"

FIFO readyQueue;
FIFO terminationQueue;
PCB_p current_process;
PCB_p idle_process;
FILE *output;

void instantiations();
void createProcesses();
void runCurrentProcess();
void pseudoISR();
void scheduler();
void dispatcher();
void pseudoIRET();

int main() {

    instantiations();

    // "main loop in which each cycle represents a timer quantum"
    for (int i = 0; i < CYCLES; i++) {
        // "call to a function that creates a random number of new processes, between 0 and 5 and puts them in the list"
        createProcesses();

        // "simulate the running of the current process"
        runCurrentProcess();

        // "do a pseudo-push of the PC to the system stack"
        systemStack = pc;

        // "a pseudo-ISR for the timer"
        pseudoISR();

    }

    fclose(output);
	return 0;
}

void instantiations() {
    // Instantiate Ready Queue
    readyQueue = FIFO_construct();
    FIFO_init(readyQueue);

    // Instantiate Termination Queue
    terminationQueue = FIFO_construct();
    FIFO_init(terminationQueue);

    // Instantiate Idle Process
    idle_process = PCB_construct();
    PCB_init(idle_process);
    PCB_set_state(idle_process, running);
    PCB_set_pc(idle_process, pc);
    PCB_set_pid(idle_process, 0xFFFFFFFF);

    // Instantiate Current Process
    current_process = idle_process;

    // Instantiate Ouput File
    output = fopen("scheduleTrace.txt", "w");
	fprintf(output, "Antonio V. Alvillar\n");
	fprintf(output, "Edgardo C. Gutierrez\n\n");
}

void createProcesses() {
	for (int i = 0; i < rand() % 5; i++) {

        PCB_p new_process = PCB_construct();
        PCB_init(new_process);
        PCB_set_pid(new_process, (unsigned long) rand());
        PCB_set_state(new_process, new);
        enqueue(readyQueue, new_process);

        char* pcb_string = malloc(100);
        PCB_toString(new_process, pcb_string);
        fprintf(output, "Enqueued PCB: %s\n", pcb_string);
        free(pcb_string);
	}
}

void runCurrentProcess() {
    // "add a PC value to the PCB"
    PCB_set_pc(current_process, pc);

    // "increment the PC value by a random number between 3,000 and 4,000"
    pc += rand() % 1000 + 3000;
}

void pseudoISR() {
    // "change the state of the running process to interrupted"
    PCB_set_state(current_process, interrupted);

    // "save the CPU state to the PCB for that process"
    PCB_set_pc(current_process, pc);

    // "do an up-call" ?

    // pseudo-ISR calls the scheduler
    scheduler(TIMER);

    // "perform a pseudo-IRET"
    pseudoIRET();
}

void scheduler(Interrupt interrupt_type) {
    // "scheduler can determine that it only needs to..."
    switch(interrupt_type) {
        case TIMER:
            // "needs to put the process back into the ready queue"
            enqueue(readyQueue, current_process);

            // "change its state from interrupted to ready"
            PCB_set_state(current_process, ready);

            // "It then calls the dispatcher"
            dispatcher();

            // "do any additional housekeeping at this time, but for now there is really nothing to do"
            PCB_p terminated_process;
            do {
                terminated_process = dequeue(terminationQueue);
                if (terminated_process != NULL) {
                    PCB_destruct(terminated_process);
                }
            } while(terminated_process != NULL);

            break;
    }
}

void dispatcher() {
    // "save the state of the current process into its PCB"
    PCB_set_pc(current_process, pc); // "(here we mean the PC value)"

    // "dequeue the next waiting process (PCB)"
    current_process = dequeue(readyQueue);

    // The ready queue was empty
    if (current_process == NULL) {
        current_process = idle_process;
    }

    // "change its state to running"
    PCB_set_state(current_process, running);

    // "copy its PC value to the SysStack location to replace the PC of the interrupted process."
    systemStack = PCB_get_pc(current_process);

    // "The dispatcher then returns to the scheduler"
}

void pseudoIRET() {
    // "the PC value stored in the SysStack will be put into the PC"
    pc = systemStack;


    // "the next process will be running"


}
