#include "xplorer.h"
#include "imgui.h"
#include "filedialog.h"
#include <string>
#include <vector>

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
    static short int selected =0;

    void ShowXplorer()
    {
        if (ImGui::Begin("Xplorer"))
        {
            if(ImGui::Button("smash"))
            {

                imfilebrowser(); //it's just copy paste. look into it more
            }

            //this is for the shortcut list
            //maybe the prebuilt "list/or selectable" widgets will be a good enough choice for it
            //needs to be border-less tho
            //ShortCut Window
            {
                ImGui::BeginChild("XplorerShortcutsWindow", ImVec2(ImGui::GetContentRegionAvail().x * 0.3f, 260), ImGuiChildFlags_None);
                {

                    ImGui::Selectable("Samples", selected==0)? selected =0: selected = selected;
                    ImGui::Selectable("Favorites", selected==1)? selected =1: selected = selected;
                    ImGui::Selectable("Preset", selected==2)? selected =2: selected = selected;
                }
                ImGui::EndChild();
            }



            ImGui::SameLine();
            ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 7.0f);
            //this is for the sub window
            {
                if (ImGui::BeginChild("XplorerSubWindow",ImVec2(-FLT_MIN, ImGui::GetTextLineHeightWithSpacing() * 8), ImGuiChildFlags_Border | ImGuiChildFlags_ResizeY))
                {
                    for(int n=0; n<10; n++)
                    {
                        ImGui::Text("something %0d",n);// replace the text with tree or something to show directories
                    }
                }
                ImGui::EndChild();
            }
            ImGui::PopStyleVar();
        ImGui::End();
        }

        return;
    }

    void add_path_from(unsigned short int selected)
    {

    }

    void remove_path_from(unsigned short int selected)
    {

    }

    struct Shortcut_data_for
    {
        int sno {}; //1 for samples... 2 for favourite.. 0 for nothing selected
        std::vector<std::string> paths {};
    };

    Shortcut_data_for Samples;
    Shortcut_data_for Favourite;


}
