#pragma once
#include <exception>

template <typename T>
class DynamicArray
{
public:
	DynamicArray();
	~DynamicArray();

	void addItems(T item[], int size);
	void addItem(T item);
	bool removeItem(T item);
	void sortItems();
	T getItem(int index);
	bool contains(T item);
	T operator[](int index);
	int getLength() { return m_length; };
private:
	T* m_items;
	int m_length;

};

/// <summary>
/// Creats the base structor of this class 
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
inline DynamicArray<T>::DynamicArray()
{
	m_length = 0;
	m_items = nullptr;
}

/// <summary>
/// Dealocates lose information once this class is removed 
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
inline DynamicArray<T>::~DynamicArray()
{

}

template<typename T>
inline void DynamicArray<T>::addItems(T items[], int size)
{
	for (int i = 0; i < size; i++)
		addItem(items[i]);

}

/// <summary>
/// Handles the addition that is going to happen in the algorithum
/// </summary>
/// <typeparam name="T"> templete type</typeparam>
/// <param name="item">item being added to </param>
template<typename T>
inline void DynamicArray<T>::addItem(T item)
{
	//Temparay array that will hold our values
	T* temp = new T[getLength() + 1];

	//idarates through the list of items 
	for (int i = 0; i < getLength(); i++)

		//Sets temps current index to be items current index 
		temp[i] = m_items[i];

	//sets the index equal to be the new item
	temp[getLength()] = item;
	//Incramnet by one 
	m_length++;

	//deletes the pointer 
	delete[] m_items;
	//sets our array of items to be temp
	m_items = temp;


}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="item"></param>
/// <returns></returns>
template<typename T>
bool DynamicArray<T>::removeItem(T item)
{
	//Cheaks to 
	if (!item || getLength() <= 0)
		return false;

	int j = 0;
	bool removed = false;

	T* temp = new T[getLength() - 1];

	for (int i = 0; i < getLength(); i++)
	{
		if (m_items[i] != item || removed)
		{
			temp[j] = m_items[i];
			j++;
		}
		else
		{
			removed = true;
		}
	}

	if (removed)
	{
		delete[] m_items;
		m_items = temp;
		m_length--;
	}

	return removed;
}

template<typename T>
void DynamicArray<T>::sortItems()
{
	int j = 0;
	T key;

	for (int i = 1; i < getLength(); i++)
	{
		key = m_items[i];
		j = i - 1;
		while (j >= 0 && m_items[j] > key)
		{
			if (m_items[j] > key)
			{
				m_items[j + 1] = m_items[j];
				j--;
			}
		}
		m_items[j + 1] = key;
	}

}

template<typename T>
T DynamicArray<T>::getItem(int index)
{
	return m_items[index];
}

template<typename T>
bool DynamicArray<T>::contains(T item)
{
	//Iterate through actor array
	for (int i = 0; i < m_actorCount; i++)
	{
		//return the current actor if it matches the argument
		if (m_actors[i] == actor)
			return true;
	}

	return false;
}

template<typename T>
T DynamicArray<T>::operator[](int index)
{
	if (index > 0 || index < getLength()) {
		return m_items[index];
	}
	throw std::exception("Index was outside the bounds of the array.");
}

