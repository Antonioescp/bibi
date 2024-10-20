//
// Created by packa on 11/10/2024.
//

#ifndef BIBI_ELEMENT_HPP
#define BIBI_ELEMENT_HPP

#include <vector>
#include <memory>
#include <ranges>

#include "IElement.hpp"
#include "Core/Application.hpp"

namespace Bibi::Modules::Gui {

    class Element : public IElement {
    public:
        ~Element() override = default;

        explicit Element(Core::Application *application);

        Element() = default;

        void setUp() override;

        void update() override;

        void tearDown() override;

        void addElement(std::unique_ptr<IElement> element) override;

        void removeElement(IElement *element) override;

        void removeElements(std::string tag) override;

        template <typename TElement>
        requires std::derived_from<TElement, IElement>
        void removeElements() {
            for (auto &element : _childrenElements) {
                if (dynamic_cast<TElement*>(element.get())) {
                    _elementsToRemove.push_back(element.get());
                }
            }
        }

        void clearElements() override;

        std::vector<std::unique_ptr<IElement>> &getElements() override;

        void setTag(std::string tag) override;

        std::string getTag() override;

        void setParent(IElement *parent) override;

        IElement *getParent() override;

        Core::Application *getApplication() override;

        void setApplication(Core::Application *application) override;

        IElement *getChildByTag(std::string_view tag) override;

    protected:
        Core::Application *_application{nullptr};
        std::vector<std::unique_ptr<IElement>> _childrenElements{};
        std::vector<std::unique_ptr<IElement>> _elementsToAdd{};
        std::vector<IElement*> _elementsToRemove{};
        std::string _tag{};
        IElement *_parent{nullptr};

        void handlePendingElements();
    };

} // Gui

#endif //BIBI_ELEMENT_HPP
