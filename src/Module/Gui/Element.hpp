//
// Created by packa on 11/10/2024.
//

#ifndef BIBI_ELEMENT_HPP
#define BIBI_ELEMENT_HPP

#include <vector>
#include <memory>
#include <ranges>

#include "IElement.hpp"

namespace Bibi::Module::Gui {

    class Element : public IElement {
    public:
        ~Element() override = default;

        explicit Element(GLFWwindow *window);

        Element() = default;

        void render() override;

        void setUp() override;

        void tearDown() override;

        void addElement(std::unique_ptr<IElement> element) override;

        void removeElement(std::string tag) override;

        void clearElements() override;

        std::vector<std::unique_ptr<IElement>> &getElements() override;

        void setTag(std::string tag) override;

        std::string getTag() override;

        void setParent(IElement *parent) override;

        IElement *getParent() override;

        GLFWwindow *getWindow() override;

        void setWindow(GLFWwindow *window) override;

        IElement* getChildByTag(std::string_view tag) override;

    protected:
        GLFWwindow *_window{nullptr};
        std::vector<std::unique_ptr<IElement>> _childrenElements{};
        std::string _tag{};
        IElement *_parent{nullptr};
    };

} // Gui

#endif //BIBI_ELEMENT_HPP
