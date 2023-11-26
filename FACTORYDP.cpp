//In the main function, a CircleFactory is instantiated through a ShapeFactory pointer. Then, a Circle is created using the createShape method of the factory. The client code doesn't need to know the specific class of the created object; it relies on the abstract interfaces provided by the factory and the product (polymorphism).
//This pattern allows for easy extension by adding new shapes or factories without modifying existing client code, promoting flexibility and maintainability in the codebase.


//In object-oriented programming (OOP), a concrete class is a class that implements the details of an abstract class or interface. It provides a complete implementation of all the methods and attributes defined in the abstract class or interface, making it instantiable and usable.
//In the context of the factory design pattern example, the concrete classes are Circle and Square. They implement the abstract Shape interface by providing specific implementations for drawing and calculating the area of circles and squares, respectively. These classes are instantiable, and their objects can be used to draw and calculate the area of their respective shapes.
//the Shape class serves as an abstract base class for all concrete shape classes
//By defining this abstract Shape class, the factory design pattern can create objects of different shapes without the client code needing to know the specific type of shape being created. The concrete shape factories handle the creation of the appropriate concrete shape objects based on the input type and parameter.

//Abstract Product (Shape):
class Shape {
    public:
            virtual void draw() const noexcept = 0;
            virtual double getArea() const noexcept = 0;
            virtual ~Shape()=default;
};

//the Circle class represents a concrete implementation of the abstract Shape class. It encapsulates the specific behavior and attributes of a circle shape.
//utilizes these concrete shape classes to create objects of the desired type based on input information.

//Concrete Products (Circle, Square):
class Circle :  public Shape {
    private:    
            double radius;
    public:
            Circle(double radius):radius(radius){}
            void draw() const override{
                std::cout << "Drawing a circle with radius" << radius << std::endl;
            }
            double getArea() const override{
                return M_PI*radius*radius;
            }
};

//the Square class represents a concrete implementation of the abstract Shape class, specifically for square shapes.
//The Square class demonstrates how concrete shape classes implement the abstract Shape interface, providing specific behavior and attributes for different types of shapes.

//Concrete Products (Circle, Square):
class Square : public Shape {
    private:
            double side;
    public:
            Square(double side):side(side){}
            void draw() const override{
                std::cout << "Drawing a square with side length"<<side<<std::endl;
            }
            double getArea() const override{
                return side*side;
            }
};
//the ShapeFactory class represents an abstract factory that defines the interface for creating different types of Shape objects.
//The createShape() method is the core method of the factory pattern.
//ensures proper destruction of the factory object when it goes out of scope.
//this abstract ShapeFactory class, the factory design pattern establishes a standard interface for creating Shape objects, allowing different concrete factories to handle the creation of specific shape types.
//The abstract nature of the createShape() method allows concrete factory classes to implement their own version of this method, specializing in creating specific types of Shape objects. For example, a CircleFactory class would implement the createShape() method to create Circle objects, while a SquareFactory class would implement it to create Square objects.

//Abstract Factory (ShapeFactory):
class ShapeFactory {
    public:
            virtual std::unique_ptr<Shape> createShape(const std::string& type, double parameter)const noexcept = 0;
            virtual ~ShapeFactory()=default;
};

//the CircleFactory class represents a concrete factory that specializes in creating Circle objects. It inherits from the abstract ShapeFactory class and overrides the createShape() method to handle the creation of Circle objects specifically.
//The CircleFactory class demonstrates how concrete factories implement the abstract factory interface, providing specialized creation logic for specific concrete shape classes.

//Concrete Factories (CircleFactory, SquareFactory):
class CircleFactory : public ShapeFactory {
    public:
            std::unique_ptr<Shape> createShape(const std:string& type,double parameter)const override{
                if(type == "circle")
                {
                    return std::make_unique<Circle>(parameter);
                }
           
};

//the CircleFactory class represents a concrete factory that specializes in creating Circle objects. It inherits from the abstract ShapeFactory class and overrides the createShape() method to handle the creation of Circle objects specifically.
//The CircleFactory class demonstrates how concrete factories implement the abstract factory interface, providing specialized creation logic for specific concrete shape classes.

//Concrete Factories (CircleFactory, SquareFactory):
class SquareFactory : public ShapeFactory {
    public:    
            std::unique_ptr<Shape> createShape(const std::string& type,double parameter)const override{
                if(type == "square")
                 {
                    return std::make_unique<Square>(parameter);
                 }
            }
};

//The client code interacts with the factory to create the desired Shape object without needing to know the specific concrete shape implementation. This promotes flexibility, maintainability, and extensibility in the code.
//Client Code (Main Function):
int main()
{
    std::unique_ptr<ShapeFactory> factory = std::make_unique<CircleFactory>();
    std::unique_ptr<Shape> shape = factory->createShape("circle",5.0);
    shape->draw();
    shape->getArea();
}



...x...

FACTORY DP EXTENSION:

Abstract Product (Shape):
This is an abstract class (or interface) that declares the interface for a type of product.

Concrete Products (Circle, Square): concrete implementations of the abstract product.


Abstract Factory (ShapeFactory): This is an interface or abstract class that declares the interface for creating the abstract products (in this case, Shape).


Concrete Factories (CircleFactory, SquareFactory):
These are concrete implementations of the abstract factory.


Client Code (Main Function): The client code uses the abstract factory to create instances of concrete products without knowing their specific classes. It relies on the abstract interfaces provided by the factory and the product.

On Sun, Nov 12, 2023 at 3:48 PM ujjwal chitransh <ujjwalchitransh1@gmail.com> wrote:
FACTORY DESIGN PATTERN ::

//In object-oriented programming (OOP), a concrete class is a class that implements the details of an abstract class or interface. It provides a complete implementation of all the methods and attributes defined in the abstract class or interface, making it instantiable and usable.
//In the context of the factory design pattern example, the concrete classes are Circle and Square. They implement the abstract Shape interface by providing specific implementations for drawing and calculating the area of circles and squares, respectively. These classes are instantiable, and their objects can be used to draw and calculate the area of their respective shapes.
//the Shape class serves as an abstract base class for all concrete shape classes
//By defining this abstract Shape class, the factory design pattern can create objects of different shapes without the client code needing to know the specific type of shape being created. The concrete shape factories handle the creation of the appropriate concrete shape objects based on the input type and parameter.

class Shape {
    public: 
            virtual void draw() const noexcept = 0;
            virtual double getArea() const noexcept = 0;
            virtual ~Shape()=default;
};

//the Circle class represents a concrete implementation of the abstract Shape class. It encapsulates the specific behavior and attributes of a circle shape.
//utilizes these concrete shape classes to create objects of the desired type based on input information.
class Circle :  public Shape {
    private:    
            double radius;
    public:
            Circle(double radius):radius(radius){}
            void draw() const override{
                std::cout << "Drawing a circle with radius" << radius << std::endl;
            }
            double getArea() const override{
                return M_PI*radius*radius;
            }
};

//the Square class represents a concrete implementation of the abstract Shape class, specifically for square shapes. 
//The Square class demonstrates how concrete shape classes implement the abstract Shape interface, providing specific behavior and attributes for different types of shapes.
class Square : public Shape {
    private:
            double side;
    public:
            Square(double side):side(side){}
            void draw() const override{
                std::cout << "Drawing a square with side length"<<side<<std::endl;
            }
            double getArea() const override{
                return side*side;
            }
};
//the ShapeFactory class represents an abstract factory that defines the interface for creating different types of Shape objects.
//The createShape() method is the core method of the factory pattern.
//ensures proper destruction of the factory object when it goes out of scope.
//this abstract ShapeFactory class, the factory design pattern establishes a standard interface for creating Shape objects, allowing different concrete factories to handle the creation of specific shape types.
//The abstract nature of the createShape() method allows concrete factory classes to implement their own version of this method, specializing in creating specific types of Shape objects. For example, a CircleFactory class would implement the createShape() method to create Circle objects, while a SquareFactory class would implement it to create Square objects.

class ShapeFactory {
    public:
            virtual std::unique_ptr<Shape> createShape(const std::string& type, double parameter)const noexcept = 0;
            virtual ~ShapeFactory()=default;
};

//the CircleFactory class represents a concrete factory that specializes in creating Circle objects. It inherits from the abstract ShapeFactory class and overrides the createShape() method to handle the creation of Circle objects specifically.
//The CircleFactory class demonstrates how concrete factories implement the abstract factory interface, providing specialized creation logic for specific concrete shape classes. 
class CircleFactory : public ShapeFactory {
    public:
            std::unique_ptr<Shape> createShape(const std:string& type,double parameter)const override{
                if(type == "circle")
                {
                    return std::make_unique<Circle>(parameter);
                }
            
};

//the CircleFactory class represents a concrete factory that specializes in creating Circle objects. It inherits from the abstract ShapeFactory class and overrides the createShape() method to handle the creation of Circle objects specifically.
//The CircleFactory class demonstrates how concrete factories implement the abstract factory interface, providing specialized creation logic for specific concrete shape classes.
class SquareFactory : public ShapeFactory {
    public:     
            std::unique_ptr<Shape> createShape(const std::string& type,double parameter)const override{
                if(type == "square")
                 {
                    return std::make_unique<Square>(parameter);
                 }
            }
};

//The client code interacts with the factory to create the desired Shape object without needing to know the specific concrete shape implementation. This promotes flexibility, maintainability, and extensibility in the code.
int main()
{
    std::unique_ptr<ShapeFactory> factory = std::make_unique<CircleFactory>();
    std::unique_ptr<Shape> shape = factory->createShape("circle",5.0);
    shape->draw();
    shape->getArea();
}
