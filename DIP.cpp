#include<iostream>

//Abstraction Interface for low-level modules
class SwitchableDevice
{
    public:
            virtual void turnOn()=0;
            virtual void turnOff()=0;
            virtual ~SwitchableDevice() = default;
};

//Low level module implementing the abstraction.
//LightBulb becomes a low-level module that conforms to the abstraction defined by the SwitchableDevice interface.
class LightBulb : public SwitchableDevice
{
    public:
            void turnOn() override
            {
                std::cout <<"Lightbulb is turned on \n";
            }

            void turnOff() override
            {
                std::cout << "Lightbulb is turned off \n";
            }
};

//This design adheres to the Dependency Inversion Principle, as the high-level module (Switch) depends on the abstraction (SwitchableDevice), and not the other way around.
//If you were to make Switch inherit from SwitchableDevice, it would violate the Dependency Inversion Principle. The reason is that high-level modules should not depend on low-level modules, and making Switch inherit from SwitchableDevice would create a dependency relationship in the wrong direction.
//The reason is that high-level modules should not depend on low-level modules, and making Switch inherit from SwitchableDevice would create a dependency relationship in the wrong direction.
//High level module
class Switch {
    private:
            SwitchableDevice* device;
    public:
            Switch(SwitchableDevice* device): device(device)
            {

            }

            void press()
            {
                if(device)
                {
                    device->turnOn();
                    device->turnOff();
                }
            }
};

int main()
{
    //Create a concrete instance of the low level module
    LightBulb bulb;

    //Create highlevel module with the concrete instance
    Switch switchButton(&bulb);

    //press the switch
    switchButton.press();

    return 0;
}

//Low-level module:  a low-level module is a module that contains detailed, specific implementations. It deals with the nitty-gritty details of a particular functionality.
//High-level module:  a high-level module is one that orchestrates or uses the abstractions defined in the system.

//LightBulb is considered a low-level module because it provides a specific implementation of a switchable device. 
//Switch is considered a high-level module because it uses the abstraction (SwitchableDevice) to perform its task. It orchestrates the interaction with the SwitchableDevice without concerning itself with the specific details of how each device (e.g., LightBulb) accomplishes turning on or off.



//Notes
//Abstraction Interface:
//The SwitchableDevice interface acts as an abstraction, defining the behavior of switchable devices, such as turning on and turning off. This abstraction allows the Switch class to interact with various switchable devices without requiring specific knowledge of their implementation details.

//Low-level Module:
//The LightBulb class implements the SwitchableDevice interface, adhering to the abstraction and encapsulating the specific functionality of turning on and turning off a light bulb. This separation allows for easy modification or replacement of the light bulb implementation without affecting the Switch class.

//High-level Module:
//The Switch class depends on the SwitchableDevice abstraction, not on any concrete implementation. This dependency enables the Switch class to interact with any object that adheres to the SwitchableDevice interface, such as the LightBulb instance.

//Effective Decoupling:
//By following the DIP, the code achieves loose coupling between high-level and low-level modules. This coupling reduction leads to several benefits:

//Flexibility: The code becomes more flexible as it can accommodate different implementations of the SwitchableDevice interface without modifying the Switch class.

//Maintainability: The code becomes easier to maintain as changes to the LightBulb implementation do not affect the Switch class and vice versa.

//Testability: The code becomes more testable as it is easier to isolate and test individual components without interfering with others.

//Enhancements:

//Additional Abstractions: The SwitchableDevice interface could be further abstracted to include additional functionalities, such as adjusting brightness or intensity levels.

//Dependency Injection: The Switch class could be modified to receive its SwitchableDevice dependency through dependency injection techniques, enabling more flexibility and dynamic configuration.

//The provided code effectively implements the Dependency Inversion Principle, demonstrating a clear separation of concerns between high-level and low-level modules. The code exhibits loose coupling, promoting flexibility, maintainability, and testability. While some enhancements could further improve the code, it effectively demonstrates the application of DIP in object-oriented programming.


//DIP -->
//For the sake of dependencies,you should depend on abstractions instead of concrete type or
//implementation details.


//High level modules should not depend on low level modules.Both should depend on abstractions.
//Abstraction should not depend on details.Details should depend on abstractions.
//High level -->  stable part.
//Low level --> implementation details.
//Dependency should be inverted -->low level should depend on the high level.
//Can be achieved by assigning the 3 abstractions to the high level.



//-->Assign the abstractions to the high level and make the high level the owner of abstractions.
//-->it is assignment of ownership.
//-->transaction class + dependenct UI abstractions should be grouped together.
//-->to steer the dependency in the right direction.
//-->for proper dependency inversion -->  the abstraction must be owned by the high level.

...





Explanation --->

 This adherence to DIP is demonstrated by the fact that the high-level module (Switch) relies on an abstraction (SwitchableDevice) rather than a concrete low-level module (LightBulb).

Here's why this conforms to DIP:

Abstraction (SwitchableDevice):

SwitchableDevice is an abstraction (interface) that defines the common behavior (turnOn and turnOff) expected from any switchable device.
Low-level module (LightBulb):

LightBulb is a low-level module that implements the SwitchableDevice interface, providing the specific details of how a light bulb should turn on or off.
High-level module (Switch):

Switch is a high-level module that depends on the abstraction (SwitchableDevice). It takes a SwitchableDevice* as a parameter in its constructor, allowing it to work with any class that implements the SwitchableDevice interface.
This structure adheres to DIP because the high-level module (Switch) is not directly dependent on the low-level module (LightBulb). Instead, it depends on the abstraction (SwitchableDevice), allowing for flexibility and easier maintenance. If you introduce another class that implements SwitchableDevice, you can use it with the Switch class without modifying the Switch class itself, demonstrating the flexibility provided by DIP.
