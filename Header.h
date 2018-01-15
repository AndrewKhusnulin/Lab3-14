
template <class T>
class CopiedObjects
{
	T data;
public:
	CopiedObjects(T data_) : data(data_) {}
	CopiedObjects(const CopiedObjects<T>& other);
	CopiedObjects<T> operator=(const CopiedObjects<T>& other);
	CopiedObjects<T> operator=(const CopiedObjects&& other) = delete;
};
template <class T>
class MovableObjects
{
	T data;
public:
	MovableObjects(T data_) : data(data_) {}
	MovableObjects(const MovableObjects&& other);
	MovableObjects<T> operator=(const MovableObjects<T>&& other);
	MovableObjects(const MovableObjects<T>& other) = delete;
	MovableObjects<T> operator=(const MovableObjects<T>& other) = delete;
};
template<class T>
MovableObjects<T>::MovableObjects(const MovableObjects<T> && other)
{
	if (this == &other)
		return;
	data = std::move(other.data);
}
template<class T>
MovableObjects<T> MovableObjects<T>::operator=(const MovableObjects<T> && other)
{
	if (this == &other)
		return *this;
	data = std::move(other.data);
}
template<class T>
CopiedObjects<T>::CopiedObjects(const CopiedObjects<T> & other)
{
	if (this == &other)
		return;
	data = other.data;
}
template<class T>
CopiedObjects<T> CopiedObjects<T>::operator=(const CopiedObjects<T> & other)
{
	if (this == &other)
		return *this;
	data = other.data;
}
// Реализация функции хеширования для пользовательского типа

template <class T>

struct CustomType
{
	T first;
	T second;
	CustomType(T first_, T second_)
	{
		first = first_;
		second = second_;
	}
};

// Специализация уже существующих сущностей (это является разрешенным в стандарте C++)

namespace std
{
	template <class T>
	struct hash<CustomType<T>>
	{
		size_t operator()(const CustomType<T>& obj) const
		{
			hash<T> h;
			return h(obj.first) ^ h(obj.second);
		}
	};
}
template <class T>

bool operator==(const CustomType<T>& obj1, const CustomType<T>& obj2)
{
	return obj1.first == obj2.first && obj1.second == obj2.second;
}