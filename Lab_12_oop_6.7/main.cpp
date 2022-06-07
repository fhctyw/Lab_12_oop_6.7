#include <iostream>
using namespace std;

template<class T>
class Predicate
{
public:
	virtual bool operator () (T x) = 0;
};

template<class T>
class Even : public Predicate<T>
{
public:
	virtual bool operator () (T x) override
	{
		return x % 2 == 0;
	}
};

template<class T>
class Positive : public Predicate<T>
{
public:
	virtual bool operator () (T x) override
	{
		return x > 0;
	}
};

template<class T> T accumulate(T* begin, T* end)
{
	T r(0);
	for (T *from = begin; from < end; from++)
	{
		r += *from;
	}
	return r;
}

template<class T> T accumulate_if(T* begin, T* end, Predicate<T> &p)
{
	T r(0);
	for (T* from = begin; from < end; from++)
	{
		if (p(*from))
			r += *from;
	}
	return r;
}

int main()
{
	int a[5] = { 1, -2, 0, 4, -5 };

	int r = accumulate(&a[0], &a[5]);
	cout << "accumulate() = " << r << endl;
	
	Predicate<int> *p = new Even<int>();
	r = accumulate_if(&a[0], &a[5], *p);
	cout << "accumulate_if() with Even predicate = " << r << endl;
	delete p;

	p = new Positive<int>();
	r = accumulate_if(&a[0], &a[5], *p);
	cout << "accumulate_if() with Positive predicate = " << r << endl;

	return 0;
}