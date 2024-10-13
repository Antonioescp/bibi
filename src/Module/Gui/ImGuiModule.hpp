//
// Created by packa on 9/10/2024.
//

#ifndef BIBI_IMGUIMODULE_HPP
#define BIBI_IMGUIMODULE_HPP

#include <string>
#include <span>
#include <spdlog/logger.h>
#include "Module/Logging/Logger.hpp"
#include "Module/IModuleConfigurable.hpp"
#include "Module/IModuleDeconstructable.hpp"
#include "Module/IModuleRunnable.hpp"
#include "Module/Gui/IElement.hpp"

namespace Bibi::Module::Gui {

    class ImGuiModule : public IModuleConfigurable, public IModuleRunnable, public IModuleDeconstructable {
    public:
        static const std::string name;

        void setUp(GLFWwindow* window) override;
        void run(GLFWwindow* window) override;
        void tearDown(GLFWwindow* window) override;
        static void addElement(std::unique_ptr<IElement> element);
        static auto getElements();

        template <typename TElement>
        requires std::derived_from<TElement, IElement>
        static TElement* getElementByTag(const std::string& tag) {
            for (auto& element : s_elements) {
                auto found{ element->getChildByTag(tag) };
                if (found) {
                    return dynamic_cast<TElement*>(found);
                }
            }

            return {};
        }

    private:
        std::shared_ptr<spdlog::logger> _logger;
        static std::vector<std::unique_ptr<IElement>> s_elements;

        void initializeImGui(GLFWwindow* window);
        static void registerElements(GLFWwindow* window);
    };

} // Module

#endif //BIBI_IMGUIMODULE_HPP
