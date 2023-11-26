#include <iostream>

template<typename T>

#if 0
Shared Ownership Across Threads:

Provides shared ownership semantics suitable for use in multithreaded environments.
The reference count operations are designed to be thread-safe, enabling shared ownership across threads

#endif

class SharedPtr {
    public:
    //Constructor
    explicit SharedPtr(T*ptr = nullptr): data_(new ControlBlock(ptr)){
    }
    //SharedPtr<int> sharedIntPtr(new int(42));  
    //a SharedPtr<int> is created, and it takes ownership of a dynamically allocated int with the value 42.
    //The reference count is initially set to 1 because this SharedPtr is the first and only owner of the object.
    //Copy Constructor
    SharedPtr(const SharedPtr& other) :  data_(other.data_){
        if(data_){
            data_->incrementRefCount();
        }
    }

    //Copy assignment
    SharedPtr& operator=(const SharedPtr& other){
        if(this != &other)
        {
            //decrement the reference count of the current object
            //It decrements the reference count of the current object,deallocates resources if needed
            if(data_ && data_->decrementRefCount() == 0)
            {
                delete data_->ptr;
                delete data_;
            }

            //copy the control block data from the other sharedptr
            //copies the control block data from the other SharedPtr, updating the reference count accordingly.
            data_ = other.data_;

            //increment the refernece count of the shared object
            if(data_)
            {
                data_->incrementRefCount();
            }
        }
        return *this;
    }


    //Destructor
    ~SharedPtr(){
        if(data_ && data_->decrementRefCount() == 0)
        {
            delete data_->ptr;
            delete data_;
        }
    }

    //Overloaded arrow operator
    T* operator->() const{
        return data_->ptr;
    }

    //Dereference operator
    T& operator*() const{
        return *(data_->ptr);
    }

    //Move constructor
    SharedPtr(SharedPtr && other)noexcept : data_(other.data_){
        other.data_ = nullptr; //source SharedPtr doesn't manage the object anymore.
    }

    //Move assignment 
    SharedPtr& operator=(SharedPtr&& other) noexcept
    {
        if(this != &other)
        {
            //Decrement the reference count of the current object
            if(data_  && data_->decrementRefCount() == 0)
            {
                delete data_->ptr;
                delete data_;
            }

            //Transfer owership from the other sharedPtr
            data_ = other.data_;
            //Source sharePtr doesn't manage the object anymore
            other.data_ = nullptr; 
        }
        return *this;
    }

    private:
    //Control block keeps track of the shared object and its reference count
    struct ControlBlock {
        //pointer to the reference object
        T* ptr;
        //reference count tracking the number of shared pointers
        std::size_t refCount;
        //Constructor initializes the ControlBlock with a pointer and initial reference count of 1.
        explicit ControlBlock(T* p) :  ptr(p) , refCount(1)
        {

        }

        //Increment the reference count
        void incrementRefCount(){
            ++refCount;
        }

        //Decrement the reference count and return the updated value
        std::size_t decrementRefCount(){
            return --refCount;
        }
    };

    ControlBlock* data_;
}
