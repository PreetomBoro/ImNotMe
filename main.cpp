#include "boringheaders.h"
#include "xplorer.h"



//didn't want to write the prerequired stuff inside the main function
GLFWwindow* initglfw(const char* title)
{
    //todo: update the function to include screen size;
    GLFWwindow* dummy;
    dummy = glfwCreateWindow(1700,800, title, nullptr, nullptr);
    glfwMakeContextCurrent(dummy);
    glfwSwapInterval(1); //this statement is not even required|||| todo: look into it
    ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
    return dummy;
}

void initimgui(GLFWwindow* window)
{
    //DearImGUI init
    IMGUI_CHECKVERSION(); //<---not really sure how this affects the project (leave it here)
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows
    ImGui::StyleColorsLight();                                // Style (classic is also good)

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
    return;
}


int main()
{
    //initialise karlo guyzzz
    GLFWwindow* window = initglfw("Main Window");
    initimgui(window);

    //xplorer.cpp
    XPLORER::showxplorer();


	return 0;
}





