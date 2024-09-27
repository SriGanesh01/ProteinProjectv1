#include "activity_bar.h"
#include "AllHeader.h"
#include "imgui.h"

// Static variables to track the visibility and animation state of the tabs
static bool isFilesTabOpen = false;
static bool isExtensionsTabOpen = false;
static bool isPluginsTabOpen = false;

// Static variable to animate the expansion/retraction of the tab content
static float tabContentWidth = 0.0f;  // Start closed

// Constants to control expansion speed and max width
const float maxTabContentWidth = 250.0f;
const float expansionSpeed = 10.0f;  // Pixels per frame

void MainActivityBar() {
    ImGuiIO& io = ImGui::GetIO();  // Get I/O object for display properties

    // Activity Bar on the left
    ImGui::SetNextWindowPos(ImVec2(0, 0));  // Position on the left
    ImGui::SetNextWindowSize(ImVec2(50, io.DisplaySize.y));  // Fixed small width for the bar
    ImGui::Begin("Activity Bar", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar);

    // Files Button
    if (ImGui::Button("Files", ImVec2(40, 40))) {
        isFilesTabOpen = !isFilesTabOpen;  // Toggle Files tab
        isExtensionsTabOpen = false;
        isPluginsTabOpen = false;
    }

    // Extensions Button
    if (ImGui::Button("Ext", ImVec2(40, 40))) {
        isExtensionsTabOpen = !isExtensionsTabOpen;  // Toggle Extensions tab
        isFilesTabOpen = false;
        isPluginsTabOpen = false;
    }

    // Plugins Button
    if (ImGui::Button("Plug", ImVec2(40, 40))) {
        isPluginsTabOpen = !isPluginsTabOpen;  // Toggle Plugins tab
        isFilesTabOpen = false;
        isExtensionsTabOpen = false;
    }

    ImGui::End();

    // Calculate the target width based on which tab is open
    bool isAnyTabOpen = isFilesTabOpen || isExtensionsTabOpen || isPluginsTabOpen;
    float targetWidth = isAnyTabOpen ? maxTabContentWidth : 0.0f;

    // Animate the width to smoothly expand or retract
    if (tabContentWidth < targetWidth) {
        tabContentWidth += expansionSpeed;  // Expand
        if (tabContentWidth > targetWidth) tabContentWidth = targetWidth;
    }
    else if (tabContentWidth > targetWidth) {
        tabContentWidth -= expansionSpeed;  // Retract
        if (tabContentWidth < targetWidth) tabContentWidth = targetWidth;
    }

    // Only display the content panel if there is any tab open
    if (tabContentWidth > 0.0f) {
        ImGui::SetNextWindowPos(ImVec2(50, 0));  // Start next to the activity bar
        ImGui::SetNextWindowSize(ImVec2(tabContentWidth, io.DisplaySize.y));  // Dynamic width based on animation
        ImGui::Begin("Tab Content", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar);

        // Content for the Files Tab
        if (isFilesTabOpen) {
            ImGui::Text("Files Tab Content");
            if (ImGui::Button("Open File", ImVec2(160, 30))) {
                // Handle open file action
            }
            if (ImGui::Button("Save File", ImVec2(160, 30))) {
                // Handle save file action
            }
            if (ImGui::Button("Close File", ImVec2(160, 30))) {
                // Handle close file action
            }
        }

        // Content for the Extensions Tab
        if (isExtensionsTabOpen) {
            ImGui::Text("Extensions Tab Content");
            if (ImGui::Button("Load Extension", ImVec2(160, 30))) {
                // Handle load extension action
            }
            if (ImGui::Button("Unload Extension", ImVec2(160, 30))) {
                // Handle unload extension action
            }
            if (ImGui::Button("Manage Extensions", ImVec2(160, 30))) {
                // Handle manage extensions action
            }
        }

        // Content for the Plugins Tab
        if (isPluginsTabOpen) {
            ImGui::Text("Plugins Tab Content");
            if (ImGui::Button("Install Plugin", ImVec2(160, 30))) {
                // Handle install plugin action
            }
            if (ImGui::Button("Remove Plugin", ImVec2(160, 30))) {
                // Handle remove plugin action
            }
            if (ImGui::Button("Update Plugin", ImVec2(160, 30))) {
                // Handle update plugin action
            }
        }

        ImGui::End();
    }
}
