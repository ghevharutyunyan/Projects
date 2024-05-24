#include "Header1.h"
#include <iostream>
/// <summary>
/// </summary>
/// <typeparam name="T"></typeparam>
/// <typeparam name="Allocator"></typeparam>
/// <param name="n"></param>
/// <returns></returns>
 
/// /////////////////////////////////////// CONST ITERATOR ////////////////////////////////////////
template <typename T, typename Allocator>
g3::vector<T, Allocator>::const_iterator::const_iterator(pointer ptr):ptr(ptr) {}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::const_iterator  g3::vector<T, Allocator>::const_iterator::operator+(size_type n) const {
	ptr + n;
	return *this;
}
template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::const_iterator  g3::vector<T, Allocator>::const_iterator::operator-(size_type n) const {
	ptr - n;
	return *this;
}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::const_iterator& g3::vector<T, Allocator>::const_iterator::operator++() {
	++ptr;
	return *this;
}
template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::const_iterator& g3::vector<T, Allocator>::const_iterator::operator--() {
	--ptr;
	return *this;
}
template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::const_iterator g3::vector<T, Allocator>::const_iterator::operator++(int) {
	const_iterator tmp = *this;
	++(*this);
	return tmp;
}
template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::const_iterator g3::vector<T, Allocator>::const_iterator::operator--(int) {
	const_iterator tmp = *this;
	--(*this);
	return tmp;
}
template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::const_reference  g3::vector<T, Allocator>::const_iterator::operator*() const {
	return *ptr;
}
template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::const_pointer  g3::vector<T, Allocator>::const_iterator::operator->() const {
	return ptr;
}
template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::const_reference  g3::vector<T, Allocator>::const_iterator::operator[](size_type pos) const {
	return *(this + pos);
}

template <typename T, typename Allocator>
bool g3::vector<T, Allocator>::const_iterator::operator==(const const_iterator& other) const {
	return (ptr == other.ptr);
}
template <typename T, typename Allocator>
bool g3::vector<T, Allocator>::const_iterator::operator!=(const const_iterator& other) const {
	return (ptr != other.ptr);
}
template <typename T, typename Allocator>
bool g3::vector<T, Allocator>::const_iterator::operator<(const const_iterator& other) const {
	return (ptr < other.ptr);
}
template <typename T, typename Allocator>
bool g3::vector<T, Allocator>::const_iterator::operator<=(const const_iterator& other) const {
	return (ptr <= other.ptr);
}
template <typename T, typename Allocator>
bool g3::vector<T, Allocator>::const_iterator::operator>(const const_iterator& other) const {
	return (ptr > other.ptr);
}
template <typename T, typename Allocator>
bool g3::vector<T, Allocator>::const_iterator::operator>=(const const_iterator& other) const {
	return (ptr >= other.ptr);
}



////////////////////////////////////// ITERATOR ///////////////////////////////////////

template <typename T, typename Allocator>
g3::vector<T, Allocator>::iterator::iterator(pointer ptr): const_iterator(ptr) {}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::iterator  g3::vector<T, Allocator>::iterator::operator+(size_type n) const {
	this->ptr += n;
	return *this;
	
}
template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::iterator  g3::vector<T, Allocator>::iterator::operator-(size_type n) const {
	this->ptr -= n;
	return *this;
}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::iterator& g3::vector<T, Allocator>::iterator::operator++() {
	++(this->ptr);
	return *this;
}
template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::iterator& g3::vector<T, Allocator>::iterator::operator--() {
	--(this->ptr);
	return *this;
}
template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::iterator g3::vector<T, Allocator>::iterator::operator++(int) {
	const_iterator tmp = *this;
	++(*this);
	return tmp;
}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::iterator g3::vector<T, Allocator>::iterator::operator--(int) {
	const_iterator tmp = *this;
	--(*this);
	return tmp;
}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::reference  g3::vector<T, Allocator>::iterator::operator*()  {
	return *(this->ptr);
}
template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::pointer  g3::vector<T, Allocator>::iterator::operator->() {
	return this->ptr;
}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::reference  g3::vector<T, Allocator>::iterator::operator[](size_type pos) const {
	return *(this + pos);
}




/////////////////////////////////////// CONST REVERSE ITERATOR //////////////////////////////////////////////////

template <typename T, typename Allocator>
g3::vector<T, Allocator>::const_reverse_iterator::const_reverse_iterator(pointer ptr) :ptr(ptr) {}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::const_reverse_iterator  g3::vector<T, Allocator>::const_reverse_iterator::operator+(size_type n) const {
	ptr -= n;
	return *this;
}
template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::const_reverse_iterator  g3::vector<T, Allocator>::const_reverse_iterator::operator-(size_type n) const {
	ptr += n;
	return *this;
}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::const_reverse_iterator& g3::vector<T, Allocator>::const_reverse_iterator::operator++() {
	--ptr;
	return *this;
}
template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::const_reverse_iterator& g3::vector<T, Allocator>::const_reverse_iterator::operator--() {
	++ptr;
	return *this;
}
template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::const_reverse_iterator g3::vector<T, Allocator>::const_reverse_iterator::operator++(int) {
	const_iterator tmp = *this;
	--(*this);
	return tmp;
}
template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::const_reverse_iterator g3::vector<T, Allocator>::const_reverse_iterator::operator--(int) {
	const_iterator tmp = *this;
	++(*this);
	return tmp;
}
template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::const_reference  g3::vector<T, Allocator>::const_reverse_iterator::operator*() const {
	return *ptr;
}
template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::const_pointer  g3::vector<T, Allocator>::const_reverse_iterator::operator->() const {
	return ptr;
}
template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::const_reference  g3::vector<T, Allocator>::const_reverse_iterator::operator[](size_type pos) const {
	return *(this - pos);
}

template <typename T, typename Allocator>
bool g3::vector<T, Allocator>::const_reverse_iterator::operator==(const const_reverse_iterator& other) const {
	return (ptr == other.ptr);
}
template <typename T, typename Allocator>
bool g3::vector<T, Allocator>::const_reverse_iterator::operator!=(const const_reverse_iterator& other) const {
	return (ptr != other.ptr);
}
template <typename T, typename Allocator>
bool g3::vector<T, Allocator>::const_reverse_iterator::operator<(const const_reverse_iterator& other) const {
	return (ptr > other.ptr);
}
template <typename T, typename Allocator>
bool g3::vector<T, Allocator>::const_reverse_iterator::operator<=(const const_reverse_iterator& other) const {
	return (ptr >= other.ptr);
}
template <typename T, typename Allocator>
bool g3::vector<T, Allocator>::const_reverse_iterator::operator>(const const_reverse_iterator& other) const {
	return (ptr < other.ptr);
}
template <typename T, typename Allocator>
bool g3::vector<T, Allocator>::const_reverse_iterator::operator>=(const const_reverse_iterator& other) const {
	return (ptr <= other.ptr);
}



/////////////////////////////////////////// REVERSE ITERATOR ///////////////////////////////////////////////////

template <typename T, typename Allocator>
g3::vector<T, Allocator>::reverse_iterator::reverse_iterator(pointer ptr): const_reverse_iterator(ptr) {}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::reverse_iterator  g3::vector<T, Allocator>::reverse_iterator::operator+(size_type n) const {
	this->ptr -= n;
	return *this;
}
template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::reverse_iterator  g3::vector<T, Allocator>::reverse_iterator::operator-(size_type n) const {
	this->ptr += n;
	return *this;
}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::reverse_iterator& g3::vector<T, Allocator>::reverse_iterator::operator++() {
	--(this->ptr);
	return *this;
}
template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::reverse_iterator& g3::vector<T, Allocator>::reverse_iterator::operator--() {
	++(this->ptr);
	return *this;
}
template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::reverse_iterator g3::vector<T, Allocator>::reverse_iterator::operator++(int) {
	const_iterator tmp = *this;
	--(*this);
	return tmp;
}
template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::reverse_iterator g3::vector<T, Allocator>::reverse_iterator::operator--(int) {
	const_iterator tmp = *this;
	++(*this);
	return tmp;
}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::reference  g3::vector<T, Allocator>::reverse_iterator::operator*() {
	return *(this->ptr);
}
template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::pointer  g3::vector<T, Allocator>::reverse_iterator::operator->() {
	return this->ptr;
}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::reference  g3::vector<T, Allocator>::reverse_iterator::operator[](size_type pos) const {
	return *(this - pos);
}





//////////////////////////////// VECTOR CONSTRUCTORS ////////////////////////////////////// 

template <typename T, typename Allocator>
g3::vector<T, Allocator>::vector():size_(0),capacity_(0),arr_(nullptr) {}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::vector(const vector& rhv) : size_(rhv.size_), capacity_(rhv.capacity_), arr_(nullptr) {
	allocator_type alloc = get_allocator();
	arr_=alloc.allocate(capacity_);
	for (int i=0; i<rhv.size_; ++i) {
		arr_[i] = rhv.arr_[i];
	}
}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::vector(vector&& rhv) : size_(rhv.size_), capacity_(rhv.capacity_),arr_(rhv.arr_){
	rhv.arr_ = nullptr;
	rhv.size_ = rhv.capacity_ = 0;
}


template <typename T, typename Allocator>
g3::vector<T, Allocator>::vector(std::initializer_list<value_type> init):size_(init.size()),capacity_(init.size()),arr_(nullptr){
	allocator_type alloc;
	if (capacity_ > 0) {
		arr_ = alloc.allocate(capacity_);
		size_type  i = 0;
		for (auto it = init.begin(); it != init.end(); ++it, ++i) {
			alloc.construct(arr_ + i, *it);
		};
	}
}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::vector(size_type size, const_reference val ):size_(size),capacity_(size) {
	allocator_type alloc;
	if (capacity_ > 0) {
		arr_ = alloc.allocate(capacity_);
		size_type i = 0;
		for (; i < size_; ++i) {
			alloc.construct(arr_ + i, val);
		}
	}
}

template <typename T,typename Allocator>
template <typename InputIt>
g3::vector<T, Allocator>::vector(InputIt first, InputIt last) {
	allocator_type alloc;

	InputIt it = first;
	while (it != last) {
		++size_;
		++it;
	}
	if (capacity_ > 0) {
		size_ = capacity_;
		arr_ = alloc.allocate(capacity_);

		size_type i = 0;
		for (InputIt it = first; it != last; ++it,++i) {
			alloc.construct(arr_ + i, *it);
		}
	}

}
template <typename T, typename Allocator>
g3::vector<T, Allocator>::~vector() {
	allocator_type alloc;
	size_type i = 0;

	for (size_type i = size_; i > 0; --i) {
		alloc.destroy(arr_ + i - 1);
	}
	alloc.deallocate(arr_, capacity_);
}









////////////////////////////////////// VECTOR FUNCTIONS ////////////////////////////////////////////////////




template <typename T, typename Allocator>
const typename g3::vector<T, Allocator>::vector&  g3::vector<T,Allocator>::vector::operator=(const vector& rhv){
	if (this == &rhv) {
		return *this;
	}
	clear();

	allocator_type alloc;

	if (capacity_ < size_) {
		capacity_ = rhv.size_;
			arr_ = alloc.allocate(capacity_);

	}
	for (size_type i = 0; i < rhv.size_; --i) {
		alloc.construct(arr_ + i, rhv.size_[i]);
	}
	size_ = rhv.size_;
	return *this;
	
}
template <typename T, typename Allocator>
const typename g3::vector<T, Allocator>::vector& g3::vector<T, Allocator>::vector::operator=(vector&& rhv) {
	this->arr_ = rhv.arr_;
	this->size_ = rhv.size_;
	this->capacity_ = rhv.capacity_;

	rhv.arr_ = nullptr;
	rhv.size_ = 0;
	rhv.capacity_ = 0;

	return *this;
}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::allocator_type  g3::vector<T, Allocator>::get_allocator() {
	return allocator_type();
}
template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::reference  g3::vector<T, Allocator>::at(size_type pos) {
	if (pos >= this->size_) {
		throw std::out_of_range();
	}
	return this->arr_[pos];
}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::const_reference  g3::vector<T, Allocator>::at(size_type pos) const {
	if (pos >= this->size_) {
		throw std::out_of_range();
	}
	return this->arr_[pos];
}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::reference  g3::vector<T, Allocator>::operator[](size_type pos){
	return this->arr_[pos];
}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::const_reference  g3::vector<T, Allocator>::operator[](size_type pos) const {
	return this->arr_[pos];
}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::reference  g3::vector<T, Allocator>::front() {
	if (this->size_ == 0) {
		throw std::out_of_range();
	}
	return this->arr_[0];
}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::const_reference  g3::vector<T, Allocator>::front()const {
	if (this->size_ == 0) {
		throw std::out_of_range();
	}
	return this->arr_[0];
}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::reference  g3::vector<T, Allocator>::back() {
	if (this->size_ == 0) {
		throw std::out_of_range();
	}
	return this->arr_[size_ - 1];
}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::const_reference  g3::vector<T, Allocator>::back() const {
	if (this->size_ == 0) {
		throw std::out_of_range();
	}
	return this->arr_[size_ - 1];
}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::iterator  g3::vector<T, Allocator>::begin() {
	return iterator(arr_);
}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::const_iterator  g3::vector<T, Allocator>::begin() const{
	return const_iterator(arr_);
}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::const_iterator  g3::vector<T, Allocator>::cbegin()const {
	return const_iterator(arr_);
}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::iterator  g3::vector<T, Allocator>::end() {
	return iterator(arr_+ size_);
}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::const_iterator  g3::vector<T, Allocator>::end() const {
	return const_iterator(arr_ + size_);
}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::const_iterator  g3::vector<T, Allocator>::cend() const {
	return const_iterator(arr_ + size_);
}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::iterator  g3::vector<T, Allocator>::rbegin()  {
	return reverse_iterator(arr_ + size_-1);
}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::const_iterator  g3::vector<T, Allocator>::rbegin()const {
	return const_reverse_iterator(arr_ + size_ - 1);
}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::const_iterator  g3::vector<T, Allocator>::crbegin()const {
	return const_reverse_iterator(arr_ + size_ - 1);
}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::iterator  g3::vector<T, Allocator>::rend() {
	return reverse_iterator(arr_ - 1);
}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::const_iterator  g3::vector<T, Allocator>::rend() const{
	return const_reverse_iterator(arr_ - 1);
}


template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::const_iterator  g3::vector<T, Allocator>::crend() const {
	return const_reverse_iterator(arr_ - 1);
}


template <typename T, typename Allocator>
bool g3::vector<T, Allocator>::empty() const {
	return size_ == 0;
}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::size_type  g3::vector<T, Allocator>::size() const {
	return size_;
}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::size_type  g3::vector<T, Allocator>::capacity() const {
	return capacity_;
}

template <typename T, typename Allocator>
void g3::vector<T, Allocator>::reserve(size_type new_cap) {
	if (new_cap > this->capacity_) {
		allocator_type alloc;
		
		pointer new_arr = alloc.allocate(new_cap);

		size_type i = 0;
		for (size_type i = 0; i < size_; ++i) {
			alloc.construct(new_arr + i, std::move(this->arr[i]));
			alloc.destroy(this->arr + i);
		}
		this->arr_ = new_arr;
		this->capacity_ = new_cap;
	}
}

template <typename T, typename Allocator>
void g3::vector<T, Allocator>::clear()noexcept {
	allocator_type alloc;
	for (size_type i = 0; i < size; ++i) {
		alloc.destroy(this->arr_ + i);
	}
	size_ = 0;
}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::iterator  g3::vector<T, Allocator>::insert(const_iterator pos, const_reference val) {
	if (size_ == capacity_) {
		reserve(capacity_ == 0 ? 1 : capacity_ * 2);
	}
	size_type index = pos - cbegin();
	iterator it =index + begin();

	for (auto current = end(); current != it; --current) {
		*current = *(current - 1);
	}

	*it = val;
	return it;
}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::iterator  g3::vector<T, Allocator>::insert(const_iterator pos, size_type count, const_reference val) {
	if (size_ + count > capacity_) {
		reserve(capacity_ == 0 ? 1 : capacity_ * 2);
	}
	size_type index = pos - cbegin();
	
	iterator it = index + begin();

	for (auto current = end(); current != it; --current) {
		*(current + count - 1) = std::move(*(current - 1));
	}
	for (size_type i = 0; i < count; ++i) {
		*(it + i) = val;
	}
	size_ += count;
	return it;
}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::iterator  g3::vector<T, Allocator>::insert(const_iterator pos, std::initializer_list<value_type> init) {
	size_type index = pos - cbegin();

	size_type count = init.size();

	if (size_ + count > capacity_) {
		reserve(capacity_ == 0 ? 1 : capacity_ * 2);
	}
	iterator it = index + begin();
	for (auto current = end(); current != it; --current) {
		*(current + count - 1) = std::move(*(current - 1));
	}
	auto init_it = init.begin();
	for (size_type i = 0; i < count; ++i) {
		*(it + i) = init_it;
		++init_it;
	}
	size_ += count;
	return it;

}

template <typename T, typename Allocator>
template <typename InputIt>
typename g3::vector<T, Allocator>::iterator  g3::vector<T, Allocator>::insert(const_iterator pos, InputIt first, InputIt last) {
	
	size_type index = pos - cbegin();

	size_type count = 0;
	for (auto it = first; it != last; ++it) {
		++count;
	}
	if (size_ + count > capacity_) {
		reserve(capacity_ == 0 ? 1 : capacity_ * 2);
	}
	iterator it = index + begin();
	for (auto current = end(); current != it; ++it) {
		*(current + count - 1) = std::move(*(current - 1));
	}

	auto input_it = first;
	while (input_it != last) {
		*it++ = *input_it++;
	}
	size_ += count;

	return it;

}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::iterator  g3::vector<T, Allocator>::erase(const_iterator pos) {
	size_type index = pos - cbegin();
	iterator it = index + begin();

	for (auto current = it + 1; current!= end(); ++current) {
		*(current - 1) = std::move(*current);
	}

	--size_;

	return it;
}

template <typename T, typename Allocator>
typename g3::vector<T, Allocator>::iterator  g3::vector<T, Allocator>::erase(const_iterator first, const_iterator last) {
	size_type index1 = first - cbegin();
	size_type index2 = last - cbegin();

	iterator it = index1 + begin();

	size_type count = index2 - index1;

	for (auto current = it + count; current != end(); ++current) {
		*it++ = std::move(*current);
	}

	size_ -= count;

	return it;
}

template <typename T, typename Allocator>
void g3::vector<T, Allocator>::push_back(const_reference val){
	if (size_ == capacity_) {
		reserve(capacity_ == 0 ? 1 : capacity_ * 2);
	}
	new(this->arr_ + this->size_)const_reference(val);
	++size_;

}

template <typename T, typename Allocator>
void g3::vector<T, Allocator>::pop_back() {
	if (size_ > 0) {
		--size_;
	}
}

template <typename T, typename Allocator>
void g3::vector<T, Allocator>::resize(size_type new_size, const_reference val) {
	if (new_size < size_) {
		size_ = new_size;
	}
	else if (new_size >size_) {
		if (new_size > capacity_) {
			reserve(new_size);
		}
	}

	for (size_type i = size_; i < new_size; ++i) {
		this->arr_[i] = val;
	}
	size_ = new_size;
}

template <typename T, typename Allocator>
bool g3::vector<T, Allocator>::operator==(const vector& other) const{
	if (this->size_ != other.size_) {
		return false;
	}
	for (size_type i = 0; i < size_; ++i) {
		if (this->arr_[i] != other.arr_[i]) {
			return false;
		}
	}

	return true;
}

template <typename T, typename Allocator>
bool g3::vector<T, Allocator>::operator!=(const vector& other) const {
	if (this->size_ == other.size_) {
		return false;
	}
	for (size_type i = 0; i < size_; ++i) {
		if (this->arr_[i] == other.arr_[i]) {
			return false;
		}
	}

	return true;
}

template <typename T, typename Allocator>
bool g3::vector<T, Allocator>::operator<(const vector& other) const {
	return compare(other) < 0;
}

template <typename T, typename Allocator>
bool g3::vector<T, Allocator>::operator<=(const vector& other) const {
	return compare(other) <= 0;
}

template <typename T, typename Allocator>
bool g3::vector<T, Allocator>::operator>(const vector& other) const {
	return compare(other) > 0;
}

template <typename T, typename Allocator>
bool g3::vector<T, Allocator>::operator>=(const vector& other) const {
	return compare(other) >= 0;
}

template <typename T, typename Allocator>
int g3::vector<T, Allocator>::compare(const vector& other)const {
	if(this->size_ > other.size_){
		return 1;
		 }
	if (this->size_ < other.size_) {
		return -1;
	}

	for (size_type i = 0; i < size_; ++i) {
		if (this->arr[i] < other.arr_[i])
			return -1;
		if (this->arr[i] > other.arr_[i])
			return 1;
	}
	return 0;
}



int main(){}