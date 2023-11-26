STRING CLASS:



#include <iostream>
#include <cstring>

class String {
private:
    char* str;

public:
    // Constructors
    String() : str(nullptr) {}
   
    String(const char* s) {
        if (s) {
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        } else {
            str = nullptr;
        }
    }

    // Destructor
    ~String() {
        if (str) {
            delete[] str;
        }
    }

    // Copy constructor
    String(const String& other) {
        if (other.str) {
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        } else {
            str = nullptr;
        }
    }

    // Move constructor
    String(String&& other) noexcept {
        str = other.str;
        other.str = nullptr;
    }

    // Assignment operator
    String& operator=(const String& other) {
        if (this != &other) {
            if (other.str) {
                delete[] str;
                str = new char[strlen(other.str) + 1];
                strcpy(str, other.str);
            } else {
                delete[] str;
                str = nullptr;
            }
        }
        return *this;
    }

    // Move assignment operator
    String& operator=(String&& other) noexcept {
        if (this != &other) {
            delete[] str;
            str = other.str;
            other.str = nullptr;
        }
        return *this;
    }

    // Getter function
    const char* c_str() const {
        return str;
    }

    // Overloaded + operator for concatenation
    String operator+(const String& other) const {
        String result;
        if (str && other.str) {
            result.str = new char[strlen(str) + strlen(other.str) + 1];
            strcpy(result.str, str);
            strcat(result.str, other.str);
        } else if (str) {
            result = *this;
        } else if (other.str) {
            result = other;
        }
        return result;
    }
};

// Overloaded << operator for easy printing
std::ostream& operator<<(std::ostream& os, const String& s) {
    os << s.c_str();
    return os;
}

int main() {
    String s1("Hello, ");
    String s2("world!");

    String s3 = s1 + s2;

    std::cout << s3 << std::endl;

    String s4 = std::move(s3);  // Move constructor

    std::cout << s4 << std::endl;
    // std::cout << s3 << std::endl;  // This would result in undefined behavior since s3 has been moved

    String s5;
    s5 = std::move(s4);  // Move assignment operator

    std::cout << s5 << std::endl;
    // std::cout << s4 << std::endl;  // This would result in undefined behavior since s4 has been moved

    return 0;
}
...





#include <iostream>
#include <cstring>

class String {
private:
    char* str;

public:
//It initializes the str member variable to nullptr. This means that the string object is initially empty.String s; // This will create an empty string object.
    String():str(nullptr) {   }

    //Constructor
    // is used to create a new string object from a C-style string.It takes a pointer to a C-style string as its argument.
    //const char* c_string = "Hello, world!";
    //String s(c_string);
    String(const char* s)
    {
        if(s)
        {
            str = new char[strlen(s) + 1];
            strcpy(str,s);
        }
        else
        {
            str = nullptr;
        }
    }

    //Destructor
    //responsible for releasing any resources that were allocated by the object. In this case, the only resource that needs to be released is the memory allocated for the string data.
    //use of delete[] is important because it ensures that the memory is properly released back to the operating system. 
    ~String()
    {
        if(str)
        {
            delete[] str;
        }
    }

    //Copy Constructor
    //is the copy constructor for the String class
    //String s1("Hello, world!");
    //String s2(s1); // This will create a copy of the string object s1.
    //This will create a new string object s2 that contains the same contents as the string object s1.
    //When the copy constructor is called, it takes a reference to an existing object.The reference is essentially an alias to the original object; it doesn't involve creating a new copy of the object.
    //The copy constructor can safely operate on the referenced object without triggering another copy constructor call.Recursive calls are prevented because there is no new object being created within the copy constructor itself.
    //Copy Constructor without Reference (Incorrect) -->  When the copy constructor is called, it takes its parameter by value.This parameter passing by value involves creating a new copy of the original object .
    //Creating this new copy invokes the copy constructor again, leading to a recursive loop.
    //By using a reference, you avoid the recursive loop because the reference doesn't trigger the creation of a new object during parameter passing. Instead, it provides a direct way to access the existing object, preventing the infinite recursion that occurs when using a value parameter in the copy constructor.
    String(const String& other)
    {
        if(other.str)
        {
            str = new char[strlen(other.str)+1];
            strcpy(str,other.str);
        }
        else
        {
            str = nullptr;
        }
    }

    //Move constructor
    //takes a reference to a movable string object as its argument and creates a new string object that takes ownership of the resources of the other string object.
    //String s1("Hello, world!");
    //String s2(std::move(s1));  --> Move the ownership of the string object s1 to the new string object s2.The string object s1 is now empty.
    //An rvalue is a temporary value or a value that is about to be destroyed.It does this by taking an rvalue reference to the source object as its argument.
    //It is especially useful for moving large objects, such as string objects and vector objects.
    //An rvalue reference allows the move constructor to bind to temporary objects (rvalues) and steal their resources without making unnecessary copies.
    String(String&& other) noexcept 
    {
        str = other.str;
        other.str = nullptr;
    }

    //Assignmnet operator
    //The assignment operator is used to efficiently copy the contents of one string object to another. 
    //String s1("Hello, world!");
    // String s2;
    // s2 = s1; --> Assign the contents of the string object s1 to the string object s2. 
    // The assignment operator is also used to implement the compound assignment operators, such as += and -=. 
    //These operators allow programmers to efficiently perform operations on strings, such as concatenation and subtraction.
    //The assignment operator returns a reference to the current object -->  to chain multiple assignments together.
    //returning a reference does not require any additional memory allocation or copying.
    String& operator=(const String& other)
    {
        if(this != &other)
        {
            if(other.str)
            {
                delete[] str;
                str = new char[strlen(other.str)+1];
                strcpy(str,other.str);
            }
            else
            {
                delete[] str;
                str = nullptr;
            }
        }
        return *this;
    }

    //Move assignment operator
    //move assignment operator is used to efficiently transfer the ownership of a string object from one object to another without copying it. It does this by stealing the resources of the other string object and assigning them to the current string object.
    //String s1("Hello, world!");
    //String s2;
    //s2 = std::move(s1);  -->  Move the ownership of the string object s1 to the string object s2.
    String& operator=(String&& other) noexcept
    {
        if(this != &other)
        {
            delete[] str;
            str = other.str;
            other.str = nullptr;
        }
        return *this;
    }


    //Getter function
    const char* c_str() const
    {
        return str;
    }

    //Overload + operator for concatenation
    // the concatenation operator for the String class
    //takes a reference to another string object as its argument and returns a new string object that contains the contents of both of the original string objects
    //String s1("Hello, ");
    //String s2("world!");
    //// Concatenate the two strings s1 and s2.
    //String s3 = s1 + s2;
    //// The string object s3 will now contain the string "Hello, world!".
    //The String operator+ returns an object rather than a reference to an object for a couple of reasons related to the design and behavior of the operator:
    //Immutability and Safety: - Returning a new object allows the + operator to create and return a result without modifying the existing objects. 
    //Expression Chaining - Returning an object facilitates expression chaining, allowing you to chain multiple operations together in a single statement
    //Avoiding Dangling References - returning a reference to result would lead to undefined behavior, as result is a local variable whose memory will be deallocated when it goes out of scope.
    String operator+(const String& other)const 
    {
        String result;
        if(str && other.str)
        {
            result.str = new char[strlen(str) + strlen(other.str) +1];
            strcpy(result.str,str);
            strcat(result.str,other.str);
        }
        else if(str)
        {
            result = *this;
        }
        else if(other.str)
        {
            result = other;
        }
        return result;
    }
};


//Overloaded << operator for easy printing
//It takes a reference to a std::ostream object and a reference to a String object as its arguments and prints the contents of the String object to the std::ostream object
//String s("Hello, world!");
// Print the string s to the console.
// cout << s << endl;
//overloaded << operator also allows programmers to print strings to other output streams, such as files and network sockets.
//Return Statement: return os;: The modified output stream (os) is returned. This allows for potential chaining of multiple output operations.
std::ostream& operator<<(std::ostream&os,const String&s)
{
    os<<s.ctr();
    return os;
}


int main()
{
    String s1("Hello, ");
    String s2("world!");
    String s3 = s1 + s2;
    std::cout << s3 << std::endl;
    String s4 = std::move(s3); //Move constructor
    std::cout << s4 << std::endl;
    String s5;
    s5=std::move(s4);//Move assignment operator
    std::cout<<s5<<std::endl;
    return 0;
}











