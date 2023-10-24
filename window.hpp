#pragma once

class OWindow {

    public:
        OWindow();
        ~OWindow();

        void makeCurrentContext();
        void present(bool vsync);

        // void onDestroy();
        // bool isClosed();
    private:
        void* m_handle = nullptr;
        void* m_context = nullptr;

};