//
// Created by franktudor on 6/3/22.
//
#include"first_app.hpp"

namespace ve{
    void FirstApp::run() {
        while(!veWindow.shouldClose()){
            glfwPollEvents();
        }

    }

}
