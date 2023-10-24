#pragma once
#include "prerequisites.h"

class OVertexArrayObject {
    public:
        OVertexArrayObject(const OVertexBufferData& data);
        ~OVertexArrayObject();

        ui32 vertexArrayObjectId = 0;
        ui32 vertexBufferId = 0;
        
};