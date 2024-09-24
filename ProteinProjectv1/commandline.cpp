#include "AllHeader.h"
#include "commandline.h"

void MainCommandline()
{
    ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiCond_FirstUseEver);
    if (ImGui::Begin("Test Window 7 78"))
    {
        ImGui::Text("Hello World");
    } ImGui::End();
}