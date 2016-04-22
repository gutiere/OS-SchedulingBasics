/*
 * Group 3 OS ADTs
 * Spring 2016
 * Authors: Gabriel Houle & Edgardo Gutierrez Jr.
 * GitHub: https://github.com/ghoule636/OS-ADTs.git
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef enum state_type {new, ready, running, interrupted, waiting, halted} state_type;

typedef struct PCB {
  unsigned long pid;        // process ID #, a unique number
  enum state_type state;    // process state (running, waiting, etc.)
  unsigned short priority;  // priorities 0=highest, 15=lowest
  unsigned long pc;         // holds the current pc value when preempted
} PCB;

typedef struct PCB * PCB_p;

PCB_p PCB_construct(void); // returns a pcb pointer to heap allocation
void PCB_destruct(PCB_p);  // deallocates pcb from the heap
void PCB_init(PCB_p);       // sets default values for member data
void PCB_set_pid(PCB_p, unsigned long pid); //sets value of pid for this process
unsigned short PCB_get_priority(PCB_p);
void PCB_set_priority(PCB_p, unsigned short);
void PCB_set_state(PCB_p, state_type);
state_type PCB_get_state(PCB_p);
unsigned long PCB_get_pid(PCB_p);  // returns pid of the process

void PCB_toString(PCB_p, char *);  // returns a string representing the contents of the pcb

#ifndef ADT
#define ADT
#include "PCB.c"
#endif
