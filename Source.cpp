#include<vector>
#include<list>
#include<map>
#include<set>
#include<unordered_map>
#include<deque>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<algorithm>
#include<conio.h>
#include"Header.h"
using namespace std;
class Vector
{
private:
	int _size;
	int _count = 0;
	clock_t _start;
	clock_t _end;
	double _result = 0.0;
	vector<int> vec;
	list<int> lst;
	deque<int> deq;
	multimap<int, long int> multmap;
	set<int> set;
	unordered_map<int, int> unorderedmap;
	vector<CopiedObjects<int>> vec_copy;
	vector<MovableObjects<int>> vec_move;
	deque<CopiedObjects<int>> d_copy;
	deque<MovableObjects<int>> d_move;
public:
	Vector(int sz) :_size(sz) {}
	void push_vector(int number)
	{

		if (number == 1)// Вычисляем сложность алгоритма доступа к элементу вектора
		{
			_count = 0;

			ofstream out("test1.txt", ios::out | ios::app | ios::binary);
			while (_count < 100)
			{

				for (register int i = 0; i < _size; ++i)
				{
					vec.push_back(i);
				}
				_start = clock();
				for (register int i = 0; i < _size; ++i)
				{
					vec.at(i);
				}
				_end = clock();

				_result += (static_cast<double>(_end - _start)) / CLOCKS_PER_SEC;

				_count++;
				vec.clear();
			}
			if (_count == 100)
			{
				cout << "Среднее значение времени при итерациях с размерностью " << _size << ", контейнер vector = " << _result / _count << endl;
				out << "Размер = " << _size << " " << "Среднее значение" << _result / _count << endl;
				system("pause");
			}
			out.close();
		}
		if (number == 2)// Вычисляем сложность добавления элемента в конец вектора
		{
			_count = 0;

			ofstream out("test2.txt", ios::out | ios::app | ios::binary);
			while (_count < 100)
			{
				_start = clock();
				for (register int i = 0; i < _size; ++i)
				{
					vec.push_back(i);
				}
				_end = clock();
				_result += (static_cast<double>(_end - _start)) / CLOCKS_PER_SEC;
				_count++;
				vec.clear();
			}
			if (_count == 100)
			{
				cout << "Среднее значение времени при итерациях с размерностью " << _size << ", контейнер vector = " << _result / _count << endl;
				out << "Размер = " << _size << " " << "Среднее значение" << _result / _count << endl;
				system("pause");
			}
			out.close();
		}
		if (number == 3)// Вычисляем сложность добавления элемента в начало вектора
		{
			_count = 0;

			ofstream out("test3.txt", ios::out | ios::app | ios::binary);
			while (_count < 100)
			{
				_start = clock();
				for (register int i = 0; i < _size; ++i)
				{
					vec.insert(vec.begin(), i);
				}
				_end = clock();
				_result += (static_cast<double>(_end - _start)) / CLOCKS_PER_SEC;
				_count++;
				vec.clear();
			}
			if (_count == 100)
			{
				cout << "Среднее значение времени при итерациях с размерностью " << _size << ", контейнер vector = " << _result / _count << endl;
				out << "Размер = " << _size << " " << "Среднее значение " << _result / _count << endl;
				system("pause");
			}
			out.close();
		}
		if (number == 4)// Вычисляем сложность добавления элемента в конец вектора (перемещаемые объекты)
		{
			_count = 0;

			ofstream out("test4.txt", ios::out | ios::app | ios::binary);
			while (_count < 1000)
			{
				for (register int i = 0; i < _size; ++i)
				{
					MovableObjects<int> movable_object(i);
					_start = clock();
					for (register int i = 0; i < _size; ++i)
					{
						vec_move.push_back(std::move(movable_object));
					}
					_end = clock();
					_result += (static_cast<double>(_end - _start)) / CLOCKS_PER_SEC;
					_count++;
					vec.clear();
				}
			}
			if (_count == 1000)
			{
				cout << "Среднее значение времени при итерациях с размерностью " << _size << ", контейнер vector = " << _result / _count << endl;
				out << "Размер = " << _size << " " << "Среднее значение " << _result / _count << endl;
				system("pause");
			}
			out.close();
		}
		if (number == 5)// Вычисляем сложность добавления элемента в конец вектора (копируемые объекты)
		{
			_count = 0;
			ofstream out("test5.txt", ios::out | ios::app | ios::binary);
			while (_count < 1000)
			{
				for (register int i = 0; i < _size; ++i)
				{
					CopiedObjects<int> copied_object(i);
					_start = clock();
					for (register int i = 0; i < _size; ++i)
					{
						vec_copy.push_back(std::move(copied_object));
					}
					_end = clock();
					_result += (static_cast<double>(_end - _start)) / CLOCKS_PER_SEC;
					_count++;
					vec.clear();
				}
			}
			if (_count == 1000)
			{
				cout << "Среднее значение времени при итерациях с размерностью " << _size << ", контейнер vector = " << _result / _count << endl;
				out << "Размер = " << _size << " " << "Среднее значение " << _result / _count << endl;
				system("pause");
			}
			out.close();
		}
		if (number == 6)// Вычисляем динамику изменения capacity при добавлении элементов в вектор
		{
			_count = 0;

			ofstream out("test6.txt", ios::out | ios::app | ios::binary);
			while (_count < 100)
			{
				for (register int i = 0; i < _size; ++i)
				{
					vec.push_back(i);
				}
				_start = clock();
				for (register int i = 0; i < _size; ++i)
				{
					vec.capacity();
				}
				_end = clock();
				_result += (static_cast<double>(_end - _start)) / CLOCKS_PER_SEC;
				_count++;
				vec.clear();
			}
			if (_count == 100)
			{
				cout << "Среднее значение времени при итерациях с размерностью " << _size << ", контейнер vector = " << _result / _count << endl;
				out << "Размер = " << _size << " " << "Среднее значение" << _result / _count << endl;
				system("pause");
			}
			out.close();
		}
		if (number == 7)// Вычисляем динамику изменения capacity при удалении элементов из вектора
		{
			_count = 0;

			ofstream out("test7.txt", ios::out | ios::app | ios::binary);
			while (_count < 100)
			{
				for (register int i = 0; i < _size; ++i)
				{
					vec.push_back(i);
				}
				for (register int i = 0; i < _size; ++i)
				{
					vec.pop_back();
				}
				_start = clock();
				for (register int i = 0; i < _size; ++i)
				{
					vec.capacity();
				}
				_end = clock();
				_result += (static_cast<double>(_end - _start)) / CLOCKS_PER_SEC;
				_count++;
				vec.clear();
			}
			if (_count == 100)
			{
				cout << "Среднее значение времени при итерациях с размерностью " << _size << ", контейнер vector = " << _result / _count << endl;
				out << "Размер = " << _size << " " << "Среднее значение" << _result / _count << endl;
				system("pause");
			}
			out.close();
		}
	}
	void push_list(int number)
	{
		if (number == 1)
		{
			_count = 0;

			ofstream out("test8.txt", ios::out | ios::app | ios::binary);
			while (_count < 100)
			{

				_start = clock();
				for (register int i = 0; i < _size; ++i)
				{
					lst.push_back(i);
				}
				_end = clock();


				_result += (static_cast<double>(_end - _start)) / CLOCKS_PER_SEC;

				_count++;
				lst.clear();

			}
			if (_count == 100)
			{
				cout << "Среднее значение времени при итерациях с размерностью " << _size << ", контейнер list = " << _result / _count << endl;
				out << "Размер = " << _size << " " << "Среднее значение " << _result / _count << endl;
				system("pause");
			}
			out.close();
		}
		if (number == 2)
		{
			_count = 0;
			ofstream out("test9.txt", ios::out | ios::app | ios::binary);
			while (_count < 100)
			{


				for (register int i = 0; i < _size; ++i)
				{
					lst.push_back(i);
				}
				list<int>::iterator p = lst.begin();
				p++;
				_start = clock();
				lst.erase(p);
				_end = clock();


				_result += (static_cast<double>(_end - _start)) / CLOCKS_PER_SEC;

				_count++;
				lst.clear();

			}
			if (_count == 100)
			{
				cout << "Среднее значение времени при итерациях с размерностью " << _size << ", контейнер list = " << _result / _count << endl;
				out << "Размер = " << _size << " " << "Среднее значение " << _result / _count << endl;
				system("pause");
			}
			out.close();
		}
		if (number == 3)
		{
			_count = 0;

			ofstream out("test10.txt", ios::out | ios::app | ios::binary);
			while (_count < 100)
			{


				for (register int i = 0; i < _size; ++i)
				{
					lst.push_back(i);
				}

				_start = clock();
				find(vec.begin(), vec.end(), 9);
				_end = clock();


				_result += (static_cast<double>(_end - _start)) / CLOCKS_PER_SEC;

				_count++;
				lst.clear();

			}
			if (_count == 100)
			{
				cout << "Среднее значение времени при итерациях с размерностью " << _size << ", контейнер list = " << _result / _count << endl;
				out << "Размер = " << _size << " " << "Среднее значение " << _result / _count << endl;
				system("pause");
			}
			out.close();
		}
	}
	void push_deque(int number)
	{


		if (number == 1)// Вычисляем сложность алгоритма доступа к элементу вектора
		{
			_count = 0;

			ofstream out("test11.txt", ios::out | ios::app | ios::binary);
			while (_count < 100)
			{

				for (register int i = 0; i < _size; ++i)
				{
					deq.push_back(i);
				}
				_start = clock();
				for (register int i = 0; i < _size; ++i)
				{
					deq.at(i);
				}
				_end = clock();

				_result += (static_cast<double>(_end - _start)) / CLOCKS_PER_SEC;

				_count++;
				deq.clear();
			}
			if (_count == 100)
			{
				cout << "Среднее значение времени при итерациях с размерностью " << _size << ", контейнер deque = " << _result / _count << endl;
				out << "Размер = " << _size << " " << "Среднее значение" << _result / _count << endl;
				system("pause");
			}
			out.close();
		}
		if (number == 2)// Вычисляем сложность добавления элемента в конец вектора
		{
			_count = 0;

			ofstream out("test12.txt", ios::out | ios::app | ios::binary);
			while (_count < 100)
			{
				_start = clock();
				for (register int i = 0; i < _size; ++i)
				{
					deq.push_back(i);
				}
				_end = clock();
				_result += (static_cast<double>(_end - _start)) / CLOCKS_PER_SEC;
				_count++;
				deq.clear();
			}
			if (_count == 100)
			{
				cout << "Среднее значение времени при итерациях с размерностью " << _size << ", контейнер deque = " << _result / _count << endl;
				out << "Размер = " << _size << " " << "Среднее значение" << _result / _count << endl;
				system("pause");
			}
			out.close();
		}
		if (number == 3)// Вычисляем сложность добавления элемента в начало вектора
		{
			_count = 0;

			ofstream out("test13.txt", ios::out | ios::app | ios::binary);
			while (_count < 100)
			{
				_start = clock();
				for (register int i = 0; i < _size; ++i)
				{
					deq.insert(deq.begin(), i);
				}
				_end = clock();
				_result += (static_cast<double>(_end - _start)) / CLOCKS_PER_SEC;
				_count++;
				vec.clear();
			}
			if (_count == 100)
			{
				cout << "Среднее значение времени при итерациях с размерностью " << _size << ", контейнер deque = " << _result / _count << endl;
				out << "Размер = " << _size << " " << "Среднее значение " << _result / _count << endl;
				system("pause");
			}
			out.close();
		}
		if (number == 4)// Вычисляем сложность добавления элемента в конец вектора (перемещаемые объекты)
		{
			_count = 0;

			ofstream out("test14.txt", ios::out | ios::app | ios::binary);
			while (_count < 1000)
			{
				for (register int i = 0; i < _size; ++i)
				{
					MovableObjects<int> movable_object(i);
					_start = clock();
					for (register int i = 0; i < _size; ++i)
					{
						d_move.push_back(std::move(movable_object));
					}
					_end = clock();
					_result += (static_cast<double>(_end - _start)) / CLOCKS_PER_SEC;
					_count++;
					deq.clear();
				}
			}
			if (_count == 1000)
			{
				cout << "Среднее значение времени при итерациях с размерностью " << _size << ", контейнер deque = " << _result / _count << endl;
				out << "Размер = " << _size << " " << "Среднее значение " << _result / _count << endl;
				system("pause");
			}
			out.close();
		}
		if (number == 5)// Вычисляем сложность добавления элемента в конец вектора (копируемые объекты)
		{
			_count = 0;
			ofstream out("test15.txt", ios::out | ios::app | ios::binary);
			while (_count < 1000)
			{
				for (register int i = 0; i < _size; ++i)
				{
					CopiedObjects<int> copied_object(i);
					_start = clock();
					for (register int i = 0; i < _size; ++i)
					{
						d_copy.push_back(std::move(copied_object));
					}
					_end = clock();
					_result += (static_cast<double>(_end - _start)) / CLOCKS_PER_SEC;
					_count++;
					vec.clear();
				}
			}
			if (_count == 1000)
			{
				cout << "Среднее значение времени при итерациях с размерностью " << _size << ", контейнер deque = " << _result / _count << endl;
				out << "Размер = " << _size << " " << "Среднее значение " << _result / _count << endl;
				system("pause");
			}
			out.close();
		}
	}
	void push_set(int number)
	{
		if (number == 1)// Вычисляем время работы поиска при использовании внешней функции из <algorithm> для set
		{
			_count = 0;
			ofstream out("test16.txt", ios::out | ios::app | ios::binary);
			while (_count < 100)
			{
				for (register int i = 0; i < _size; ++i)
				{
					set.insert(i);
				}
				_start = clock();
				for (register int i = 0; i < _size; ++i)
				{
					find(set.begin(), set.end(),i);
				}
				_end = clock();

				_result += (static_cast<double>(_end - _start)) / CLOCKS_PER_SEC;

				_count++;
				set.clear();

			}
			if (_count == 100)
			{
				cout << "Среднее значение времени при итерациях с размерностью " << _size << ", контейнер set = " << _result / _count << endl;
				out << "Размер = " << _size << " " << "Среднее значение " << _result / _count << endl;
				system("pause");
			}
			out.close();
		}
		if (number == 2)// Вычисляем время работы поиска при использовании метода класса
		{
			_count = 0;

			ofstream out("test17.txt", ios::out | ios::app | ios::binary);
			while (_count < 100)
			{
				for (register int i = 0; i < _size; ++i)
				{
					set.insert(i);
				}
				_start = clock();
				for (register int i = 0; i < _size; ++i)
				{
					set.find(i);
				}
				_end = clock();

				_result += (static_cast<double>(_end - _start)) / CLOCKS_PER_SEC;

				_count++;
				set.clear();

			}
			if (_count == 100)
			{
				cout << "Среднее значение времени при итерациях с размерностью " << _size << ", контейнер set = " << _result / _count << endl;
				out << "Размер = " << _size << " " << "Среднее значение " << _result / _count << endl;
				system("pause");
			}
			out.close();
		}
		
	}

	void push_multimap(int number)
	{
		if (number == 1)// Вычисляем изменение времени добавления элемента с одним и тем же ключом
		{
			_count = 0;
			ofstream out("test18.txt", ios::out | ios::app | ios::binary);
			while (_count < 100)
			{
				_start = clock();
				for (register int i = 0; i < _size; ++i)
				{
					multmap.insert(pair<unsigned int, unsigned int>(i, _size));
				}
				_end = clock();

				_result += (static_cast<double>(_end - _start)) / CLOCKS_PER_SEC;

				_count++;
				multmap.clear();

			}
			if (_count == 100)
			{
				cout << "Среднее значение времени при итерациях с размерностью " << _size << ", контейнер multimap = " << _result / _count << endl;
				out << "Размер = " << _size << " " << "Среднее значение " << _result / _count << endl;
				system("pause");
			}
			out.close();
		}
	};
	void push_unordered_map(int number)
	{
		if (number == 1)// Отслеживание попадания элементов в конкретный bucket
		{
			
			int count_of_buckets;
			_count = 0;
			ofstream out("test19.txt", ios::out | ios::app | ios::binary);
			while (_count < 1)
			{
				for (register int i = 0; i < _size; ++i)
				{
					unorderedmap.insert(pair<int, int>(i, i));
					auto it = unorderedmap.begin();
					_start = clock();
					for (unsigned int step = { 0 }; step != i; ++step)
					{
						++it;
					}
					count_of_buckets = unorderedmap.bucket_count();
					int size = 0;
					for (unsigned int j = { 0 }; j < count_of_buckets; ++j)
					{
						size += unorderedmap.bucket_size(j);
					}

						_end = clock();
				}
				_result += (static_cast<double>(_end - _start)) / CLOCKS_PER_SEC;

				_count++;
				unorderedmap.clear();

			}
			if (_count == 1)
			{
				cout << "Среднее значение времени при итерациях с размерностью " << _size << ", контейнер unordered_map = " << _result / _count << endl;
				out << "Размер = " << _size << " " << "Среднее значение " << _result / _count << endl;
				system("pause");
			}
			out.close();
		}
		if (number == 2)// Оценка сложности поиска для unordered_map
		{
			_count = 0;

			ofstream out("test20.txt", ios::out | ios::app | ios::binary);
			while (_count < 500)
			{
				for (register int i = 0; i < _size; ++i)
				{
					unorderedmap.insert(pair<int, long int>(i, i+5));
				}

				_start = clock();
				unorderedmap.find(5);
				_end = clock();

				_result += (static_cast<double>(_end - _start)) / CLOCKS_PER_SEC;

				_count++;
				unorderedmap.clear();
			}
			if (_count == 500)
			{
				cout << "Среднее значение времени при итерациях с размерностью " << _size << ", контейнер unordered_map = " << _result / _count << endl;
				out << "Размер = " << _size << " " << "Среднее значение " << _result / _count << endl;
				system("pause");
			}
			out.close();
		}
		if (number == 3)// Оценка сложности поиска в случае "плохой" функции хэширования для пользовательского типа
		{
			_count = 0;
			unordered_map<CustomType<int>, int> unorderedmap_custom;
			ofstream out("test21.txt", ios::out | ios::ate | ios::binary);
			while (_count < 10)
			{
				for (unsigned int i = { 0 }; i < _size; ++i)
				{
					CustomType<int> custom_elem(i, i);
					unorderedmap_custom.insert(std::pair<CustomType<int>, int>(custom_elem, i));
				}
				CustomType<int> element(10, 10);
					for (unsigned int i = { 0 }; i < _size; ++i)
					{
					unorderedmap_custom.find(element);
					_end = clock();
					}

				_result += (static_cast<double>(_end - _start)) / CLOCKS_PER_SEC;

				_count++;
				multmap.clear();

			}
			if (_count == 10)
			{
				cout << "Среднее значение времени при итерациях с размерностью " << _size << ", контейнер unordered_map =" << _result / _count << endl;
				out << "Размер=" << _size << " " << "Среднее значение" << _result / _count << endl;
				system("pause");
			}
			out.close();
		}
	}
};
int main()
{
	setlocale(0, "rus");
	auto size_of_massive = 0;
	auto number = 0, size = 10;
	while (1)
	{
		cout << "Введите 1, если хотите узнать сложность vector для содержимого в контейнере " << endl;
		cout << "Введите 2, если хотите узнать сложность list для содержимого в контейнере " << endl;
		cout << "Введите 3, если хотите узнать сложность deque для содержимого в контейнере " << endl;
		cout << "Введите 4, если хотите узнать сложность set для содержимого в контейнере " << endl;
		cout << "Введите 5, если хотите узнать сложность multimap для содержимого в контейнере " << endl;
		cout << "Введите 6, если хотите узнать сложность unordered_map для содержимого в контейнере " << endl;
		cout << "Введите 0, если хотите выйти" << endl;
		cin >> number;
		//char ch;
		switch (number)
		{
		case 1:
		{
			cout << "(Для vector) Введите 1 Вычисляем сложность алгоритма доступа к элементу вектора, 2 -  Вычисляем сложность добавления элемента в конец вектора, 3 -  Вычисляем сложность добавления элемента в начало вектора, 4 -  Вычисляем сложность добавления элемента в конец вектора (перемещаемые объекты), 5 -  Вычисляем сложность добавления элемента в конец вектора (копируемые объекты), 6 - Вычисляем динамику изменения capacity при добавлении элементов в вектор, 7 - Вычисляем динамику изменения capacity при удалении элементов в вектор" << endl;
			cin >> number;
			Vector vec(10);
			vec.push_vector(number);

			Vector vec1(100);
			vec1.push_vector(number);
			/*cin >> ch;
			if ((ch = 'N') || (ch = 'n'))
				break;*/
			Vector vec2(1000);
			vec2.push_vector(number);
			Vector vec3(10000);
			vec3.push_vector(number);
			Vector vec4(50000);
			vec4.push_vector(number);
			Vector vec5(100000);
			vec5.push_vector(number);
			Vector vec6(500000);
			vec6.push_vector(number);
			_getch();
			break;
		}
		case 2:
		{

			cout << "(Для list) Введите 1 для добавления элемента в контейнер, 2 -  Вычисляем сложность добавления элемента в конец вектора, 3 -  Вычисляем сложность добавления элемента в начало вектора, 4 -  Вычисляем сложность добавления элемента в конец вектора (перемещаемые объекты), 5 -  Вычисляем сложность добавления элемента в конец вектора (копируемые объекты)" << endl;
			cin >> number;
			Vector vec(10);
			vec.push_list(number);
			Vector vec1(100);
			vec1.push_list(number);
			Vector vec2(1000);
			vec2.push_list(number);
			Vector vec3(10000);
			vec3.push_list(number);
			Vector vec4(50000);
			vec4.push_list(number);
			Vector vec5(100000);
			vec5.push_list(number);
			Vector vec6(500000);
			vec6.push_list(number);
			_getch();
			break;
		}
		case 3:
		{

			cout << "(Для deque) Введите 1 Вычисляем сложность алгоритма доступа к элементу вектора, 2 - для удаления элемента в контейнере, 3 - для поиска элемента" << endl;
			cin >> number;
			Vector vec(10);
			vec.push_deque(number);
			Vector vec1(100);
			vec1.push_deque(number);
			Vector vec2(1000);
			vec2.push_deque(number);
			Vector vec3(10000);
			vec3.push_deque(number);
			Vector vec4(50000);
			vec4.push_deque(number);
			Vector vec5(100000);
			vec5.push_deque(number);
			Vector vec6(500000);
			vec6.push_deque(number);
			_getch();
			break;
		}
		case 4:
		{

			cout << "(Для set) Введите 1  Вычисляем время работы поиска при использовании внешней функции из <algorithm> для set, 2 - Вычисляем время работы поиска при использовании метода класса" << endl;
			cin >> number;
			Vector vec(10);
			vec.push_set(number);
			Vector vec1(100);
			vec1.push_set(number);
			Vector vec2(1000);
			vec2.push_set(number);
			Vector vec3(10000);
			vec3.push_set(number);
			Vector vec4(50000);
			vec4.push_set(number);
			Vector vec5(100000);
			vec5.push_set(number);
			Vector vec6(500000);
			vec6.push_set(number);
			_getch();
			break;
		}
		case 5:
		{

			cout << "(Для multimap) Введите 1 Вычисляем изменение времени добавления элемента с одним и тем же ключом" << endl;
			cin >> number;
			Vector vec(10);
			vec.push_multimap(number);
			Vector vec1(100);
			vec1.push_multimap(number);
			Vector vec2(1000);
			vec2.push_multimap(number);
			Vector vec3(10000);
			vec3.push_multimap(number);
			Vector vec4(50000);
			vec4.push_multimap(number);
			Vector vec5(100000);
			vec5.push_multimap(number);
			Vector vec6(500000);
			vec6.push_multimap(number);
			_getch();
			break;
		}
		case 6:
		{

			cout << "(Для unordered_map) Введите 1 Отслеживание попадания элементов в конкретный bucket, 2 -  Оценка сложности поиска для unordered_map, 3 - Оценка сложности поиска в случае 'плохой' функции хэширования для пользовательского типа" << endl;
			cin >> number;
			Vector vec(10);
			vec.push_unordered_map(number);
			Vector vec1(100);
			vec1.push_unordered_map(number);
			Vector vec2(1000);
			vec2.push_unordered_map(number);
			Vector vec3(10000);
			vec3.push_unordered_map(number);
			Vector vec4(50000);
			vec4.push_unordered_map(number);
			Vector vec5(100000);
			vec5.push_unordered_map(number);
			Vector vec6(500000);
			vec6.push_unordered_map(number);
			_getch();
			break;
		}
		case 0:
		{
			return 0;
			break;
		}
		}
	}

}

