// RAII: "resource acquisition is initialization" --> basic idea is to represent a resource by a
//local object  , so that the local object's destructor will release the resource.
//https://www.stroustrup.com/bs_faq2.html#finally
class File_handle
{
    private:    
            FILE* p;
    public:
            File_handle(const char*n,const char* a)
            {
                p = fopen(n,a);
                if(p)
                {
                    throw Open_error(errno);
                }
            }     
            File_handle(FILE *pp)
            {
                p = pp;
                if(p)
                {
                    throw Open_error(errno);
                }
            }
            ~File_handle()
            {
                fclose(p);
            }
            operator FILE*()
            {
                return p;
            }
};


void f(const char* fn)
{
    File_handle f(fn,"rw"); //open fn for reading and writing.
    //use file through f
}

....x....


https://en.cppreference.com/w/cpp/language/raii

std::mutex m;

void good()
{
    //RAII class: mutex acquisition is initialization
    std::lock_guard<std::mutex> lk(m);
    f(); //if f() throws an exception, the mutex is released.
    if(!everything_ok()) //early return , the mutex is released.
    return;              //if good() returns normally, the mutex is released.

}


..x...



//https://stackoverflow.com/questions/2321511/what-is-meant-by-resource-acquisition-is-initialization-raii

//Scope-Bound Resource Management
//'Resource' we don't just mean memory - it could be file handles, network sockets, database handles, GDI objects... In short, things that we have a finite supply of and so we need to be able to control their usage. 
//The 'Scope-bound' aspect means that the lifetime of the object is bound to the scope of a variable, so when the variable goes out of scope then the destructor will release the resource. A very useful property of this is that it makes for greater exception-safety.



..x..



//https://learn.microsoft.com/en-us/cpp/cpp/object-lifetime-and-resource-management-modern-cpp?view=msvc-170&redirectedfrom=MSDN
//As the object gets initialized, it acquires the resource it owns. The object is then responsible for releasing the resource in its destructor. 
//The principle that objects own resources is also known as "resource acquisition is initialization," or RAII.
//garbage collection in C++ is closely related to object lifetime, and is deterministic.


class widget {
    private:
            gadget g; // lifetime closely tied to enclosing object.
    public:
            void draw();
}

void functionUsingWidget()
{
    widget w;// lifetime atomatically tied to enclosing scope
            //constructs w --> including w.g gadget member.
    w.draw();
}
//automatic destruction and deallocation for w and w.g 
//automatic exception safety,
//as it "finally { w.dispose();  w.g.dispose(); }"



class widget{
    private:
            int *data;
    public:
            widget(const int size)
            {
                data = new int[size]; // acquire
            }
            ~widget()
            {
                delete[] data;// release
            }
            void do_something()
            {

            }
};

void functionUsingWidget()
{
    widget w(100);//lifetime automactially tied to enclosing scope.
                  //constructs w ,inclusing w.data member
    w.do_something();
}//automatic destruction and deallocation for w and w.data



C++11 SMARTPOINTER
//This model works for other resources, such as file handles or sockets.
#include<memory>
class widget
{
private:
        std::unique_ptr<int[]> data;
public:
        widget(const int size)
        {
            data=std::make_unique<int[]>(size);
        }
        void do_something()
        {

        }
}
