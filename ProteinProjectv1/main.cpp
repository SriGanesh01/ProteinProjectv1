#include <wpframework.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
// Window dimensions
const GLint WIDTH = 800, HEIGHT = 600;
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)

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
		GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window",
			NULL, NULL);
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
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		ImGui::Begin("Test Window");
		ImGui::Text("Hello World");
		ImGui::End();
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
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