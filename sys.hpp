#pragma once

#include "mmu.hpp"

namespace SYS {

    extern u32 VTOR;

    void init();

    extern MMU::Layout layout;


}
