
#ifndef DESIGNERMODE_PROARRAY_H
#define DESIGNERMODE_PROARRAY_H

#include <iostream>
#include <sstream>
#include <iterator>
// 顺序表抽象类---------简单的vector实现
template<typename Type>
class VProLinearList {
public:
    virtual ~VProLinearList() = default;

    virtual bool empty() const = 0;

    virtual int size() const = 0;

    virtual Type &get(int index) const = 0;

    virtual int indexOf(const Type &element) const = 0;

    virtual void insert(int index, const Type &element) = 0;

    virtual void erase(int index) = 0;

    virtual void output(std::ostream &out) const = 0;
};

template<typename Type>
class ProVector : public VProLinearList<Type> {
public:
    explicit ProVector(int initialCapacity = 10);

    ~ProVector() override;

    inline bool empty() const override {
        return listSize == 0;
    }

    inline int getCapacity() const {
        return arrayLength;
    }

    inline int size() const override {
        return listSize;
    }


    Type &get(int index) const override;

    int indexOf(const int &element) const override;

    void insert(int index, const int &element) override;

    void erase(int index) override;

    void output(std::ostream &out) const override;

protected:
    void checkIndex(int index) const;
    void changeLength1D(Type *a, int oldLength, int newLength);
    Type *m_element;
    int arrayLength;//数组容量
    int listSize;
};

template<typename Type>
void ProVector<Type>::output(std::ostream &out) const {
    std::copy(m_element, m_element + listSize, std::ostream_iterator<Type>(out, " "));

}

template<typename Type>
void ProVector<Type>::erase(int index) {
    checkIndex(index);
    std::copy(m_element + index + 1, m_element + listSize, m_element + index);
    m_element[--listSize].~Type();

}

template<typename Type>
void ProVector<Type>::changeLength1D(Type *a, int oldLength, int newLength) {
    if (newLength < 0) {
        throw "new length must be >= 0";
    }
    Type *temp = new Type[newLength];
    int number = std::min(oldLength, newLength);
    std::copy(a, a + number, temp);
    delete[] a;
    a = temp;

}

template<typename Type>
void ProVector<Type>::insert(int index, const int &element) {
    checkIndex(index);
    if (listSize == arrayLength) {
        changeLength1D(m_element, arrayLength, 2 * arrayLength);
        arrayLength *= 2;
    }
    std::copy_backward(m_element + index, m_element + listSize, m_element + listSize + 1);
    m_element[index] = element;
    ++listSize;

}

template<typename Type>
int ProVector<Type>::indexOf(const int &element) const {
    for (int i = 0; i < listSize; ++i) {
        if (this->m_element[i] == element) {
            return i;
        }
    }
    return -1;
}

template<typename Type>
Type &ProVector<Type>::get(int index) const {
    return m_element[index];
}

template<typename Type>
void ProVector<Type>::checkIndex(int index) const {
    if (index < 0 || index >= listSize) {
        std::ostringstream s;
        s << "index = " << index << " size = " << listSize;
        throw std::out_of_range(s.str());
    }

}

template<typename Type>
ProVector<Type>::~ProVector() {
    delete[] m_element;
}

template<typename Type>
ProVector<Type>::ProVector(int initialCapacity) {
    if (initialCapacity < 1) {
        std::ostringstream s;
        s << "Initial capacity = " << initialCapacity << " Must be > 0";
        throw std::invalid_argument(s.str());
    }
    arrayLength = initialCapacity;
    m_element = new Type[arrayLength];
    listSize = 0;
}

#endif //DESIGNERMODE_PROARRAY_H
