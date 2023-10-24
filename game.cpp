#include "game.hpp"
#include "window.hpp"
#include "graphics.hpp"
#include <windows.h>

OGame::OGame() {
    m_graphicsEngine = std::make_unique<OGraphicsEngine>();
    m_display = std::make_unique<OWindow>();
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

void onCreate() {
    
}

void onUpdate() {
    
}

void onQuit() {
    
}