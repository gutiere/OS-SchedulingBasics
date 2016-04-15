/*
 * Group 3 OS ADTs
 * Spring 2016
 * Authors: Gabriel Houle & Edgardo Gutierrez Jr.
 * GitHub: https://github.com/ghoule636/OS-ADTs.git
 */

#ifndef Q
#define Q
#include "FIFO.h"
#endif

FIFO FIFO_construct(void) {
    FIFO result = (FIFO) malloc(sizeof(struct FIFO));
    return result;
}

void FIFO_deconstruct(FIFO theFIFO) {
  if (theFIFO) {
    if (theFIFO->head) {
      int size = 0;
      int i;
      size += theFIFO->size;
      for (i = 0; i < size; i++) {
        PCB_destruct(theFIFO->head->data);
        dequeue(theFIFO);
      }
      free(theFIFO);
    }
  }
}

void FIFO_init(FIFO theFIFO) {
  theFIFO->head = NULL;
  theFIFO->tail = NULL;
  theFIFO->size = 0;
}

void enqueue(FIFO theFIFO, PCB_p theElement) {
    theFIFO->size = theFIFO->size + 1;

	struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
	temp->data = theElement;
    temp->next = NULL;
	if(theFIFO->head == NULL && theFIFO->tail == NULL){
		theFIFO->head = theFIFO->tail = temp;
		return;
	}
	theFIFO->tail->next = temp;
	theFIFO->tail = temp;
}


PCB_p dequeue(FIFO theFIFO) {
    PCB_p value = NULL; // No value in queue
	if (theFIFO->head && theFIFO->head == theFIFO->tail) {
    value = theFIFO->head->data;
		theFIFO->head = theFIFO->tail = NULL;
	}
	else if (theFIFO->head != NULL){
    value = theFIFO->head->data;
    Node *temp = theFIFO->head;
	theFIFO->head = theFIFO->head->next;
    free(temp);
    temp = NULL;
	}
    if (value != NULL) theFIFO->size = theFIFO->size - 1;

    return value;
}

void FIFO_toString(FIFO theFIFO, char *theStr) {
    if (theStr) {
        strcpy(theStr, "");
        int i, loops = 0;
        char buf[13];

        loops += theFIFO->size;

        sprintf(buf, "Count=%d: ", loops); // puts string into buffer

        strcat(theStr,buf);
        PCB_p liveData;

        for (i = 1; i <= loops; i++) {
            liveData = dequeue(theFIFO); // Pick off the head of the queue//
            enqueue(theFIFO, liveData); // Put it on the back//

            if (i < loops) sprintf(buf, "P%lu->", liveData->pid);
            if (i == loops) sprintf(buf, "P%lu-*", liveData->pid);
            strcat(theStr,buf);
        }
	}
}
