#ifndef _SMART_PTR_HPP
#define _SMART_PTR_HPP

#include <stddef.h>

template<typename T>
class SmartPtr {
	public:
		SmartPtr();
		SmartPtr(T* value);
		~SmartPtr();
		
		SmartPtr(const SmartPtr<T>& sp);
		SmartPtr<T>& operator = (const SmartPtr<T>& sp);
		
		bool isNull() const;
	
		T& operator * () const;
		T* operator -> () const;
		
	private:
		unsigned int *_refs;
		T* _value;
};

template <typename T>
SmartPtr<T>::SmartPtr() : _value(NULL) {
	_refs = new unsigned int;
	*_refs = 1;
}

template <typename T>
SmartPtr<T>::SmartPtr(T* value) : _value(value) {
	_refs = new unsigned int;
	*_refs = 1;
}

template <typename T>
SmartPtr<T>::~SmartPtr() {
	if (--(*_refs) == 0) {
		delete _refs;
		
		if (_value)
			delete _value;
	}
}

template <typename T>
SmartPtr<T>::SmartPtr(const SmartPtr<T>& sp) : _value(sp._value) {
	_refs = sp._refs;
	(*_refs)++;	
}

template <typename T>
SmartPtr<T>& SmartPtr<T>::operator = (const SmartPtr<T>& sp) {
	if (this != &sp) {
		if(--(*_refs) == 0) {
			delete _refs;
			
			if (_value)
				delete _value;
		}
	
		_value = sp._value;
		_refs = sp._refs;
		
		(*_refs)++;
	}
	
	return *this;
}

template <typename T>	
bool SmartPtr<T>::isNull() const {
	return (_value == NULL);
}

template <typename T>	
T& SmartPtr<T>::operator * () const {
	return *_value;
}

template <typename T>
T* SmartPtr<T>::operator -> () const {
	return _value;
}

#endif
