#include "Header1.h"
#include <iostream>

//////////////////////////////////////// CONSTRUCTORS STACK //////////////////////////////////////////////

template <typename T, typename Container>
g3::stack<T,Container>::stack():ob(ob){}

template <typename T, typename Container>
g3::stack<T, Container>::stack(const stack& rhv) : ob(rhv.ob) {}

template <typename T, typename Container>
g3::stack<T, Container>::stack(stack&& rhv) : ob(std::move(rhv.ob)){}

template <typename T, typename Container>
g3::stack<T, Container>::stack(std::initializer_list<value_type> init) : ob(init) {}

template <typename T, typename Container>
template <typename InputIt>
g3::stack<T, Container>::stack(InputIt first, InputIt last):ob(first,last){}

template <typename T, typename Container>
g3::stack<T, Container>::~stack(){}

template <typename T, typename Container>
const typename g3::stack<T, Container>::stack& g3::stack<T, Container>::operator=(const stack& rhv) {
	if (this != &rhv) {
		ob = rhv.ob;
	}

	return *this;
}

template <typename T, typename Container>
const typename g3::stack<T, Container>::stack& g3::stack<T, Container>::operator=(stack&& rhv) {
	if (this != rhv) {
		this->ob = std::move(rhv.ob);
	}
	return *this;
}

template <typename T, typename Container>
typename g3::stack<T, Container>::reference g3::stack<T, Container>::top() {
	this->ob.back();
}

template <typename T, typename Container>
typename g3::stack<T, Container>::const_reference g3::stack<T, Container>::top() const {
	this->ob.back();
}

template <typename T, typename Container>
bool g3::stack<T, Container>::empty() const {
	return this->ob.empty();
}

template <typename T, typename Container>
typename g3::stack<T, Container>::size_type g3::stack<T,Container>::size()const{
	return this->ob.size();
}

template <typename T, typename Container>
void g3::stack<T, Container>::push(const_reference val){
	this->ob.push_back(val);
}

template <typename T, typename Container>
void g3::stack<T, Container>::pop() {
	if (!this->ob.empty()) {
		this->ob.pop_back();
	}
}

template <typename T, typename Container>
bool g3::stack<T, Container>::operator==(const stack& other) {
	return this->ob == other.ob;
}

template <typename T, typename Container>
bool g3::stack<T, Container>::operator!=(const stack& other) {
	return this->ob != other.ob;
}

template <typename T, typename Container>
bool g3::stack<T, Container>::operator<(const stack& other) {
	return this->ob < other.ob;
}

template <typename T, typename Container>
bool g3::stack<T, Container>::operator<=(const stack& other) {
	return this->ob <= other.ob;
}

template <typename T, typename Container>
bool g3::stack<T, Container>::operator>(const stack& other) {
	return this->ob > other.ob;
}

template <typename T, typename Container>
bool g3::stack<T, Container>::operator>=(const stack& other) {
	return this->ob >= other.ob;
}



int main(){}

