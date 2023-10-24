#include "game.hpp"
#include "window.hpp"
#include <windows.h>

OGame::OGame() {
    m_display = std::unique_ptr<OWindow>(new OWindow());
}

OGame::~OGame() {
    // delete m_display;
}

void OGame::run() {
    MSG msg;
    while (isRunning && !m_display->isClosed()) {
        if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        Sleep(1);
    }
}

void OGame::quit() {
    isRunning = false;
}