#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

using namespace std;

        /**
        * @brief    setting the initial vector size to a constant
        *
        *           constant starting value for the vector size.
        *           Allows for changing easily.
        *
        */

const int INITIAL_VECTOR_SIZE = 4;

/**
* @class Vector
* @brief Custom Vector class
*
* Contains a private Vector class with only the needed functions.
* Not overly bloated with unused functions like the STL vector class
*
* @author Joshua Oh
* @version 01
* @date 14/10/2022 Joshua Oh, Started by creating the basic functions
*                             for the custom Vector.
*
* @author Joshua Oh
* @version 02
* @date 16/10/2022 Joshua Oh, Added more functions to the class.
*
*
* @todo Submit to LMS.
*
* @bug Hopefully none.
*/
template <class T>
class Vector
{
private:
    /// Capacity of the vector. can be increased using resize function
    int m_allocation;

    /// Amount of space taken up in the vector
    int m_size;

    /// template T pointer to array
    T* m_array;

        /**
        * @brief    function to multiply the vector's capacity
        *
        *           Function that will multiply the vector's capacity by 2.
        *           Is called by the Add function when size is check and
        *           determined to be less than capacity / 2. Is a private
        *           function as only functions in this class calls it.
        * @return   void
        */
    void Resize();

public:

        /**
        * @brief    default constructor for the Vector
        *
        *           default constructor with no parameters to be passed.
        *           set to default values.
        *
        */

    Vector();

        /**
        * @brief    Copy Constructor
        *
        *           Copy constructor to create another copy of a vector
        *           using deep copy to ensure original vector is not
        *           corrupted.
        * @param    Vector &vector - Reference of another vector
        */
    Vector(Vector &vector);

        /**
        * @brief    Destructor for the Vector, destroys the container object.
        *
        *           deallocates all the storage capacity allocated by the vector
        *           and sets it to point to null pointer.
        */

    ~Vector();

        /**
        * @brief    function to add an element to the Vector at the last position
        *
        *           Will do a check to see if size is less than capacity / 2.
        *           If so, will invoke the Resize() function. After which,
        *           it will proceed to add the item at the current pointer location
        *           and increment the size.
        * @param    T item - T object.
        * @return   bool
        */

    bool Add(T item);

        /**
        * @brief    function to remove an element at a specific location
        *
        *           Uses integer to  determine position of element to be removed.
        *           Copies element at position integer + 1 to the initial position
        *           and decrease the size of the Vector.
        * @param    int index - integer used to determine the position of the element
        *           to be removed.
        * @return   void
        */

    void Remove(int index);

        /**
        * @brief    function to return the reference to an element at a specified position
        *
        *           Uses integer to  determine position of element to be removed.
        *           Returns a reference to the element at the position determined in
        *           the vector
        * @param    int index - integer used to determine the position of the element
        *           to be returned.
        * @return   Reference to T object at i position
        */

    T &at(int i);

        /**
        * @brief    Returns the number of elements in the array
        *
        *           Returns the number of actual objects held in the vector. Different
        *           from capacity. Will check if the position of the element is within
        *           bounds of valid elements in the vector.
        * @param    int index - integer used to determine the position of the element
        *           to be removed.
        * @return   int
        */

    int GetSize() const;

        /**
        * @brief    Returns the capacity of the vector
        *
        *           Returns the amount of storage space allocated for the vector.
        *           Can be equal or greater than vector size.
        *
        * @return   int
        */

    int GetAllocation() const;

        /**
        * @brief    Removes all elements from the vector
        *
        *           Removes all elements from the vector calling
        *           the destructor and setting the size to 0. Capacity is not changed
        *
        * @return   void
        */

    void Clear();

        /**
        * @brief    Overloaded = operator
        *
        *           Assigns contents of original vector to the new container and modify its size
        *           according to the number of elements copied.
        * @param    const Vector &vector - Reference to a vector whose elements are
        *           to be copied
        * @return   Vector <T>&
        */

    Vector<T>& operator=(const Vector &vector);

        /**
        * @brief    Returns a reference to the element at a specified position
        *
        *           Returns the number of actual objects held in the vector. Different
        *           from capacity. Does not check whether the element at position
        *           specified is within bounds of valid elements in the vector
        *
        * @return   T&
        */

    const T& operator[](int i);
};

template <class T>
Vector<T>::Vector()
{
    m_allocation = INITIAL_VECTOR_SIZE;
    m_size = 0;
    m_array = new T[m_allocation];
    if(m_array == nullptr)      // memory allocation fails
    {
        m_allocation = 0;
    }
}

template <class T>
Vector<T>::Vector(Vector &vector)
{
    m_size = vector.m_size;
    m_allocation = vector.m_allocation;
    m_array = new T[m_allocation];            // deep copy

    for (int i = 0; i < m_size; i++)
    {
        m_array[i] = vector.m_array[i];
    }
}

template <class T>
Vector<T>::~Vector()
{
    if(m_array != nullptr)
    {
        delete[] m_array;
    }
    m_array = nullptr;
}

template <class T>
bool Vector<T>::Add(T item)
{
    if (m_size > m_allocation / 2)
    {
        Resize();
    }
    if(m_size < m_allocation)
    {
        m_array[m_size++] = item;
        return true;
    }
    return false;
}

template <class T>
void Vector<T>::Remove(int index)
{
    m_array[index].~T();
    for(int i = index; i < m_size - 1; i++)
    {
        m_array[i] = m_array[i+1];
    }
    m_size--;
}

template <class T>
T &Vector<T>::at(int i)
{
    if((i >= 0) && (i < m_size))
    {
        return m_array[i];
    }

    return m_array[0];
}

template <class T>
int Vector<T>::GetSize() const
{
    return m_size;
}

template <class T>
int Vector<T>::GetAllocation() const
{
    return m_allocation;
}

template <class T>
void Vector<T>::Resize()
{
    m_allocation = m_size * 2;
    T* newarray = new T[m_allocation];

    for(int i = 0; i < m_size; i++)
    {
        newarray[i] = m_array[i];
    }
    delete m_array;
    m_array = newarray;
}

template <class T>
void Vector<T>::Clear()
{
    for (int i = 0; i < m_size; i++)
    {
        m_array[i].~T();
    }
    m_size = 0;
}

template <class T>
Vector<T>& Vector<T>::operator =(const Vector<T> &vector)
{
    if(this != &vector)
    {
        delete m_array;
        m_size = vector.m_size;
        m_allocation = vector.m_allocation;
        m_array = new T[m_allocation];          // deep copy
    }
    for(int i = 0; i < vector.m_size; i++)
    {
        m_array[i] = vector.m_array[i];
    }
    return *this;
}

template <class T>
const T& Vector<T>::operator[](const int i)
{
    return m_array[i];
}

#endif // VECTOR_H_INCLUDED
