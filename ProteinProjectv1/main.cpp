#include "AllHeader.h"
#include "main_ui.h"



const GLint WIDTH = 800, HEIGHT = 600;

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
    if (!glfwInit()) {
        printf("GLFW initialization failed\n");
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);
    if (!mainWindow) {
        printf("GLFW window creation failed\n");
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(mainWindow);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        printf("GLEW initialization failed\n");
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return 1;
    }

    GLint bufferWidth, bufferHeight;
    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);
    glViewport(0, 0, bufferWidth, bufferHeight);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(mainWindow, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    // Define the line coordinates
    double x1 = -0.5, y1 = -0.5, z1 = 0.0; // Start point
    double x2 = 0.5, y2 = 0.5, z2 = 0.0;  // End point

	double x3 = -0.5, y3 = 0.5, z3 = 0.0; // Start point
	double x4 = 0.5, y4 = -0.5, z4 = 0.0;  // End point

	double x5 = -0.5, y5 = 0.5, z5 = 0.0; // Start point
	double x6 = 0.5, y6 = 0.5, z6 = 0.0;  // End point

    while (!glfwWindowShouldClose(mainWindow)) {
        glfwPollEvents();
        glClearColor(1.0f, 0.75f, 0.8f, 1.0f);

        glClear(GL_COLOR_BUFFER_BIT);

        //call render function till the file ends
        /*render(x1, y1, z1, x2, y2, z2);
		render(x3, y3, z3, x4, y4, z4);
		render(x5, y5, z5, x6, y6, z6);*/
		SelectLines();

        MainGUI1();
        glfwSwapBuffers(mainWindow);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(mainWindow);
    glfwTerminate();

    return 0;
}
