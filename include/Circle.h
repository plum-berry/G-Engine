#include<glm/glm.hpp>
#include<Shader.h>
class Circle{

    protected:
        static unsigned int VAO;
        static unsigned int VBO;
        static Shader* shader;
        static int count; 
        static std::vector<float> vertices;

        
        float radius;
        glm::vec3 Color = glm::vec3(1.0f,0.0f,0.0f);
        
        void setup(); // will be called upon the first instance of the object

    public:
        glm::vec2 Position;
        void SetColor(glm::vec3 Color);
        Circle(float radius,glm::vec2 Position);
        void Draw(glm::mat4 Projection);
        void Clean();
};
