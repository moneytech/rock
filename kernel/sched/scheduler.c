#include <sched/scheduler.h>
#include <acpi/madt.h>
#include <bitmap.h>
#include <output.h>
#include <sched/smp.h>

static uint64_t ready = 0, task_cnt = 0;
static task_t *tasks;

static void reschedule(regs_t *regs);

static core_local_t *core_local;

void scheduler_main(regs_t *regs) {
    static char lock = 0;
    spin_lock(&lock);

    if(!ready) { 
        spin_release(&lock);
        return;                 
    }

    reschedule(regs);

    spin_release(&lock);
}

void scheduler_init() {
    tasks = kmalloc(sizeof(task_t) * 20); 
    core_local = kmalloc(sizeof(core_local_t) * madt_info.ent0cnt);
    for(uint8_t i = 0; i < madt_info.ent0cnt; i++) {
        core_local[i] = (core_local_t) { -1, -1 };
    }

    kvprintf("[SCHED] the scheduler is now pogging\n");
    ready = 1;
}

static void reschedule(regs_t *regs) {
    uint16_t core_index = 0;
    asm volatile ("mov %%gs, %0" : "=r"(core_index));

    int last_pid = core_local[core_index].current_pid;
    int last_tid = core_local[core_index].current_tid;

    int next_pid = 0;
    int next_tid = 0;

    if(last_tid == -1) {
        
    }
}
