//
// Created by franktudor on 6/3/22.
//
#pragma once

#define GLFW_INCLUDE_VULKAN
#include<GLFW/glfw3.h>
#include<string>
namespace ve{
    class VeWindow{
    public:
        VeWindow(const int& w, const int& h, const std::string& nanme);
        ~VeWindow();
        VeWindow(const VeWindow& ) = delete;
        VeWindow&operator=(const VeWindow&) = delete;

        bool shouldClose(){return glfwWindowShouldClose(window); }

    private:
        void initWindow();

        const int width;
        const int height;
        std::string windowName;
        GLFWwindow *window;




    };//class VeWindow
}//namespace ve

