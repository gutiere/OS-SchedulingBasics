//
// Created by hlawr_000 on 4/20/2016.
//

#ifndef OSHW2_SCHEDULER_H
#define OSHW2_SCHEDULER_H

#include "PCB.h"
#include "FIFO.h"
#include "ISR.h"

PCB_p reschedule(FIFO queue, PCB_p pcb, enum Interrupts interrupt);

#endif //OSHW2_SCHEDULER_H
