#include "vertexArrayObject.hpp"
#include "glad.h"

OVertexArrayObject::OVertexArrayObject(const OVertexBufferData& data)
{
    glGenBuffers(1, &vertexBufferId);


    glGenVertexArrays(1, &vertexArrayObjectId);
    glBindVertexArray(vertexArrayObjectId);
    
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);  
    glBufferData(GL_ARRAY_BUFFER, data.vertexSize * data.listSize, data.verticesList, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, data.vertexSize, /*(void*)*/0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
}

OVertexArrayObject::~OVertexArrayObject()
{
    glDeleteBuffers(1, &vertexBufferId);
    glDeleteVertexArrays(1, &vertexArrayObjectId);
}

ui32 OVertexArrayObject::getId()
{
    return vertexArrayObjectId;
}