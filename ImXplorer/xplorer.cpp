#include "xplorer.h"
#include "imgui.h"
/*
xplorer window should have two main window

the shortcut window     : for switching between different type of sub window.
the sub-window          : for primary auditioning of objects and drag and droping objects.
(listbox will be a good widget to look at for the sub window,
 but the problem is the subwindow should allow tree view.
 so either figure out how to make the listbox display tree nodes
 Or, make a tree node in another window and somehow append it to the shortcut window)

*/
static void HelpMarker(const char* desc)
{
    ImGui::TextDisabled("(?)");
    if (ImGui::BeginItemTooltip())
    {
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(desc);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}

namespace XPLORER
{
    void ShowXplorer()
    {
        if (ImGui::Begin("Xplorer"))
        {
            ImGui::Text("This is a text");
            ImGui::Button("smash");
            if (ImGui::BeginChild("the sub window",ImVec2(-FLT_MIN, ImGui::GetTextLineHeightWithSpacing() * 8), ImGuiChildFlags_Border | ImGuiChildFlags_ResizeY))
            {for(int n=0; n<10; n++)
            {
                ImGui::Text("something %0d",n);
            }
            }
            ImGui::EndChild();

            /*
            HelpMarker("Drag bottom border to resize. Double-click bottom border to auto-fit to vertical contents.");
            ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::GetStyleColorVec4(ImGuiCol_FrameBg));
            if (ImGui::BeginChild("ResizableChild", ImVec2(-FLT_MIN, ImGui::GetTextLineHeightWithSpacing() * 8), ImGuiChildFlags_Border | ImGuiChildFlags_ResizeY))
                for (int n = 0; n < 10; n++)
                    ImGui::Text("Line %04d", n);
            ImGui::PopStyleColor();
            ImGui::EndChild();
            */
        ImGui::End();
        }

        return;
    }
}
