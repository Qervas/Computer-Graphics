//
// Created by franktudor on 6/3/22.
//

#pragma once
#include<string>
#include<vector>
namespace ve{
class VePipeline{
public:
    VePipeline(const std::string& vertFilepath, const std::string& fragFilepath);

private:
    static std::vector<char> readFile(const std::string& filepath);

    void createGraphicsPipleline(const std::string& vertFilepath, const std::string& fragFilepath);

};
}//namepsace ve
