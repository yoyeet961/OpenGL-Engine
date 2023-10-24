#pragma once
#include "math.h"

class OGraphicsEngine {
    public:
        OGraphicsEngine();
        ~OGraphicsEngine();

    public:
        OVertexArrayObjectPtr createVertexArrayObject(const OVertexBufferData& data);

    public:
        void clear(const OVec4 color);
        void setViewport(const ORect& size);
        void setVertexArrayObject(const OVertexArrayObjectPtr& vao);
        void drawTriangles(ui32 vertexCount, ui32 offset);
};