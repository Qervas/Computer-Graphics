//
// Created by franktudor on 6/4/22.
//
#include "ve_pipeline.hpp"
#include<fstream>
#include<stdexcept>
namespace ve{
    std::vector<char> VePipeline::readFile(const std::string &filepath) {

        std::ifstream file(filepath, std::ios::ate | std::ios::binary);
        if(!file.is_open()){
            throw std::runtime_error("failed to open file " + filepath);
        }
        size_t fileSize = static_cast<size_t>(file.tellg());
        std::vector<char> buffer(fileSize);
        file.seekg(0);//start of file
        file.read(buffer.data(), fileSize);
        file.close();
        return buffer;
    }

    void VePipeline::createGraphicsPipleline(const std::string &vertFilepath, const std::string &fragFilepath) {
        auto vertCode = readFile(vertFilepath);
        auto fragCode = readFile(fragFilepath);
        std::cout << "Vertex Shader Code Size: " << vertCode.size() << "\n" \
                     "Fragment Shader Code Size: " << fragCode.size() << "\n";
    }
}