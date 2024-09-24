#include "AllHeader.h"
#include "editor_group.h"

void MainEditorGroup()
{
    ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiCond_FirstUseEver);
    if (ImGui::Begin("Test Window 7"))
    {
        ImGui::Text("Hello World");
    } ImGui::End();
}