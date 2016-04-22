//
// Created by hlawr_000 on 4/20/2016.
//

#include "Scheduler.h"
#include "Dispatcher.h"

PCB_p reschedule(FIFO queue, PCB_p pcb, enum Interrupts interrupt) {
    if (interrupt == TIMER) {
        pcb->state = ready;
        enqueue(queue, pcb);
        return dispatch(queue);
    }
}