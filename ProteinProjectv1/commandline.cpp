#include "AllHeader.h"
#include "commandline.h"
#include "imgui.h"

// Static buffer to store input text
static char inputBuffer[256] = "";  // Adjust size if necessary

void MainCommandline()
{
    ImGuiIO& io = ImGui::GetIO(); // Get the ImGui IO object to access display properties

    // Default window size and position
    static float windowWidth = io.DisplaySize.x * 0.8f;  // Initially 80% of the screen width
    static float windowHeight = 80.0f;                   // Increased height for aesthetics
    float xPos = (io.DisplaySize.x - windowWidth) / 2.0f;  // Center horizontally
    float yPos = io.DisplaySize.y - windowHeight - 50.0f;  // Move 50 pixels above the bottom

    // Set the next window's position and size
    ImGui::SetNextWindowPos(ImVec2(xPos, yPos), ImGuiCond_FirstUseEver); // Set the calculated position
    ImGui::SetNextWindowSize(ImVec2(windowWidth, windowHeight), ImGuiCond_FirstUseEver); // Set the initial size

    // Start a new window with a title, remove collapse but allow resizing
    ImGui::Begin("Command Line", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar);

    // Draw a heading for "Command Line"
    ImGui::Text("Command Line"); // Heading label

    ImGui::Separator(); // A horizontal line for separation

    // Input text field for command line
    ImGui::InputText("##CommandInput", inputBuffer, IM_ARRAYSIZE(inputBuffer));

    // Handle input: If 'Enter' is pressed, clear the buffer for now
    if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_Enter))) {
        inputBuffer[0] = '\0'; // Clear after pressing Enter (can be modified to handle actual input)
    }

    ImGui::End();
}
