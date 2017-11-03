#pragma once
#include <vector>

using namespace std;

template <class T>
class Lista
{
private:
	vector<T> listObjs;
public:
	Lista();
	~Lista();
	void addObj(T const pObj);
	
	// retorna o Obj na posição i
	T const objI(const int i);

	// retorna o numero de objetos
	const int numObjs();

	void deleteObj(T aObj);
	
};

template <class T>
Lista<T>::Lista()
{

}

template <class T>
Lista<T>::~Lista()
{
	listObjs.clear();
}

template <class T>
void Lista<T>::addObj(T const pObj)
{
	listObjs.push_back(pObj);
}

template <class T>
T const Lista<T>::objI(const int i)
{
	if (i < (int)listObjs.size() && i >= 0)
		return listObjs[i];
	else
		return NULL;
}

template <class T>
const int Lista<T>::numObjs()
{
	return listObjs.size();
}

template <class T>
void Lista<T>::deleteObj(T aObj)
{
	T aux;
	for (int i = 0; i < (int)listObjs.size(); i++)
		if (listObjs[i] == aObj)
		{
			aux = listObjs[i];
			listObjs.erase(listObjs.begin() + i);
			delete(aux);
		}

}