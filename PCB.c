/*
 * Group 1
 * Spring 2016
 * Authors: Edgardo Gutierrez Jr. & Antonio V. Alvillar
 * GitHub: https://github.com/gutiere/OS-SchedulingBasics.git
 */

#ifndef ADT
#define ADT
#include "PCB.h"
#endif

PCB_p PCB_construct(void) {
  PCB_p result = malloc(sizeof(PCB));
  return result;
}

void PCB_destruct(PCB_p thePCB) {
  if (thePCB) {
    free(thePCB);
  }
}

void PCB_init(PCB_p thePCB) {

  //not sure what values to give.

  thePCB->state = new;
  thePCB->priority = 15; // lowest priority is default
  thePCB->pid = 0;
  thePCB->pc = 0;
}

void PCB_set_pid(PCB_p thePCB, unsigned long thePID) {
  if (thePID) {
    thePCB->pid = thePID;
  }
}

unsigned short PCB_get_priority(PCB_p thePCB) {
  return thePCB->priority;
}

void PCB_set_priority(PCB_p thePCB, unsigned short theNum) {
  if (theNum) {
    thePCB->priority = theNum;
  }
}

unsigned long PCB_get_pid(PCB_p thePCB) {
  return thePCB->pid;
}

void PCB_set_state(PCB_p thePCB, state_type theState) {
  if (theState) {
    thePCB->state = theState;
  }
}

state_type PCB_get_state(PCB_p thePCB) {
  return thePCB->state;
}

int PCB_set_pc(PCB_p pcb, unsigned long pc) {
    if(pcb == NULL) {
        return -1;
    }
    pcb->pc = pc;
    return 0;
}

unsigned long PCB_get_pc(PCB_p pcb) {
    return pcb->pc;
}

void PCB_toString(PCB_p thePCB, char *theStr) {
  if (theStr) {
    char state[8];

    if (thePCB->state == new) {
      strcpy(state, "new");
    } else if (thePCB->state == ready) {
      strcpy(state, "ready");
    } else if (thePCB->state == running) {
      strcpy(state, "running");
    } else if (thePCB->state == waiting) {
      strcpy(state, "waiting");
    } else if (thePCB->state == halted) {
      strcpy(state, "halted");
    }

    sprintf(theStr, "PID: 0x%lu, State: %s, Priority: 0x%X, PC: 0x%lu\n",
      thePCB->pid, state, thePCB->priority, thePCB->pc);
  }
}
