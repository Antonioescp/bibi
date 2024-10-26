//
// Created by harol on 10/10/2024.
//
#pragma once

#ifndef FILEEXPLORER_H
#define FILEEXPLORER_H
#include <filesystem>
#include <vector>
#include <string>

#include "Modules/Gui/Element.hpp"

namespace fs = std::filesystem;  // Usar std::filesystem en lugar de experimental

namespace Bibi::Modules::Gui:: inline Elements
{

     struct file
    {
        std::string alias;
        fs::path path;
    };

    class FileExplorerElement : public virtual Element
    {
        static const int modal_flags;
        const char* m_title;
        bool m_oldVisibility;
        int m_selection;
        fs::path m_currentPath;
        bool m_currentPathIsDir;
        std::vector<file> m_filesInScope;

    public:
        explicit FileExplorerElement(const char* title);
        const bool renderElement(bool isVisible, std::string& outPath);

        void update() override;

    };
} // Elements

#endif //FILEEXPLORER_H
