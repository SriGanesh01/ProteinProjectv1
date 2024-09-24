#include "main_ui.h"
#include "activity_bar.h" //MainActivityBar
#include "status_bar.h" // MainStatusBar
#include "toolkit.h" // MainToolkit
#include "editor_group.h" // MainEditorGroup
#include "commandline.h" // MainCommandline
#include "visualizer.h" // MainVisualizer
#include "AllHeader.h"

void MainGUI1()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    MainActivityBar();
    MainStatusBar();
    MainToolkit();
    MainEditorGroup();
    MainCommandline();
    MainVisualizer();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}