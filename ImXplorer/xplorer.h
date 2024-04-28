#include <vector>
#ifndef INCLUDED_DONT_WORRY
#include "boringheaders.h"
#endif // INCLUDED_DONT_WORRY



namespace XPLORER
{
    void showxplorer();
    //there should be 6 shortcuts(towards the edge of the window:
    /*
    1) Favorite             :deal with it later
    2) Samples
    3) Plugins              :deal with it later
    4) Track Template       :deal with it later
    5) Instrument           :deal with it later
    6) Disk
    */
    struct shortcut {
        int subDirCount {}; //how many directories/ sub shortcuts should be in the sub window
        std::vector<int> subDirs {}; //shouldn't be int, but some kind of path datatype(to the directories)
        void subDirEdit(); //supposed to handle any change in the number of paths added
    }Favourite, Samples, Plugins, Track_Template, Instrument, Disk;

}
