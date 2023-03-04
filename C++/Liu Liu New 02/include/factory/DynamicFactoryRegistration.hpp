// DynamicFactoryRegistration.hpp
//
//
// Implements a single registration entry for a DynamicFactory, along
// with the DYNAMIC_FACTORY_REGISTER macro used to register a
// single class into a DynamicFactory.

#ifndef DYNAMICFACTORYREGISTRATION_HPP
#define DYNAMICFACTORYREGISTRATION_HPP



namespace factory
{
    template <typename BaseType, typename ObjectType, typename... ConstructorArgs>
    class DynamicFactoryRegistration
    {
    public:
        DynamicFactoryRegistration(
            const std::string& name, ConstructorArgs... constructorArgs);
    };



    template <typename BaseType, typename ObjectType, typename... ConstructorArgs>
    DynamicFactoryRegistration<BaseType, ObjectType, ConstructorArgs...>
        ::DynamicFactoryRegistration(
            const std::string& name, ConstructorArgs... constructorArgs)
    {
        DynamicFactory<BaseType>::instance().template registerType<ObjectType>(
            name, std::forward(constructorArgs)...);
    }
}



#define DYNAMIC_FACTORY_REGISTER_MAKE_NAME2_(BaseName, UniquePart) BaseName##UniquePart



#define DYNAMIC_FACTORY_REGISTER_MAKE_NAME_(BaseName, UniquePart) \
    DYNAMIC_FACTORY_REGISTER_MAKE_NAME2_(BaseName, UniquePart)



#define DYNAMIC_FACTORY_REGISTER_MAKE_UNIQUE_NAME_(BaseName) \
    DYNAMIC_FACTORY_REGISTER_MAKE_NAME_(BaseName, __COUNTER__)



#define DYNAMIC_FACTORY_REGISTER(BaseType, ObjectType, ...) \
    namespace { \
        factory::DynamicFactoryRegistration<BaseType, ObjectType> \
            DYNAMIC_FACTORY_REGISTER_MAKE_UNIQUE_NAME_(reg) {__VA_ARGS__}; \
    }



#endif

