//
// Created by franktudor on 6/3/22.
//

#pragma once
#include "ve_device.hpp"
#include<string>
#include<vector>
namespace ve{

struct PipelineConfigInfo{



};


class VePipeline{
public:
    VePipeline(const VePipeline&) = delete;
    void operator=(const VePipeline&) = delete;
    VePipeline(VeDevice& device, const std::string& vertFilepath, const std::string& fragFilepath,
               const PipelineConfigInfo& configInfo);
    ~VePipeline(){}
    static  PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);


private:
    static std::vector<char> readFile(const std::string& filepath);

    void createGraphicsPipleline(const std::string& vertFilepath, const std::string& fragFilepath,
                                 const PipelineConfigInfo& configInfo);

    void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);


    VeDevice & veDevice;
    VkPipeline  graphicsPipeline;
    VkShaderModule  vertShaderModule;
    VkShaderModule fragShaderModule;
};
}//namepsace ve
