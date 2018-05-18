#include <iostream>

template <typename T>

class vector_t
{
private:
	T * elements_;
	std::size_t size_;
	std::size_t capacity_;
public:
	vector_t()
	{
		elements_ = nullptr;
		size_ = 0;
		capacity_ = 0;
	}

	vector_t(vector_t<T> const & other)
	{
		size_ = other.size_;
		capacity_ = other.capacity_;
		elements_ = new T[capacity_];
		for (size_t i = 0; i < size_; i++)
		{
			elements_[i] = other.elements_[i];
		}
	}
	vector_t<T> & operator =(vector_t<T> const & other)
	{
		if (this != &other)
		{
			delete[] elements_;
			size_ = other.size_;
			capacity_ = other.capacity_;
			elements_ = new T[capacity_];
			for (size_t i = 0; i < size_; i++)
			{
				elements_[i] = other.elements_[i];
			}
		}
		return *this;
	}
	~vector_t() 
	{
		delete[] elements_;
	}

	std::size_t size() const
	{
		return size_;
	}

	std::size_t capacity() const
	{
		return capacity_;
	}

	void push_back(int value)
	{
		if (capacity_ == 0)
		{
			size_ = 1;
			capacity_ = 1;
			elements_ = new T[capacity_];
			elements_[0] = value;
		}
		else
		{
			T* mas;
			if (size_ == capacity_)
			{
				capacity_ = capacity_ * 2;
			}
			mas = new T[capacity_];
			for (size_t i = 0; i < size_; i++)
			{
				mas[i] = elements_[i];
			}
			delete[] elements_;
			elements_ = mas;
			elements_[size_] = value;
			size_++;
		}
	}
	void pop_back()
	{
		if (size_ == 0) return;
		size_--;
		if (size_ == 0 || size_ * 4 == capacity_)
		{
			T* mas;
			capacity_ = capacity_ / 2;
			mas = new T[capacity_]; //выделение памяти
			for (size_t i = 0; i < size_; i++)
			{
				mas[i] = elements_[i];
			}
			delete[] elements_;
			elements_ = mas;
		}
	}

	T & operator [](std::size_t index)
	{
		return elements_[index];
	}

	T operator [](std::size_t index) const
	{
		return elements_[index];
	}

	T at(std::size_t index)
	{
		if (index < size_) 
		{
			return (*this)[index];
		}
		else 
		{
			throw std::out_of_range("Invalid range");
		}
	}
	T & at(std::size_t index) const
	{
		if (index < size_) 
		{
			return (*this)[index];
		}
		else 
		{
			throw std::out_of_range("Invalid range");
		}
	}

	bool operator ==(vector_t const & other) const
	{
		bool success = false;
		if (size_ == other.size_ && capacity_ == other.capacity_) 
		{
			for (size_t i = 0; i < size_; i++) 
			{
				if (elements_[i] != other.elements_[i]) 
				{
					success = false;
					break;
				}
				else 
				{
					success = true;
				}
			}
		}
		if (success) 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
};

template <typename T>
bool operator !=(vector_t<T> const & lhs, vector_t<T> const & rhs)
{
	bool success = true;
	if (lhs == rhs) 
	{
		success = !success;
	}
	return success;
}
