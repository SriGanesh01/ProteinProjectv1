#include "activity_bar.h"
#include "AllHeader.h"
#include "imgui.h"

// Static variables to track minimized state and icon sizes for the Activity Bar
static bool isActivityBarMinimized = false;

void MainActivityBar()
{
    ImGuiIO& io = ImGui::GetIO(); // Get I/O object for display properties

    if (!isActivityBarMinimized)
    {
        // Expanded state of the Activity Bar
        ImGui::SetNextWindowPos(ImVec2(0, 0)); // Position on the left
        ImGui::SetNextWindowSize(ImVec2(200, io.DisplaySize.y));     // Full height on the side

        ImGui::Begin("Activity Bar", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar);

        // Add buttons/icons for the Activity Bar
        if (ImGui::Button("Files", ImVec2(180, 40))) {
            // Handle files action
        }
        if (ImGui::Button("Extensions", ImVec2(180, 40))) {
            // Handle extensions action
        }
        if (ImGui::Button("Plugins", ImVec2(180, 40))) {
            // Handle plugins action
        }

        // Minimize button to shrink the activity bar
        if (ImGui::Button("Minimize", ImVec2(180, 40))) {
            isActivityBarMinimized = true;
        }

        ImGui::End();
    }
    else
    {
        // Minimized state of the Activity Bar with small icon buttons
        ImGui::SetNextWindowPos(ImVec2(0, 0)); // Small strip on the left
        ImGui::SetNextWindowSize(ImVec2(50, io.DisplaySize.y));    // Height with minimized width

        ImGui::Begin("Activity Bar", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar);

        // Calculate available height and center icons
        int totalIcons = 3;                   // Total number of icon buttons
        float buttonHeight = 40.0f;           // Height of each button
        float totalButtonHeight = totalIcons * buttonHeight;
        float availableHeight = io.DisplaySize.y;
        float topPadding = (availableHeight - totalButtonHeight) / 2.0f; // Calculate top padding to center icons

        ImGui::SetCursorPosY(topPadding); // Set the Y position to start from the center

        // Icons to represent the options (you can replace text with actual icons)
        if (ImGui::Button("F", ImVec2(40, 40))) {
            // Handle files action (minimized icon for Files)
        }
        if (ImGui::Button("E", ImVec2(40, 40))) {
            // Handle extensions action (minimized icon for Extensions)
        }
        if (ImGui::Button("P", ImVec2(40, 40))) {
            // Handle plugins action (minimized icon for Plugins)
        }

        // Button to expand the activity bar
        if (ImGui::Button(">", ImVec2(40, 40))) {
            isActivityBarMinimized = false;  // Expand the activity bar when clicked
        }

        ImGui::End();
    }
}
