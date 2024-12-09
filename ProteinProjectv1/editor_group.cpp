#include "editor_group.h"
#include "AllHeader.h"
#include "imgui.h"

// Constants for the activity bar buttons
const char* buttonLabels[] = { "File", "Edit", "View", "Simulate", "Help" };

// Static variables to track the state of the tabs
static bool isFilesTabOpen = false;
static bool isViewTabOpen = false;
static bool isEditTabOpen = false;
static bool isSimulateTabOpen = false;  // State for Simulate tab visibility
static bool isHelpOpen = false;         // State for Help visibility
static bool isSearchOpen = false;       // State for search bar visibility

void MainEditorGroup() {
    //ImGuiIO& io = ImGui::GetIO();  // Get I/O object for display properties

    //// Main Editor Window
    //ImGui::SetNextWindowSize(ImVec2(800, 600), ImGuiCond_FirstUseEver);
    //if (ImGui::Begin("Protein Project Editor")) {
    //    ImGui::Text("Protein Visualization");

    //    // Separator to differentiate content and status bar
    //    ImGui::Separator();

    //    // Main content (placeholder for visualization)
    //    ImGui::Text("Visualization Area (Placeholder)");

    //    // Another separator before the buttons
    //    ImGui::Separator();

    //    // Display buttons and search bar horizontally at the top
    //    ImGui::BeginChild("ButtonPanel", ImVec2(0, 50), false, ImGuiWindowFlags_NoScrollbar);

    //    // Add buttons horizontally
    //    for (int i = 0; i < 5; ++i) {
    //        if (ImGui::Button(buttonLabels[i], ImVec2(150, 40))) {
    //            // Handle button click for File, Edit, View, Simulate, Help
    //            if (i == 0) {  // If the "File" button is clicked
    //                isFilesTabOpen = !isFilesTabOpen;  // Toggle Files tab
    //                isViewTabOpen = false;
    //                isEditTabOpen = false;
    //                isSimulateTabOpen = false;
    //                isHelpOpen = false;
    //            }
    //            if (i == 1) {  // If the "Edit" button is clicked
    //                isEditTabOpen = !isEditTabOpen;  // Toggle Edit tab
    //                isFilesTabOpen = false;
    //                isViewTabOpen = false;
    //                isSimulateTabOpen = false;
    //                isHelpOpen = false;
    //            }
    //            if (i == 2) {  // If the "View" button is clicked
    //                isViewTabOpen = !isViewTabOpen;  // Toggle View tab
    //                isFilesTabOpen = false;
    //                isEditTabOpen = false;
    //                isSimulateTabOpen = false;
    //                isHelpOpen = false;
    //            }
    //            if (i == 3) {  // If the "Simulate" button is clicked
    //                isSimulateTabOpen = !isSimulateTabOpen;  // Toggle Simulate tab
    //                isFilesTabOpen = false;
    //                isViewTabOpen = false;
    //                isEditTabOpen = false;
    //                isHelpOpen = false;
    //            }
    //            if (i == 4) {  // If the "Help" button is clicked
    //                isHelpOpen = !isHelpOpen;  // Toggle Help visibility
    //                isFilesTabOpen = false;
    //                isViewTabOpen = false;
    //                isEditTabOpen = false;
    //                isSimulateTabOpen = false;
    //            }
    //        }
    //        ImGui::SameLine();  // Arrange buttons horizontally
    //    }

    //    // "Search" button to toggle the search bar visibility
    //    if (ImGui::Button("Search", ImVec2(150, 40))) {
    //        isSearchOpen = !isSearchOpen;  // Toggle the search bar visibility
    //    }

    //    // Show the search bar if isSearchOpen is true
    //    if (isSearchOpen) {
    //        static char searchBuffer[128] = "";  // Buffer to hold the search input
    //        ImGui::SameLine();  // Keep search bar on the same line
    //        ImGui::InputText("##search", searchBuffer, sizeof(searchBuffer), ImGuiInputTextFlags_EnterReturnsTrue);  // Search bar with a unique label
    //    }

    //    ImGui::EndChild();

    //    // Show file operations if the Files tab is open
    //    if (isFilesTabOpen) {
    //        ImGui::Text("Files Tab Content");
    //        if (ImGui::Button("Open File", ImVec2(160, 30))) {
    //            // Handle open file action
    //            printf("Open File clicked\n");
    //        }
    //        if (ImGui::Button("Save File", ImVec2(160, 30))) {
    //            // Handle save file action
    //            printf("Save File clicked\n");
    //        }
    //        if (ImGui::Button("Close File", ImVec2(160, 30))) {
    //            // Handle close file action
    //            printf("Close File clicked\n");
    //        }
    //        ImGui::Separator();  // Separator after the file operations
    //    }

    //    // Show edit options if the Edit tab is open
    //    if (isEditTabOpen) {
    //        ImGui::Text("Edit Options");
    //        if (ImGui::Button("Edit Sequence", ImVec2(160, 30))) {
    //            // Handle Edit Sequence action
    //            printf("Edit Sequence clicked\n");
    //        }
    //        if (ImGui::Button("Change Color", ImVec2(160, 30))) {
    //            // Handle Change Color action
    //            printf("Change Color clicked\n");
    //        }
    //        ImGui::Separator();  // Separator after edit options
    //    }

    //    // Show view options if the View tab is open
    //    if (isViewTabOpen) {
    //        ImGui::Text("View Options");
    //        if (ImGui::Button("Explorer", ImVec2(160, 30))) {
    //            // Handle Explorer action
    //            printf("Explorer clicked\n");
    //        }
    //        if (ImGui::Button("Appearance", ImVec2(160, 30))) {
    //            // Handle Appearance action
    //            printf("Appearance clicked\n");
    //        }
    //        if (ImGui::Button("Editor Layout", ImVec2(160, 30))) {
    //            // Handle Editor Layout action
    //            printf("Editor Layout clicked\n");
    //        }
    //        ImGui::Separator();  // Separator after view options
    //    }

    //    // Show simulation options if the Simulate tab is open
    //    if (isSimulateTabOpen) {
    //        ImGui::Text("Simulate Options");
    //        if (ImGui::Button("Start Simulation", ImVec2(160, 30))) {
    //            // Handle Start Simulation action
    //            printf("Start Simulation clicked\n");
    //        }
    //        if (ImGui::Button("End Simulation", ImVec2(160, 30))) {
    //            // Handle End Simulation action
    //            printf("End Simulation clicked\n");
    //        }
    //        ImGui::Separator();  // Separator after simulation options
    //    }

    //    // Show help paragraph if the Help tab is open
    //    if (isHelpOpen) {
    //        ImGui::TextWrapped(
    //            "This editor assists with protein visualization, sequence editing, "
    //            "and running simulations. Use the 'File' tab to open, save, and close files, "
    //            "the 'Edit' tab to modify sequences or change colors, and the 'View' tab "
    //            "to explore different layouts. In the 'Simulate' tab, you can start or stop "
    //            "a protein simulation. For any other queries, feel free to consult the help documentation."
    //        );
    //        ImGui::Separator();  // Separator after the help paragraph
    //    }

    //    // Status Bar (Coordinates)
    //    ImGui::SetNextWindowPos(ImVec2(0, io.DisplaySize.y - 30), ImGuiCond_Always);  // Position at the bottom
    //    ImGui::SetNextWindowSize(ImVec2(io.DisplaySize.x, 30), ImGuiCond_Always);    // Full width

    //    if (ImGui::Begin("Status Bar", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse)) {
    //        // Draw a rectangle (background of the status bar)
    //        ImDrawList* draw_list = ImGui::GetWindowDrawList();
    //        ImVec2 window_pos = ImGui::GetWindowPos();
    //        ImVec2 window_size = ImGui::GetWindowSize();

    //        // Define rectangle coordinates
    //        ImVec2 rect_min = window_pos;
    //        ImVec2 rect_max = ImVec2(window_pos.x + window_size.x, window_pos.y + window_size.y);

    //        // Draw rectangle with light gray color
    //        draw_list->AddRectFilled(rect_min, rect_max, IM_COL32(200, 200, 200, 255));

    //        // Display fixed text on the left side
    //        ImGui::Text("Command Line Interface: Ready");

    //        // Display coordinates on the right side
    //        ImGui::SameLine(io.DisplaySize.x - 250); // Align to the right side
    //        ImGui::Text("Coordinates: x=0.0, y=0.0, z=0.0");  // Example coordinates
    //    }
    //    ImGui::End();  // End status bar window
    //}
    //ImGui::End();  // End main editor window
}