#include<glm/glm.hpp>
#include<Shader.h>

class Triangle{
    private:
         unsigned int VAO;
         unsigned int VBO;
        static Shader* shader;
        static int count;
        std::vector<float> vertices;
        glm::vec3 Color = glm::vec3(1.0f,0.0f,0.0f);
        //void setup();

    public:
        glm::vec2 Position;
        
        Triangle(glm::vec2 A,glm::vec2 B,glm::vec2 C);
        //Triangle(float A_x,float A_y,float B_x,float B_y,float C_x,float C_y);
        void Draw(glm::mat4 Projection);
        void Clean();
};