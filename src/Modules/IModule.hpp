//
// Created by packa on 9/10/2024.
//

#ifndef BIBI_IMODULE_HPP
#define BIBI_IMODULE_HPP

namespace Bibi::Core {
    class Application;
}

namespace Bibi::Modules {
    class IModule {
    public:
        virtual ~IModule() = default;
        void setApplication(Core::Application* application) { _application = application; }

    protected:
        Core::Application* _application{ nullptr };
    };
} // Modules

#endif //BIBI_IMODULE_HPP
