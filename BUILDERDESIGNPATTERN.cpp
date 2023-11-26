//Builder Interface - PizzaBuilder
//Abstract Builder - Declares the steps to build a product - pizza.
//Pizzabuilder Interface - fundamental methods required for building a pizza.
class Pizzabuilder {
public:
        virtual PizzaBuilder& setDough(const std::string& dough)=0;
        virtual PizzaBuilder& setSauce(const std::string& sauce)=0;
        virtual PizzaBuilder& setTopping(const std::string& topping)=0;
        virtual Pizza* build()=0;
};


//Concrete Builder - Hawaiin Pizza Builder
//class implements 'Pizzabuilder' interface for creating specific type of pizza
//keeps a pointer to the product being constructed.
//HawaiianPizzaBuilder class -->  implements Pizzabuilder interface specifically for creating Hawaiian pizzas.
//refernece to the product being constructed - HawaiianPizza.
class HawaiianPizzaBuilder : public Pizzabuilder {
        private:
                HuwauuanPizzaBuilder* pizza_;
        public:
                virtual Pizzabuilder& setDough(const std::string& dough)override {
                        pizza_->setDough(dough);
                        return *this;
                }

                virtual Pizzabuilder& setSauce(const std::string& sauce)override {
                        pizza_->setSauce(sauce);
                        return *this;
                }

                virtual Pizzabuilder& setTopping(const std::string& topping)override{
                        pizza_->setTopping(topping);
                        return *this;
                }

                virtual Pizza *build()override{
                        return pizza_;
                }

}

//Product - Pizza
class Pizza {
        public: 
                virtual std::string getPizzaDescription() const = 0;
};

//Concrete Product - Hawaiian Pizza
//provides a method to get description of pizza
//HawaiianPizza class - represents the actual product being built.
class HawaiianPizza : public Pizza
{
        private:
                std::string dough_;
                std::string sauce_;
                std::string topping_;
        public:
                virtual std::string getPizzaDescription() const override;

};

//Director - PizzaDirector
//reponsible for using builder to construct a poduct
//high level interface o construct a complex product with a specific configuration
//PizzaDirector class - acts as a client for builder pattern.It orchestrates the construction of a 
//speicific pizza type(Hawaiian pizza in this case)- by utilizing the HawaiianPizzaBuilder instance.
class PizzaDirector{
        public: 
                Pizza* buildHawaiianPizza()
                {
                        HawaiianPizzaBuilder builder;
                        builder.setDough("Thin crust");
                        builder.setSauce("Sweet and sour");
                        builder.setTopping("Ham and pineapple");
                        return builder.build();
                }
};


//Director uses builder to construct pizza.
//Client code interacts with the constructed pizza.
//Demonstrates usage of the PizzaDirector to create a Hawaiian pizza and display its description.
int main()
{
        PizzaDirector director;
        Pizza* pizza = director.buildHawaiianPizza();
        pizza->bakePizza();
        std::cout << pizza->getPizzaDescription() << std::endl;
        delete pizza;
        return 0;
}
