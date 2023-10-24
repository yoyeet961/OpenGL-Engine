#pragma once
#include "prerequisites.h"

class OVec4
{
    public:
        OVec4() {

        }
        OVec4(f32 x, f32 y, f32 z, f32 w): x(x),y(y),z(z),w(w) {

        }
        ~OVec4() {
            
        }



    public:
        f32 x = 0, y = 0, z = 0, w = 0;
};

class ORect
{
    public:
        ORect(){}
        ORect(i32 width, i32 height):width(width),height(height) {}
        ORect(i32 width, i32 height, i32 left, i32 top):width(width),height(height),left(left),top(top) {}
        ORect(const ORect& rect):width(rect.width),height(rect.height),left(rect.left),top(rect.top) {}

    public:
        i32 width = 0, height = 0, left = 0, top = 0;
};