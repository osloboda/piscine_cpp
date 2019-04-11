#ifndef ARRAY_H
# define ARRAY_H

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <exception>

template <typename T>

class Array
{
	private:
		T*				arr;
		unsigned int	n;
	public:
		Array<T>(void) : arr(NULL), n(0) {}
		~Array<T>(void){}
		Array<T>(unsigned int n): n(n)
		{
			arr = new T[n];
			return;
		}
		Array<T>(Array const &D)
		{
			*this = D;
			return;
		}
		Array<T> &operator=(Array const &D)
		{
			this->n = D.n;
			delete this->arr;
			this->arr = new T[this->n];
			for (int i = 0; i < this->n; i++)
				this->arr[i] = D.arr[i];
		}
		T&operator[](unsigned int n)
		{
			if (n >= this->n)
				throw std::exception();
			return (this->arr[n]);
		}
		unsigned int getSize() const
		{
			return (this->n);
		}
};

#endif
