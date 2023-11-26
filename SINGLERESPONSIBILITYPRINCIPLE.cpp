//https://www.youtube.com/watch?v=twbNutezDzY&list=PLEI-q7w3s9gSumsDp3Ybt61DDqY7vp0p3&index=2&ab_channel=CodingDecoded

//Single Responsibility Principle to design a restaurant manager system with separate modules.


#include <iostream>

//Interface for modules.

class Module
{
    public:
            virtual void performTask() = 0;
            virtual ~Module() = default;
};


//Manager class to oversee and coordinate modules

class Manager
{
    private:
            Module* foodPreperationModule;
            Module* orderPlacementModule;
            Module* logisticsModule;
            Module* deliveryModule;

    public:
            Manager(Module* foodModule, Module* orderModule,Module* logisticsModule,Module* deliveryModule) : foodPreperationModule(foodModule),
                                                                                                              orderPlacementModule(orderModule),
                                                                                                              logisticsModule(logisticsModule),
                                                                                                              deliveryModule(deliveryModule)
            {

            }

            //Check the status of each module
            void checkModules()
            {
                std::cout << "Checking modules..\n";
                foodPreperationModule->performTask();
                orderPlacementModule->performTask();
                logisticsModule->performTask();
                deliveryModule->performTask();
                std::cout << "modules checked \n";

            }

};

//Concrete implemenation of the Food preperation module
class FoodPreperationModule : public Module
{
    public:
            void performTask() override
            {
                std::cout << "Food Preperation Module is working. \n";
                //Implement food perperation logic.
            }
};

//Concrete implementation of the Order placement module
class OrderPlacementModule : public Module
{
    public:
            void performTask() override
            {
                std::cout << "Order placement module is working. \n";
                //Implement order placement logic.
            }
};


//Concrete implementation of the Logistics and Procurement Module
class LogisticsModule : public Module
{
    public:
            void performTask() override
            {
                std::cout << "Logistics and Procurement module is working \n";
                //Implement logistic and procurement logic.
            }
};


//Concrete implementation of Delivery module
class DeliveryModule : public Module
{
    public:
            void performTask() override
            {
                std::cout << "Delivery module is working \n";
                //Implement delivery logic.
            }
};


int  main()
{
    //Create instance of modules.
    FoodPreperationModule foodModule;
    OrderPlacementModule  orderModule;
    LogisticsModule logisticsModule;
    DeliveryModule  deliveryModule;

    //Create manager with modules;
    Manager manager(&foodModule,&orderModule,&logisticsModule,&deliveryModule);

    //Simulate the system check
    manager.checkModules();

    //Suppose the order placement module is corrupted.

    //Continue to check other modules
    manager.checkModules();

    return 0;
}


....x.....


//Better naming :

class ModuleInterface {
public:
    virtual void performTask() = 0;
};

class FoodPreparationModule : public ModuleInterface {
public:
    void performTask() override {
        // Implement food preparation logic
    }
};

class OrderPlacementModule : public ModuleInterface {
public:
    void performTask() override {
        // Implement order placement logic
    }
};

class LogisticsModule : public ModuleInterface {
public:
    void performTask() override {
        // Implement logistics logic
    }
};

class DeliveryModule : public ModuleInterface {
public:
    void performTask() override {
        // Implement delivery logic
    }
};

class Manager {
private:
    ModuleInterface* foodPreparationModule;
    ModuleInterface* orderPlacementModule;
    ModuleInterface* logisticsModule;
    ModuleInterface* deliveryModule;

public:
    Manager(ModuleInterface* foodModule, ModuleInterface* orderModule, ModuleInterface* logisticsModule, ModuleInterface* deliveryModule)
        : foodPreparationModule(foodModule),
          orderPlacementModule(orderModule),
          logisticsModule(logisticsModule),
          deliveryModule(deliveryModule) {}

    void checkModules() {
        foodPreparationModule->performTask();
        orderPlacementModule->performTask();
        logisticsModule->performTask();
        deliveryModule->performTask();
    }
};


//it is possible to use Module pointers without inheriting the Module class in the Manager class. This can be achieved by using composition rather than inheritance. In composition, the Manager class contains pointers to Module objects, but it does not inherit from the Module class itself.
//In this example, the Manager class holds pointers to objects that implement the ModuleInterface, rather than inheriting from the Module class. This allows the Manager class to work with different implementations of the ModuleInterface, and it promotes a clearer separation of concerns between the Manager class and the specific module implementations.
// the Manager class doesn't inherit from the Module class. It simply holds pointers to instances of classes that implement the Module interface. This allows you to achieve the desired separation of concerns without introducing unnecessary inheritance.

//In object-oriented programming (OOP), composition is a design technique that allows objects to contain other objects. This means that an object can be composed of objects from other classes. Composition is a powerful tool for creating reusable and extensible software.
