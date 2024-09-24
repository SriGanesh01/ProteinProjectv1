#include "activity_bar.h"
#include "AllHeader.h"

void MainActivityBar()
{
    ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiCond_FirstUseEver);
    if (ImGui::Begin("Test Window 1"))
    {
        ImGui::Text("Hello World");
    } ImGui::End();
}