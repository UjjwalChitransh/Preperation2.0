#include <iostream>

template <typename T>
//memory allocation and deallocation are still required when using a unique pointer. 
//The unique pointer class manages the ownership of the allocated memory and automatically deallocates it when the unique pointer goes out of scope. 
//However, the actual memory allocation is still performed using the new operator, and the memory is not automatically deallocated until the unique pointer goes out of scope or is explicitly released.
//The unique pointer class simplifies memory management by automatically deallocating the allocated object when it is no longer needed. 
//However, it is important to note that memory allocation and deallocation still occur, and the unique pointer does not magically eliminate the need for manual memory management.


class UniquePtr {
    private:
            T* ptr_;
    public: 
            //Constructor
            //The explicit keyword prevents the constructor from being called implicitly when converting from a raw pointer to a UniquePtr object. 
            // This helps to avoid accidental conversions and ensures that ownership of the pointer is explicitly transferred to the UniquePtr.
            //Initialization List: -->  The ptr_(ptr) initialization list assigns the value of the ptr parameter to the ptr_ member variable.
            explicit UniquePtr(T* ptr = nullptr) :  ptr_(ptr) { 

            }

            //Destructor
            // the destructor calls the delete operator to deallocate the memory pointed to by ptr_
            //This ensures that the memory is properly freed when the UniquePtr object goes out of scope.
            ~UniquePtr(){
                delete ptr_;
            }

            //Move constructor
            //The move constructor is responsible for transferring ownership of the managed object from one UniquePtr object to another.
            // In this case, the move constructor efficiently transfers ownership of the managed object without copying it, saving memory and improving performance.
            //This effectively transfers ownership of the managed object from the otherUniquePtr object to the newly constructed UniquePtr object.
            //By assigning nullptr to other.ptr_, the move constructor ensures that the otherUniquePtr object no longer owns the managed object.
            UniquePtr(UniquePtr&& other) noexcept : ptr_(other.ptr_){
                other.ptr_ = nullptr;
            }

            //Move assignment
            //The move assignment operator is responsible for transferring ownership of the managed object from one UniquePtr object to another.
            UniquePtr& operator=(UniquePtr&& other) noexcept {
                if(this != &other)
                {
                    delete ptr_;
                    ptr_ = other.ptr_;
                    other.ptr_ = nullptr;
                }
                //The return *this; statement returns a reference to the current UniquePtr object. This allows for chained assignments, such as ptr = anotherPtr = uniquePtr;
                //The const qualifier indicates that the overloaded arrow operator does not modify the UniquePtr object or the managed object.
                return *this;
            }

            //overload arrow operator
            //The overloaded arrow operator (->) provides a convenient way to access the member variables of the managed object through the UniquePtr object. It is called when the -> operator is used on a UniquePtr object.
            T* operator->() const{
                return ptr_;
            }

            //dereferenence operator
            //The overloaded dereference operator (*) provides a way to access the managed object directly through the UniquePtr object.
            T& operator*() const{
                return *ptr_;
            }


            //UniquePtr<int> ptr(new int(42));
            //UniquePtr<int> ptr2(std::move(ptr));
            std::cout<< *ptr << std::endl;

}
