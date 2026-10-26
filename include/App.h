#include<glad/gl.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<cstdio>

class App
{
   private:
       GLFWwindow *window = nullptr;
       int Height = 0, Width = 0;

       static void FramebufferSizeCB(GLFWwindow* window,int width,int height);
       void OnResize(int width,int height);

       glm::mat4 projection = glm::mat4(1.0f);
       
   public:


    int Init(int Width,int Height);
    void ProcessInputs();
    void DrawBG();
    void Destroy();

    bool ShouldClose() const {return glfwWindowShouldClose(window);}
    void SwapBuffers() {glfwSwapBuffers(window);}
    void PollEvents() {glfwPollEvents();}
    void Update();

    GLFWwindow* GetWindow() const {return window;}
    glm::mat4 GetProjection() {return projection;}
    int Get_Height(){return Height;}
    int Get_Width(){return Width;}
};