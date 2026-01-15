template<typename T>
MyUniquePointer<T>::MyUniquePointer(T* pointer) {
	this->pc_pointer = pointer;
}

template<typename T>
MyUniquePointer<T>::MyUniquePointer(MyUniquePointer&& other) {
    this->pc_pointer = other.pc_pointer; 
    other.pc_pointer = nullptr;
}

template<typename T>
MyUniquePointer<T>& MyUniquePointer<T>::operator=(MyUniquePointer&& other) noexcept{
    if (this != &other) {
        delete pc_pointer
        this->pc_pointer = other.pc_pointer; 
        other.pc_pointer = nullptr;      
    }
    return *this;
}

template<typename T>
MyUniquePointer<T>::~MyUniquePointer() {
    if (pc_pointer != nullptr) {
        delete this->pc_pointer;
    }  
}

template<typename T>
T& MyUniquePointer<T>::operator->() {
	return this->pc_pointer;
}

template<typename T>
T* MyUniquePointer<T>::operator*() {
	return *(this->pc_pointer);
}