#include<glad/gl.h>
#include<glm/glm.hpp>
#include<glm/gtc/constants.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<Circle.h>
#include<Shader.h>


// Initializing static variables
int Circle::count = 0;
Shader* Circle::shader  = nullptr; 
unsigned int Circle::VAO = 0;
unsigned int Circle::VBO = 0;
std::vector<float> Circle::vertices = {0.0f,0.0f};

void Circle::setup()
{
    //  Setup vertices
    const int N = 64;

    for (int i = 0 ;i <= N; i ++)
    {
        float a = 2.0f* glm::pi<float>() * static_cast<float> (i)/N;
        vertices.push_back(glm::cos(a));
        vertices.push_back(glm::sin(a));
    } 
    // Generate VBO and VAO

    glGenBuffers(1,&VBO);
    glGenVertexArrays(1,&VAO);

    glBindVertexArray(VAO);

    //Buffer Definition on the GPU
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,vertices.size()*sizeof(float),vertices.data(),GL_STATIC_DRAW);

    // Vertex Attributes defintions
    glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,2*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);

    shader  =  new Shader("../Shaders/Circle.vs","../Shaders/Circle.fs");

    // Has to called for the first instance of the object
}

Circle::Circle(float radius,glm::vec2 Position)
{   
    count++;
    if(count == 1)
    {
        // this is the first instance so
        setup();
    }
    // initialize the instance of the object with its position and scale
    this->radius = radius;
    this->Position = Position;

}

void Circle::Draw(glm::mat4 Projection)
{
    glm::mat4 model = glm::translate(glm::mat4(1.0f),glm::vec3(Position,0.0f));
    model = glm::scale(model,glm::vec3(radius,radius,1.0f));
    shader->use();
    shader->setMat4("model",model);
    shader->setMat4("projection",Projection);
    shader->setVec3("Color",Color);

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLE_FAN,0,vertices.size()/2);

}

// Fix needed will do later
void Circle::Clean()
{
    glDeleteVertexArrays(1,&VAO);
    glDeleteBuffers(1,&VBO);
}

void Circle::SetColor(glm::vec3 Color)
{
    this->Color = Color;
}