#pragma once
#include<glm/glm.hpp>



//Helper function to normalize RGB Colors
inline glm::vec3 RGB(int r,int g,int b){
    return glm::vec3(r,g,b)/255.0f;
}

namespace Color{
    
    inline const glm::vec3 Black   = RGB(  0,   0,   0);
    inline const glm::vec3 White   = RGB(255, 255, 255);
    inline const glm::vec3 Red     = RGB(255,   0,   0);
    inline const glm::vec3 Green   = RGB(  0, 255,   0);
    inline const glm::vec3 Blue    = RGB(  0,   0, 255);
    inline const glm::vec3 Yellow  = RGB(255, 255,   0);
    inline const glm::vec3 Cyan    = RGB(  0, 255, 255);
    inline const glm::vec3 Magenta = RGB(255,   0, 255);

    // Common extras
    inline const glm::vec3 Orange  = RGB(255, 128,   0);
    inline const glm::vec3 Purple  = RGB(128,   0, 128);
    inline const glm::vec3 Pink    = RGB(255, 105, 180);
    inline const glm::vec3 Brown   = RGB(139,  69,  19);
    inline const glm::vec3 Teal    = RGB(  0, 128, 128);
    inline const glm::vec3 Lime    = RGB(50,  205,  50);
    inline const glm::vec3 Gold    = RGB(255, 215,   0);
    inline const glm::vec3 Navy    = RGB(  0,   0, 128);

    // Grays
    inline const glm::vec3 LightGray = RGB(211, 211, 211);
    inline const glm::vec3 Gray      = RGB(128, 128, 128);
    inline const glm::vec3 DarkGray  = RGB( 64,  64,  64);
}