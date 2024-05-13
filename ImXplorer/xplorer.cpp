#include "xplorer.h"
#include "imgui.h"
#include <string>
#include <vector>
#include "filedialog.h"
/*
xplorer window should have two main window

the shortcut window     : for switching between different type of sub window.
the sub-window          : for primary auditioning of objects and drag and droping objects.
(listbox will be a good widget to look at for the sub window,
 but the problem is the subwindow should allow tree view.
 so either figure out how to make the listbox display tree nodes
 Or, make a tree node in another window and somehow append it to the shortcut window)

*/

namespace XPLORER
{
    static short int selected =0;
    char path = NULL;
    void ShowXplorer()
    {
        if(ununified){
            ShowXplorerUnunified();
            return;
        }
        if (ImGui::Begin("Xplorer"))
        {
            if(ImGui::Button("smash"))
            {
                 //<-- god damn linker errors when using nfd.h
                 //idk what's causing it. built the "gmake-windows" config=debug/release_x64
                 //it's crazy how much linker error still occurs. god damn bruh I just want to make a window appear.
                 //thank you to anybody that makes header only library. real heroes.
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
                    ImGui::Selectable("Root", selected==3)? selected =3: selected = selected;
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

}

// there's some porblem with user defined data types

struct sturec {
    int rollno;
};

sturec newstu;
//newstu.rollno =10;

