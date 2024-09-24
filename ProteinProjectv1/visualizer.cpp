#include "AllHeader.h"
#include "visualizer.h"

void MainVisualizer()
{
    if (ImGui::BeginTabBar("MyTabs"))
    {
        if (ImGui::BeginTabItem("Tab 1")) {
            ImGui::Text("Tab 1 content here");
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Tab 2")) {
            ImGui::Text("Tab 2 content here");
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Tab 3")) {
            ImGui::Text("Tab 3 content here");
            ImGui::EndTabItem();
        }

    }ImGui::EndTabBar();
}