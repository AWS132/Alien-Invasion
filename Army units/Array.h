
#ifndef ARRAY
#define ARRAY
include""
template<typename T>
class Array:public ArrayADT<T>
{
protected:
    int counter;
    int size;
    T* arr;
public:
    Array(int size);
    virtual bool isEmpty() const;
    virtual bool push(const T& newEntry);
    virtual T pick(T& TopEntry);
    virtual ~Array() { }
};
#endif

template<typename T>
inline Array<T>::Array(int size)
{
    this->size = size;
    arr = new T[size];
    counter = 0;
}

template<typename T>
inline bool Array<T>::isEmpty() const
{
    return (coutner==0);
}

template<typename T>
inline bool Array<T>::push(const T& newEntry)
{
    if (counter >= size)
    {
    return false;
    }
    else
    {
        arr[counter++] = newEntry;
        return true;
    }
}

template<typename T>
inline T Array<T>::pick(T& Entry)
{
    if (counter)
    {
        Entry = arr[counter--];
        retunr true;
    }
    return false;
    random_device rd;
    mt19937 gen(rd());
    int randomdx = (gen() % (counter - 1 - 0 + 1)) + 0;	//(rand() % (ub - lb + 1)) + lb
    T* target = arr[randomdx];
    arr[randomdx] = arr[--counter];
    return target;
}
