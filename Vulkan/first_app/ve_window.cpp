//
// Created by franktudor on 6/3/22.
//

#include "ve_window.hpp"
namespace ve{
    VeWindow::VeWindow(const int& w, const int& h, const std::string& name): width(w), height(h), windowName(name){
        initWindow();
    }
    VeWindow::~VeWindow(){
        glfwDestroyWindow(window);
        glfwTerminate();
    }


    void VeWindow::initWindow(){
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
    }
}