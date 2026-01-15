template <typename T>
CMySmartPointer<T>::CMySmartPointer(T* pc_pointer) {
	this->pc_pointer = pc_pointer;
	this->pc_counter = new CRefCounter();
	this->pc_counter->iAdd();
}

template <typename T>
CMySmartPointer<T>::CMySmartPointer(const CMySmartPointer& pcOther)
{
	this->pc_pointer = pcOther.pc_pointer;
	this->pc_counter = pcOther.pc_counter;
	pcOther.pc_counter->iAdd();
}
template <typename T>
CMySmartPointer<T>::~CMySmartPointer()
{
    if (this->pc_counter && this->pc_counter->iDec() == 0) {
        delete this->pc_pointer;
        delete this->pc_counter;
    }
}

template <typename T>
CMySmartPointer<T>::CMySmartPointer(CMySmartPointer&& pcOther) {
	this->pc_pointer = pcOther.pc_pointer;
	this->pc_counter = pcOther.pc_counter;
    pcOther.pc_pointer = nullptr;
    pcOther.pc_counter = nullptr;
}

template <typename T>
CMySmartPointer<T>& CMySmartPointer<T>::operator=(CMySmartPointer&& pcOther) noexcept {
    if (this != &pcOther) {
        if (this->pc_counter && this->pc_counter->iDec() == 0) {
            delete this->pc_pointer;
            delete this->pc_counter;
        }
        this->pc_pointer = pcOther.pc_pointer;
        this->pc_counter = pcOther.pc_counter;
        pcOther.pc_pointer = nullptr;
        pcOther.pc_counter = nullptr;
    }
    return *this;

}

template <typename T>
CMySmartPointer<T>& CMySmartPointer<T>::operator=(const CMySmartPointer& pcOther) {
    if (this != &pcOther) {
        if (this->pc_counter && this->pc_counter->iDec() == 0) {
            delete this->pc_pointer;
            delete this->pc_counter;
        }
        this->pc_pointer = pcOther.pc_pointer;
        this->pc_counter = pcOther.pc_counter;
        this->pc_counter->iAdd();
    }
    return *this;
}
template <typename T>
T* CMySmartPointer<T>::operator->()
{
	return this->pc_pointer;
}
template <typename T>
T& CMySmartPointer<T>::operator*()
{
	return *(this->pc_pointer);
}
