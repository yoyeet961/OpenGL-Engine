#pragma once
#include "math.h"

class OGraphicsEngine {
    public:
        OGraphicsEngine();
        ~OGraphicsEngine();

    public:
        void clear(const OVec4 color);
};