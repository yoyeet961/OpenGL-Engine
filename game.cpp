#include "game.hpp"
#include "window.hpp"
#include "graphics.hpp"
#include <windows.h>

OGame::OGame() {
    m_graphicsEngine = std::make_unique<OGraphicsEngine>();
    m_display = std::make_unique<OWindow>();

    m_display->makeCurrentContext();
}

OGame::~OGame() {
    // delete m_display;
}

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
    m_graphicsEngine->clear(OVec4(0.0f, 1.0f, 0.0f, 1.0f));



    m_display->present(false);
}

void OGame::onUpdate() {
    
}

void OGame::onQuit() {
    
}