//#ifndef SHADER_LOADER_H
//#define SHADER_LOADER_H
//
//#include <string>
//#include <fstream>
//#include <sstream>
//#include <iostream>
//
//class ShaderLoader {
//public:
//    static std::string loadShaderFromFile(const std::string& filePath) {
//        std::ifstream file(filePath);
//        std::stringstream buffer;
//
//        if (!file.is_open()) {
//            std::cerr << "ERROR: Could not open shader file: " << filePath << std::endl;
//            return "";
//        }
//
//        buffer << file.rdbuf();
//        return buffer.str();
//    }
//};
//
//#endif
