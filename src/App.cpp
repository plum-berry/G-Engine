#include<App.h>


int App::Init(int Width,int Height)
{
    this->Width = Width;
    this->Height = Height;

    //initializing glfw
    if(!glfwInit())
        return -1;

    //setup a opengl context
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHintString(GLFW_WAYLAND_APP_ID, "flock_sim");

    window= glfwCreateWindow(Width, Height, "Flock Sim", nullptr, nullptr);

    if (!window)   
    { 
        glfwTerminate(); 
        return -1; 
    }
    glfwMakeContextCurrent(window);

    // loading opengl functions
    int version = gladLoadGL(glfwGetProcAddress);
    
    if (!version) 
    { 
        std::fprintf(stderr, "GLAD failed\n"); 
        return -1; 
    }

    std::printf("OpenGL %d.%d\n", GLAD_VERSION_MAJOR(version), GLAD_VERSION_MINOR(version));

    // setting up callbacks
    glfwSetWindowUserPointer(window,this);
    glfwSetFramebufferSizeCallback(window,FramebufferSizeCB);

    glm::mat4 projection = glm::ortho(0.0f,(float)Width,0.0f,(float)Height);   

    return 0;

}

void App::FramebufferSizeCB(GLFWwindow* window,int width,int height)
{
    static_cast<App*>(glfwGetWindowUserPointer(window))->OnResize(width,height);
}

void App::OnResize(int width,int height)
{
    Width = width; Height = height;
    glViewport(0,0,width,height);
}

void App::ProcessInputs()
{
    if (glfwGetKey(GetWindow(), GLFW_KEY_ESCAPE)==GLFW_PRESS)
    {
        glfwSetWindowShouldClose(GetWindow(),true);
    }
}

void App::DrawBG()
{
    glClearColor(0.1,0.1f,0.1f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void App::Destroy()
{
    glfwTerminate();
}

void App::Update()
{
    projection = glm::ortho(0.0f,(float)Width,0.0f,(float)Height);
}