#include <iostream>
#include "Header1.h"


/////////////////////////////////// QUEUE CTORS /////////////////////////////////////////////////////////

template <typename T, typename Container>
g3::queue<T,Container>::queue():ob(ob){}

template <typename T, typename Container>
g3::queue<T, Container>::queue(const queue& rhv) : ob(rhv.ob) {}

template <typename T, typename Container>
g3::queue<T, Container>::queue(queue&& rhv) : ob(std::move(rhv.ob)) {}

template <typename T, typename Container>
g3::queue<T, Container>::queue(std::initializer_list<value_type> init) : ob(init) {}

template <typename T, typename Container>
template <typename InputIt>
g3::queue<T, Container>::queue(InputIt first,InputIt last) : ob(first,last) {}

template <typename T, typename Container>
g3::queue<T, Container>::~queue(){}



/////////////////////////////////////// QUEUE FUNCTIONS /////////////////////////////////////////////////////////

template <typename T, typename Container>
const typename g3::queue<T, Container>::queue& g3::queue<T, Container>::operator=(const queue& rhv) {
	if (this != rhv) {
		this->ob = rhv.ob;
	}
}

template <typename T, typename Container>
const typename g3::queue<T, Container>::queue& g3::queue<T, Container>::operator=(queue&& rhv) {
	if (this != rhv) {
		this->ob = std::move(rhv.ob);
	}
}

template <typename T, typename Container>
typename g3::queue<T, Container>::reference g3::queue<T, Container>::front() {
	this->ob.front();
}

template <typename T, typename Container>
typename g3::queue<T, Container>::const_reference g3::queue<T, Container>::front()const {
	this->ob.front();
}

template <typename T, typename Container>
typename g3::queue<T, Container>::reference g3::queue<T, Container>::back() {
	this->ob.back();
}

template <typename T, typename Container>
typename g3::queue<T, Container>::const_reference g3::queue<T, Container>::back()const {
	this->ob.back();
}

template <typename T, typename Container>
bool g3::queue<T, Container>::empty()const {
	this->ob.empty;
}

template <typename T, typename Container>
typename g3::queue<T, Container>::size_type g3::queue<T, Container>::size()const {
	this->ob.size();
}

template <typename T, typename Container>
void g3::queue<T, Container>::push(const_reference val) {
	this->ob.push_back(val);
}

template <typename T, typename Container>
void g3::queue<T, Container>::pop() {
	this->ob.pop_front();
}

/////////////////////////////////////////////////// OPERATORS /////////////////////////////////////////////

template <typename T, typename Container>
bool g3::queue<T, Container>::operator==(const queue& other){
	return this->ob == rhv.ob;
}

template <typename T, typename Container>
bool g3::queue<T, Container>::operator!=(const queue& other) {
	return this->ob != rhv.ob;
}

template <typename T, typename Container>
bool g3::queue<T, Container>::operator<(const queue& other) {
	return this->ob < rhv.ob;
}

template <typename T, typename Container>
bool g3::queue<T, Container>::operator<=(const queue& other) {
	return this->ob <= rhv.ob;
}

template <typename T, typename Container>
bool g3::queue<T, Container>::operator>(const queue& other) {
	return this->ob > rhv.ob;
}

template <typename T, typename Container>
bool g3::queue<T, Container>::operator>=(const queue& other) {
	return this->ob >= rhv.ob;
}

int main(){}