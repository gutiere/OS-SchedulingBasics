/*
 * Group 3 OS ADTs
 * Spring 2016
 * Authors: Gabriel Houle & Edgardo Gutierrez Jr.
 * GitHub: https://github.com/ghoule636/OS-ADTs.git
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PCB.h"

typedef struct Node {
    PCB_p data;
	struct Node* next;
} Node;

typedef struct FIFO {
    int size;
    struct Node* head;
    struct Node* tail;
} *FIFO;

FIFO FIFO_construct(void);
void FIFO_deconstruct(FIFO);
void FIFO_init(FIFO);
void FIFO_toString(FIFO, char *);
void enqueue(FIFO, PCB_p);
PCB_p dequeue(FIFO);

#ifndef Q
#define Q
#include "FIFO.c"
#endif
