#pragma once
#include "math.h"

class OWindow {

    public:
        OWindow();
        ~OWindow();

        ORect getInnerSize();

        void makeCurrentContext();
        void present(bool vsync);

        // void onDestroy();
        // bool isClosed();
    private:
        void* m_handle = nullptr;
        void* m_context = nullptr;

};