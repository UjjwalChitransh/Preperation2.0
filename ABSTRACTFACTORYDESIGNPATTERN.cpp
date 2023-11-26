//Abstract Vehicle Interface
//The Vehicle interface defines the common behavior of all vehicles
class Vehicle {
    public: 
            virtual void move() const = 0;
            virtual double getFuelConsumption() const = 0;
            virtual ~Vehicle() = default;
};

//Concrete Vehicle Implementation
//The concrete Vehicle classes (Car, Truck, and Bike) implement the Vehicle interface
class Car :  public Vehicle {
    public:
            void move()const override{
                std::cout << "Driving  a  car!" << std::endl;
            }

            double getFuelConsumption()const override{
                return 10.0; //Litres per km.
            }
};

class Truck : public Vehicle {
    public:
            void move() const override{
                std::cout << "Driving a truck!" << std::endl;
            }

            double getFuelConsumption()const override{
                return 20.0; //Litres per km.
            }
};

class Bike : public Vehicle {
    public:
            void move()const override{
                std::cout << "Cycling!" << std::endl;
            }
            double getFuelConsumption()const override{
                return 0.0 //Litres per km.
            }
};

//Abstract VehicleFactory Interface
//VehicleFactory interface defines the interface for creating different types of vehicles. 
//concrete VehicleFactory classes (MotorVehicleFactory and NonMotorVehicleFactory) implement the VehicleFactory interface.
class VehicleFactory{
    public: 
            virtual std::unique_ptr<Vehicle> createVehicle(const std::string& type) const=0;
            virtual ~VehicleFactory()=default;
};

//Concrete VehicleFactory implementation
class MotorVehicleFactory:public VehicleFactory{
    public:
            std::unique_ptr<Vehicle> createVehicle(const std::string& type)const override{
                if(type == "car")
                {
                    return std::make_unique<Car>();
                }
                else if(type == "truck")
                {
                    return std::make_unique<Truck>();
                }
                else
                {
                    return nullptr;
                }
            }
};


class NonMotorVehicleFactory:public VehicleFactory{
    public:
            std::unique_ptr<Vehicle> createVehicle(const std::sring& type)const override{
                if(type == "bike")
                {
                    return std::make_unique<Bike>();
                }
                else
                {
                    return nullptr;
                }
            }
};



//Client code using abstract factory pattern
//The client code can then use the appropriate factory to create the desired type of vehicle.
int main()
{
    //Create a factory for motor vehicle
    //creates the MotorVehicleFactory object and stores it in the smart pointer :   std::make_unique<MotorVehicleFactory>()
    // the motorVehicleFactory variable will be used to store a pointer to a factory that can create motor vehicles, such as cars and trucks. The factory can then be used to create specific instances of motor vehicles using the createVehicle() method.
    
    std::unique_ptr<VehicleFactory> motorVehicleFactory = std::make_unique<MotorVehicleFactory>();

    //Create a car using the motor vehicle factory
    //creates a new car using the motorVehicleFactory
    // calls the createVehicle() method on the factory object pointed to by motorVehicleFactory
    std::unique_ptr<Vehicle>car = motorVehicleFactory->createVehicle("car");
    //calls the move() method on the car object. 
    car->move();
    std::cout << "Fuel consumption:" << car->getFuelConsumpion() <<"litres per km" << std::endl;

    //Create a truck using the motor vehicle factory
    std::unique_ptr<Vehicle>truck = motorVehicleFactory->createVehicle("truck");
    truck->move();
    std::cout << "Fuel consmuption:" << truck->getFuelConsumption() << "litres per km" << std::endl;

    //Create a factory for non motor vehicles
    std::unique_ptr<VehicleFactory> nonMotorVehicleactory = std::make_unique<NonMotorVehicleFactory>();

    //Create a bike using non motor vehicle factory
    std::unique_ptr<Vehicle>bike = nonMotorVehicleactory->createVehicle("bike");
    bike->move();
    std::cout << "Fuel consumption:" << bike->getFuelConsumpion() <<"litres per km" << std::endl;

    return 0;
}
