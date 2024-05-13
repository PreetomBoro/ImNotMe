static void HelpMarker(const char* desc);

namespace XPLORER
{
    bool unified = false;
    enum e_shortcuts{ e_Samples, e_Favourites, e_Preset, e_Root};
    void ShowXplorer(); //shows xplorer window
    void ShowXplorerUnified();
    struct Shortcut_data_for; //will hold the paths for the shortcut; has add_path(), remove_path(), update();
    //should the Shortcut_data be a class or struct. not really sure. I mean the destructor will be a nice feature to have

}
