//
// Created by packa on 13/10/2024.
//

#ifndef BIBI_ELEMENTTAG_HPP
#define BIBI_ELEMENTTAG_HPP

#include <string>
namespace Bibi::Core::UI {

    class ElementTag {
    public:
        ElementTag() = delete;

        static const std::string MainMenuHelpAbout;
        static const std::string MainMenuWindowsSubjectList;
        static const std::string MainMenuWindowsInspector;
        static const std::string WindowObjectList;
        static const std::string WindowInspector;
    };

} // UI

#endif //BIBI_ELEMENTTAG_HPP
