#ifndef guard_vec
#define guard_vec

#include <memory>

template <typename T>
class Vec 
{
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;
	typedef T& reference;
	typedef const T& const_reference;
	typedef std::ptrdiff_t difference_type;

	Vec() { create(); }
	explicit Vec(size_type n, const T& t = T()) { create(n, t); }
	~Vec() { uncreate(); }
	size_type size() const { return avail - data; }
	T&  operator[](size_type i) { return data[i]; }
	const T& operator[](size_type i) const { return data[i]; }
	iterator begin() { return data; }
	iterator const begin() const { return data; }
	iterator end() { return avail; }
	iterator const end() const { return avail; }
	Vec(const Vec& v) { create(v.begin(), v.end()); }
	Vec& operator= (const Vec&);
	void push_back(const T& t) {
		if (avail == limit)
			grow();
		unchecked_append(t);
	}
	bool empty() const { return data; }
	void clear() { uncreate(); }

private:
	T* data;
	T* limit;
	T* avail;
	std::allocator<T> alloc;
	void create() { 
		data = avail = limit = 0;
	}
	void create(size_type n, const T& t) {
		data = alloc.allocate(n);
		limit = avail = data + n;
		std::uninitialized_fill(data, limit, t);
	}
	void create(const_iterator b, const_iterator e) {
		data = alloc.allocate(e - b);
		limit = avail = std::uninitialized_copy(b, e, data);
	}
	void uncreate();
	void grow();
	void unchecked_append(const T& t) { alloc.construct(avail++, t); }

};


template <class T>
Vec<T>& Vec<T>::operator=(const Vec& v) 
{
	if (this != &v)
	{
		uncreate();
		create(v.begin(), v.end());
	}
	return *this; 
}
template <class T>
void Vec<T>::uncreate() {
	if (data) {
		iterator it = avail;
		while (it != data)
			alloc.destroy(--it);
		alloc.deallocate(data, limit - data);
	}
	data = avail = limit = 0;
}
template <class T>
void Vec<T>::grow() {
	size_type nlen = data ? 2 * (end() - begin()) : std::ptrdiff_t(1);
	iterator ndata = alloc.allocate(nlen);
	iterator navail = std::uninitialized_copy(data, avail, ndata);

	uncreate();

	data = ndata;
	avail = navail;
	limit = ndata + nlen;
}

#endif