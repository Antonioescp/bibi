//
// Created by packa on 9/10/2024.
//

#ifndef BIBI_IMGUIMODULE_HPP
#define BIBI_IMGUIMODULE_HPP

#include <string>
#include <span>
#include <spdlog/logger.h>
#include "Modules/Logging/Logger.hpp"
#include "Modules/Gui/IElement.hpp"

namespace Bibi::Modules::Gui {

    class ImGuiModule : public IModule {
    public:
        static const std::string name;

        void setUp() override;
        void update() override;
        void tearDown() override;
        void addElement(std::unique_ptr<IElement> element);
        auto getElements();

        template <typename TElement>
        requires std::derived_from<TElement, IElement>
        TElement* getElementByTag(const std::string& tag) {
            for (auto& element : s_elements) {
                if (auto converted{ dynamic_cast<TElement*>(element.get()) }; element->getTag() == tag && converted != nullptr) {
                    return converted;
                }

                auto found{ element->getChildByTag(tag) };
                if (found) {
                    return dynamic_cast<TElement*>(found);
                }
            }

            return {};
        }

    private:
        std::shared_ptr<spdlog::logger> _logger{};
        std::vector<std::unique_ptr<IElement>> s_elements{};

        void initializeImGui();
        void registerElements();
    };

} // Modules

#endif //BIBI_IMGUIMODULE_HPP
