//
// Created by packa on 20/10/2024.
//

#ifndef BIBI_ILIFECYCLEAWARE_HPP
#define BIBI_ILIFECYCLEAWARE_HPP

namespace Bibi::Core::Lifecycle {

    /**
     * @brief Interface del ciclo de vida de un objecto en la aplicación.
     * Esta interface define las operaciones que se pueden realizar en el ciclo de vida dentro de la aplicación.
     */
    class ILifecycleAware {
    public:
        virtual ~ILifecycleAware() = default;

        /**
         * @brief Se ejecuta una sola vez al inicio de la aplicación.
         * Se ejecuta una sola vez cuando un objeto es creado y se agrega a la aplicación.
         * Se ejecuta en el orden en que los objetos fueron agregados a la aplicación.
         */
        virtual void setUp() = 0;

        /**
         * @brief Se ejecuta por cada frame de la aplicacion.
         * Se ejecuta por cada frame de la aplicación, se ejecuta después de setUp() y antes de tearDown().
         * Se ejecuta en el orden en que los objetos fueron agregados a la aplicación.
         */
        virtual void update() = 0;

        /**
         * @brief Se ejecuta una sola vez al final de la aplicación.
         * Se ejecuta una sola vez cuando la aplicación se cierra.
         */
        virtual void tearDown() = 0;
    };

} // Lifecycle

#endif //BIBI_ILIFECYCLEAWARE_HPP
