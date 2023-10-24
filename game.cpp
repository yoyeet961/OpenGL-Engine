#include "game.hpp"
#include "window.hpp"
#include "graphics.hpp"
#include <windows.h>
#include "vertexArrayObject.hpp"


OGame::OGame() {
    m_graphicsEngine = std::make_unique<OGraphicsEngine>();
    m_display = std::make_unique<OWindow>();

    m_display->makeCurrentContext();

    m_graphicsEngine->setViewport(m_display->getInnerSize());
}

OGame::~OGame() {
    // delete m_display;
}

/**
 * Runs the game.
 *
 * @return void
 *
 * @throws None
 */
void OGame::run() {
    onCreate();
    MSG msg;
    while (isRunning /*&& !m_display->isClosed()*/) {
        if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE)) {
            if (msg.message == WM_QUIT) {
                isRunning = false;
            }
            else {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }

        onUpdate();
    }

    onQuit();
}

void OGame::quit() {
    isRunning = false;
}

void OGame::onCreate() {
    const f32 triangleVertices[] = {
      -0.5f,-0.5f, 0,
      0.5f, -0.5f, 0.0f,
      0.0f, 0.5f, 0.0f
    };

    m_graphicsEngine->createVertexArrayObject({ (void*)triangleVertices, sizeof(f32)*3,3 });
}

/**
 * Updates the game state and handles rendering.
 */
void OGame::onUpdate() {
    m_graphicsEngine->clear(OVec4(0.0f, 1.0f, 0.0f, 1.0f));

    m_graphicsEngine->setVertexArrayObject(m_triangleVAO);

    m_graphicsEngine->drawTriangles(3, 0);

    m_display->present(false);
}

void OGame::onQuit() {
    
}