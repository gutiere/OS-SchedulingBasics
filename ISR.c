//
// Created by hlawr_000 on 4/20/2016.
//

#include "ISR.h"
#include "Scheduler.h"

PCB_p timerInterrupt(FIFO queue, PCB_p pcb, int pc) {
    pcb->state = interrupted;
    pcb->pc = pc;
    return reschedule(queue, pcb, TIMER);
}