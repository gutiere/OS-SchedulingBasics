//
// Created by hlawr_000 on 4/20/2016.
//

#include "Dispatcher.h"
#include "OSMainLoop.c"

PCB_p dispatch(FIFO queue) {
    PCB_p pcb = dequeue(queue);
    SysStack = pcb->pc;
    return pcb;
}