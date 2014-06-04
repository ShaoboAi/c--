template<class T>
class smart_ptr
{
public:
    smart_ptr();

    smart_ptr(T* value);
    smart_ptr& operator=(const smart_ptr& sp);
    ~smart_ptr();
private:
    smart_ptr(const smart_ptr& sp);
    T* p;//T& p;
    int* counter;
};

template<class T>
smart_ptr<T>::smart_ptr():p(NULL),counter(NULL)
{
}

template<class T>
smart_ptr<T>::smart_ptr(T* value):p(value)
{

    counter = new int();
    *counter = 1;
}

template<class T>
smart_ptr<T>& smart_ptr<T>::operator=(const smart_ptr& sp)
{
    if(this != &sp)
    {
        counter = sp.counter;
        p = sp.p;
        *counter += 1;
    }
    return *this;
}

template<class T>
smart_ptr<T>::~smart_ptr()
{
    if(--*counter == 0 )
    {
        delete p;
        delete counter;
    }

}

