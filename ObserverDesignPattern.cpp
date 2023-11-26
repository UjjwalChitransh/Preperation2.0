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



//Observer Interface

class Observer{
    public: 
            virtual void update(const Message& message) = 0;
};
//Concrete Observer implementation


//DisplayObserver observes and prints the updates to the console
// Concrete Observer
class DisplayObserver : public Observer {
    private:
                Subject *subject;
    public:     
                //Constructor registers the observer with the subject
                DisplayObserver(Subject* subject){
                    this->subject = subject;
                    subject->registerObserver(this);
                }

                //Update method is called by the subject and prints the updates to the console
                void update(const Message& message) override{
                    switch(message.getType())
                    {
                        case Message::TEMPERATURE_UPDATE:
                             std::cout << "Temperature:" << message.getData() << std::endl;
                        break;
                        case Message::HUMIDITY_UPDATE:
                             std::cout << "Humidity:" << message.getData() << std::endl;
                        break;
                        case Message::PRESSURE_UPDATE:
                             std::cout << "Pressure:" << message.getData() << std::endl;
                        break;
                     }

                }

                //Destructor removes the observer from the subject
                ~DisplayObserver() override{
                    subject->removeObserver(this);
                }
};

#if 0
//Concrete Subject implemetation
class WeatherStation: public Subject {
    private:
            std::vector<Observer*> observers;
            double temperature;
            double humidity;
            double pressure;

    public:
            //Register an observer
            void registerObserver(Observer* observer) override{
                observers.push_back(observer);
            }

            //Remove an observer
            void removeObserver(Observer* observer) override{
                observers.erase(std::remove(observers.begin()))
            }
};
#endif

//Concrete Subject Implementation
class WeatherStation : public Subject{
    private:
            std::vector<Observer*> observers;
            double temperature;
            double humidity;
            double pressure;
    
    public:
            //Register an observer
            void registerObserver(Observer* observer) override {
                observers.push_back(observer);
            }

            //Remove an observer
            void removeObserver(Observer* observer) override {
                observers.erase(std::remove(observers.begin(),obserers.end(),observer),observers.end());
            }

            //Notify all the registered observers with  a  message
            void notifyObservers(const Message& message) override {
                for(Observer* observer : observers)
                {
                    observer->update(message);
                }
            }

            //Update measurements and notify observers
            void updateMeasurements(double temperature,double humidity,double pressure)
            {
                this->temperature = temperature;
                this->humidity = humidity;
                this->pressure = pressure;

                Message message;

                //Notify about temperature update
                message.setType(Message::TEMPERATURE_UPDATE);
                message.setData(temperature);
                notifyObserver(message);

                //Notify about humidity update
                message.setType(Message::HUMIDITY_UPDATE);
                message.setData(humidity);
                notifyObservers(message);

                //Notify about pressure update
                message.setType(Message::PRESSURE_UPDATE);
                message.setData(pressure);
                notifyObservers(message);
            }
};



//Client Code Using the Observer Pattern
// This design pattern allows for a flexible and decoupled system where observers (like DisplayObserver) can react to changes in the state of the subject (WeatherStation)
int main()
{
    WeatherStation weatherStation;

    //Create display observers,registering them with the weather station

    DisplayObserver displayObserver(&weatherStation);

    //Update weather measurements , triggering observer notifications
    weatherStation.updateMeasurements(25,70,1013);


    return 0;
}




..........







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



//Observer Interface

class Observer{
    public: 
            virtual void update(const Message& message) = 0;
};
//Concrete Observer implementation


//DisplayObserver observes and prints the updates to the console

class DisplayObserver : public Observer {
    private:
                Subject *subject;
    public:     
                //Constructor registers the observer with the subject
                DisplayObserver(Subject* subject){
                    this->subject = subject;
                    subject->registerObserver(this);
                }

                //Update method is called by the subject and prints the updates to the console
                void update(const Message& message) override{
                    switch(message.getType())
                    {
                        case Message::TEMPERATURE_UPDATE:
                             std::cout << "Temperature:" << message.getData() << std::endl;
                        case Message::HUMIDITY_UPDATE:
                             std::cout << "Humidity:" << message.getData() << std::endl;
                        case Message::PRESSURE_UPDATE:
                             std::cout << "Pressure:" << message.getData() << std::endl;
                     }

                }

                //Destructor removes the observer from the subject
                ~DisplayObserver() override{
                    subject->removeObserver(this);
                }
};

#if 0
//Concrete Subject implemetation
class WeatherStation: public Subject {
    private:
            std::vector<Observer*> observers;
            double temperature;
            double humidity;
            double pressure;

    public:
            //Register an observer
            void registerObserver(Observer* observer) override{
                observers.push_back(observer);
            }

            //Remove an observer
            void removeObserver(Observer* observer) override{
                observers.erase(std::remove(observers.begin()))
            }
};
#endif
