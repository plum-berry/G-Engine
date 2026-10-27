#include<glad/gl.h>
#include<Triangle.h>
#include<Shader.h>

// Static varibales
int Triangle::count = 0;
Shader* Triangle::shader = nullptr;

Triangle::Triangle(glm::vec2 A,glm::vec2 B,glm::vec2 C)
{
    vertices.push_back(A.x);
    vertices.push_back(A.y);
    vertices.push_back(B.x);
    vertices.push_back(B.y);
    vertices.push_back(C.x);
    vertices.push_back(C.y);

    //Generate VBO and VAO
    glGenBuffers(1,&VBO);
    glGenVertexArrays(1,&VAO);

    glBindVertexArray(VAO);

    //Buffer Definition on the GPU
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,vertices.size()*sizeof(float),vertices.data(),GL_STATIC_DRAW);

    // Vertex Attributes defintions
    glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,2*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);

    // temporarily using Cirlcle.vs 
    // TODO: Make a Default Shader2D
    shader  =  new Shader("Shaders/Circle.vs","Shaders/Circle.fs");
}

void Triangle::Draw(glm::mat4 Projection)
{
    glm::mat4 model(1.0f);
    shader->use();
    shader->setMat4("model",model);
    shader->setMat4("projection",Projection);
    shader->setVec3("Color",Color);

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES,0,3);
}

void Triangle::Clean()
{
    glDeleteVertexArrays(1,&VAO);
    glDeleteBuffers(1,&VBO);

}