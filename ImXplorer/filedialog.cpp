#include "filedialog.h"
#include "imgui.h"
#include "imfilebrowser.h"
#include <iostream>

namespace FDIALOG
{

}


//using the project "imgui-filebrowser" for now

void imfilebrowser()
{
    // create a file browser instance
    ImGui::FileBrowser fileDialog;

    // (optional) set browser properties
    fileDialog.SetTitle("title");
    fileDialog.SetTypeFilters({ ".h", ".cpp" });

    fileDialog.Open();
    fileDialog.Display();

    if(fileDialog.HasSelected())
    {
        std::cout << "Selected filename" << fileDialog.GetSelected().string() << std::endl;
        fileDialog.ClearSelected();
    }
}
