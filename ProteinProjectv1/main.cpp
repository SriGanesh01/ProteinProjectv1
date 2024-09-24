#include "AllHeader.h"
#include "main_ui.h"

using namespace ImGui;

// Window dimensions
const GLint WIDTH = 800, HEIGHT = 600;

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    // Initialize GLFW
    if (!glfwInit())
    {
        printf("GLFW initialization failed\n");
        return 1;
    }
    // Setup GLFW window properties
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // No Backwards Compatibility
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Forward Compatibility
    GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);
    if (!mainWindow)
    {
        printf("GLFW window creation failed\n");
        glfwTerminate();
        return 1;
    }
    // Get buffer size information
    GLint bufferWidth, bufferHeight;
    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);
    // Set context for GLEW to use
    glfwMakeContextCurrent(mainWindow);
    // Allow modern extension features
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        printf("GLEW initialization failed\n");
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return 1;
    }
    // Setup Viewport size
    glViewport(0, 0, bufferWidth, bufferHeight);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(mainWindow, true);
    ImGui_ImplOpenGL3_Init("#version 330");
    // Loop until window closed
    while (!glfwWindowShouldClose(mainWindow))
    {
        glfwPollEvents();
        // Clear window
        glClearColor(1.0f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        MainGUI1();
        glfwSwapBuffers(mainWindow);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    // Clean up and exit
    glfwDestroyWindow(mainWindow);
    glfwTerminate();
    return 0;
}