/*
 * Group 1
 * Spring 2016
 * Authors: Edgardo Gutierrez Jr. & Antonio V. Alvillar
 * GitHub: https://github.com/gutiere/OS-SchedulingBasics.git
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

	Node_p temp = (Node_p) malloc(sizeof(Node));
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
    Node_p temp = theFIFO->head;
	theFIFO->head = theFIFO->head->next;
    free(temp);
    temp = NULL;
	}
    if (value != NULL) theFIFO->size = theFIFO->size - 1;

    return value;
}

int FIFO_size(FIFO queue) {
    if(queue == NULL) {
        return -1;
    } else {
        return queue->size;
    }
}

int FIFO_toString_size(FIFO queue) {
    int header_size = 6;
    int PCBs_size = (100 + 4) * FIFO_size(queue);
    return header_size + PCBs_size + 1;
}

char* FIFO_toString(FIFO queue, char* string, int size) {
    strcat(string, "Head: ");
    Node_p head = queue->head;
    while (head != NULL) {
        char* pcb_string = malloc(100);
        PCB_toString(head->data, pcb_string);
        strcat(string, pcb_string);
        free(pcb_string);

        if(head->next != NULL) {
            strcat(string, " -> ");
        }
        head = head->next;
    }
    return string;
}
