#include "graphics.hpp"
#include "vertexArrayObject.hpp"
#include "glad_wgl.h"
#include "glad.h"
#include <assert.h>
#include <stdexcept>

OGraphicsEngine::OGraphicsEngine() {
    WNDCLASSEX wc = {};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpszClassName = "OpenGLDummyWindow";
    wc.lpfnWndProc = DefWindowProc;
    wc.style = CS_OWNDC;

    auto classId = RegisterClassEx(&wc);
    assert(classId);

    auto dummyWindow = CreateWindowEx(NULL, MAKEINTATOM(classId), "OpenGL Engine", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, NULL, NULL);

    assert(dummyWindow);

    auto dummyDC = GetDC(dummyWindow);

    PIXELFORMATDESCRIPTOR pixelFormatDesc = {};
    pixelFormatDesc.nSize = sizeof(PIXELFORMATDESCRIPTOR);
    pixelFormatDesc.nVersion = 1;
    pixelFormatDesc.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pixelFormatDesc.iPixelType = PFD_TYPE_RGBA;
    pixelFormatDesc.cColorBits = 32;
    pixelFormatDesc.cAlphaBits = 8;
    pixelFormatDesc.cDepthBits = 24;
    pixelFormatDesc.cStencilBits = 8;
    pixelFormatDesc.iLayerType = PFD_MAIN_PLANE;



    auto pixelFormat = ChoosePixelFormat(dummyDC, &pixelFormatDesc);
    SetPixelFormat(dummyDC, pixelFormat, &pixelFormatDesc);


    auto dummyContext = wglCreateContext(dummyDC);
    assert(dummyContext);

    wglMakeCurrent(dummyDC, dummyContext);

    if (!gladLoadWGL(dummyDC)) {
        throw std::runtime_error("Failed to run gladLoadWGL");
    }

    if (!gladLoadGL()) {
        throw std::runtime_error("Failed to run gladLoadGL");
    }

    wglMakeCurrent(dummyDC, 0);
    wglDeleteContext(dummyContext);
    ReleaseDC(dummyWindow, dummyDC);
    DestroyWindow(dummyWindow);

}

OGraphicsEngine::~OGraphicsEngine() {
    
}

OVertexArrayObjectPtr OGraphicsEngine::createVertexArrayObject(const OVertexBufferData& data) {
    return std::make_shared<OVertexArrayObject>(data);
}

void OGraphicsEngine::clear(const OVec4 color) {
    glClearColor(color.x, color.y, color.z, color.w);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void OGraphicsEngine::setViewport(const ORect& size) {
    glViewport(size.left, size.top, size.width, size.height);
}

void OGraphicsEngine::setVertexArrayObject(const OVertexArrayObjectPtr& vao) {
    // glBindVertexArray(vao->getId());
    glBindVertexArray(vao->vertexArrayObjectId);
}

void OGraphicsEngine::drawTriangles(ui32 vertexCount, ui32 offset)
{
    glDrawArrays(GL_TRIANGLES, offset, vertexCount);
}
