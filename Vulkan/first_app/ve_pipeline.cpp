//
// Created by franktudor on 6/4/22.
//
#include "ve_pipeline.hpp"
#include<fstream>
#include<stdexcept>
#include<iostream>
#include<filesystem>
namespace ve{


    VePipeline::VePipeline(VeDevice& device, const std::string &vertFilepath, const std::string &fragFilepath,
                           const PipelineConfigInfo& configInfo):veDevice(device) {
        createGraphicsPipleline(vertFilepath, fragFilepath, configInfo);
    }
    std::vector<char> VePipeline::readFile(const std::string &filepath) {
        std::string path = std::filesystem::current_path().parent_path().string();
        path += "/" + filepath;
        std::ifstream file(path, std::ios::ate | std::ios::binary);
        if(!file.is_open()){
            throw std::runtime_error("failed to open file " + path);
        }
        size_t fileSize = static_cast<size_t>(file.tellg());
        std::vector<char> buffer(fileSize);
        file.seekg(0);//start of file
        file.read(buffer.data(), fileSize);
        file.close();
        return buffer;
    }

    void VePipeline::createGraphicsPipleline(const std::string &vertFilepath, const std::string &fragFilepath,
                                             const PipelineConfigInfo& configInfo) {
        auto vertCode = readFile(vertFilepath);
        auto fragCode = readFile(fragFilepath);
        std::cout << "Vertex Shader Code Size: " << vertCode.size() << "\n" \
                     "Fragment Shader Code Size: " << fragCode.size() << "\n";
    }
    void VePipeline::createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule){
        VkShaderModuleCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());
        if(vkCreateShaderModule(veDevice.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS){
            throw std::runtime_error("failed to create shader module");
        }
    }

    PipelineConfigInfo VePipeline::defaultPipelineConfigInfo(uint32_t width, uint32_t height){
        PipelineConfigInfo configInfo{};
        return configInfo;
    }
}