#ifndef ISR_BASE_HH
#define ISR_BASE_HH

#include <stdint.h>
extern uint32_t _estack; // linker defined variable - is a stack size

extern "C" {
    namespace isr {
        struct vectors // table of pointer to interrupt vectors - arm cortex-m4 core interrupts
        {
            uint32_t *estack; /*! stack begin */
            void (*reset)           (); /*!#0 cortex-m4 reset interrupt begin code of this */
            void (*NMI)             (); /*!#1 cortex-m4 non maskable interrupt */
            void (*hard_fault)      (); /*!#2 cortex-m4 hardware fault interrupt */
            void (*mem_manage)      (); /*!#3 cortex-m4 memory management interrupt */
            void (*bus_fault)       (); /*!#4 cortex-m4 bus fault interrupt */
            void (*usage_fault)     (); /*!#5 cortex-m4 usage fault interrupt */
            void (*__unused0[4])    (); /*!#6-9 reserved */
            void (*SVC)             (); /*!#10 cortex-m4 system service interrupt */
            void (*debug_mon)       (); /*!#11 cortex-m4 debug monitor interrupt */
            void (*__unused1[1])    (); /*!#12 reserved */
            void (*pend_SV)         (); /*!#13 cortex-m4 penable request for system service interrupt */
            void (*sys_tick_timer)  (); /*!#14 cortex-m4 system tick timer interrupt */
        };

        void reset();
        void NMI();
        void hard_fault();
        void mem_manage();
        void bus_fault();
        void usage_fault();
        void SVC();
        void debug_mon();
        void pend_SV();
        void sys_tick_timer();
    }
}

#endif // ISR_BASE_HH
