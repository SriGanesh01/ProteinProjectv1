#include "AllHeader.h"
#include "toolkit.h"
#include "imgui.h"

// Static variable to track minimized state
static bool isMinimized = true; // We can keep this for future expansion logic, but toolkit remains minimized

void MainToolkit()
{
    ImGuiIO& io = ImGui::GetIO(); // Get I/O object for display properties

    // Minimized state of the toolkit with small icon buttons (permanently minimized)
    ImGui::SetNextWindowPos(ImVec2(io.DisplaySize.x - 50, 0)); // Small strip on the right
    ImGui::SetNextWindowSize(ImVec2(50, io.DisplaySize.y));    // Height with minimized width

    ImGui::Begin("Toolkit", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar);

    // Calculate available height and slightly move icons upward from the center
    int totalIcons = 5;                   // Total number of icon buttons
    float buttonHeight = 40.0f;           // Height of each button
    float totalButtonHeight = totalIcons * buttonHeight;
    float availableHeight = io.DisplaySize.y;
    float topPadding = (availableHeight - totalButtonHeight) / 2.0f - 20.0f; // Adjust to move icons up

    ImGui::SetCursorPosY(topPadding); // Set the Y position to start slightly above center

    // Single-letter icons for Move, Draw, Notes, Delete, and Share
    if (ImGui::Button("M", ImVec2(40, 40))) {
        // Handle move action (M for Move)
    }
    if (ImGui::Button("D", ImVec2(40, 40))) {
        // Handle draw action (D for Draw)
    }
    if (ImGui::Button("N", ImVec2(40, 40))) {
        // Handle notes action (N for Notes)
    }
    if (ImGui::Button("X", ImVec2(40, 40))) {
        // Handle delete action (X for Delete)
    }
    if (ImGui::Button("S", ImVec2(40, 40))) {
        // Handle share action (S for Share)
    }

    ImGui::End();
}
