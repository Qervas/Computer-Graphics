//
// Created by franktudor on 6/3/22.
//
#pragma once

#include"ve_window.hpp"
namespace ve{
    class FirstApp{
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;
        void run();
    private:
        VeWindow veWindow{WIDTH, HEIGHT, "Hello, Vulkan"};
    };


} //namespace ve