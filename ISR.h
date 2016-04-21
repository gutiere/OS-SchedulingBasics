//
// Created by hlawr_000 on 4/20/2016.
//

#ifndef OSHW2_ISR_H
#define OSHW2_ISR_H

#include "PCB.h"
#include "FIFO.h"

enum Interrupts {
    TIMER
};

PCB_p timerEvent(FIFO queue, PCB_p pcb, int pc);


#endif //OSHW2_ISR_H
