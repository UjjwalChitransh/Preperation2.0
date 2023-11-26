//Target interface - is the target interface that new system expects
class NewSystemInterface
{
    public:
            virtual void execute()=0;
            virtual ~NewSystemInterface() = default;
};

//existing class with methos that we want to adapt
class OldSystem {
    public:
            void performAction()
            {
                std::cout << "Old System is performing an action." << std::endl;
            }
};

//Class that adapts OldSystem to the NewSystemInterface. Inherits from NewSystemInterface and contains an instance of OldSystem.
//execute() method of adapter is implemented by calling performAction() on the OldSystem
class Adapter : public NewSystemInterface {
    private:
            OldSystem oldsystem;

    public:
            void execute() override{
                oldsystem.performAction();
            }
};

//Client Code
//Instance of the Adaper is created and treated as a NewSystemInterface
//Client code then calls execute() on the adapter which internally calls performAction() on the OldSystem.
int main()
{   //Using the Adapter to make the OldSystem compatible with NewSystemInterface
    NewSystemInterface* adapter = new Adapter();

    //Client code can now call execute() on the adapter.
    adapter->execute();

    delete adapter;

    return 0;
}

On Tue, Nov 14, 2023 at 11:11 PM ujjwal chitransh <ujjwalchitransh1@gmail.com> wrote:
Observer Design Pattern ::

#include <iostream>
#include <fstream>
#include <vector>

//Message class for passing information from Subject to Observer
class Message
{
    public:
            enum MessageType {
                TEMPERATURE_UPDATE,
                HUMIDITY_UPDATE,
                PRESSURE_UPDATE
            };


            void setType(MessageType messageType)
            {
                type = messageType;
            }

            void setData(double value)
            {
                data= value;
            }

            MessageType getType() const {
                return type;
            }

            double getData() const {
                return data;
            }

    private:
            MessageType type;
            double data;
};


//Subject Interface
class Subject{
    public:
            virtual void registerObserver(Observer* observer)=0;
            virtual void removeObserver(Observer* observer)=0;
            virtual void notifyObserver(const Message& message)=0;
};
