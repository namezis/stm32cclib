#ifndef RCC_D_HH
#define RCC_D_HH

namespace hal {
    volatile rcc_t * const rcc = reinterpret_cast<rcc_t *>(0x40023800);
}

#endif // RCC_D_HH 