/*
 * Group 1
 * Spring 2016
 * Authors: Edgardo Gutierrez Jr. & Antonio V. Alvillar
 * GitHub: https://github.com/gutiere/OS-SchedulingBasics.git
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node Node;
typedef Node * Node_p;

struct node {
    PCB_p data;
	Node_p next;
};

typedef struct FIFO {
    int size;
    Node_p head;
    Node_p tail;
} *FIFO;

FIFO FIFO_construct(void);
void FIFO_deconstruct(FIFO);
void FIFO_init(FIFO);
int FIFO_toString_size(FIFO queue);
int FIFO_size(FIFO queue);
char* FIFO_toString(FIFO queue, char* string, int size);
void enqueue(FIFO, PCB_p);
PCB_p dequeue(FIFO);

#ifndef Q
#define Q
#include "FIFO.c"
#endif
