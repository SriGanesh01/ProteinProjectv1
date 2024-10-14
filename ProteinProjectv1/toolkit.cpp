#include "AllHeader.h"
#include "toolkit.h"

void MainToolkit()
{
    ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiCond_FirstUseEver);
    if (ImGui::Begin("Test Window 22"))
    {
        ImGui::Text("Hello World");
    } ImGui::End();
}