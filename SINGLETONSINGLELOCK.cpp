#include<iostream>
#include<mutex>

class Singleton
{
    public:
    //static method is the public interface to access the singleton instance.it employs 
    // double checked locking to improve initialization efficiency.
    // It involves checking the status of the singleton instance twice, once before acquiring a lock and once after acquiring the lock. This optimization is intended to reduce the overhead of acquiring the lock in cases where the singleton instance has already been initialized.

            static Singleton& getInstance()
            {
                //Double checked locking for efficiency
                if(instance == nullptr)
                {
                    std::lock_guard<std::mutex> lock(mutex); 
                //If the instance is not yet initialized, a lock is acquired using std::lock_guard<std::mutex> lock(mutex). This lock ensures that only one thread can access the instance variable at a time, preventing race conditions.
                // Locking
                //Check again inside the lock to avoid race condition
                //to ensure that no other thread has initialized the singleton instance while the current thread was waiting for the lock.
                    if(instance == nullptr)
                    {
                        //If the second check also confirms that the instance is not yet initialized, the singleton instance is created (instance = new Singleton()). This initialization happens within the lock, ensuring thread-safe creation of the singleton.
                        instance = new Singleton();
                    }
                }
                //returns the reference to the initialized singleton instance 
                return *instance;

            }

    private:
            //Constructor and Destructor are declared private to prevent direct instantiation and deletion
            //of single objects , enforcing the singleton pattern.
            //Private Constructor to prevent instantiation.
            Singleton() {  }
            //Private destructor to prevent deletion using pointers
            ~Singleton() {  }
            //copy construction and assignment operator are declared as deleted to prevent cloning
            //of the single instance.
            //Private copy constructor and assignment operator to prevent cloning.
            Singleton(const Singleton&)=delete;
            Singleton& operator=(const Singleton&)=delete;
            //Private instance of the singleton
            //static member variable holds singleton instance.
            static Singleton* instance;
            //Mutex for thread safety
            //static member variable is a mutex object used to synchronize access to the instance
            //variable, ensuring thread safety.
            static std::mutex mutex;
};

//Static member variable initialization.
//static member variables are initialized outside the class definition ensuring their existence
//before the first call to getInstance()
Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mutex;


int main()
{
    //Access to the singleton instance
    Singleton& mySingleton = Singleton::getInstance();
    //use the singleton instance
    return 0;
}
