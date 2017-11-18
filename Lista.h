#pragma once
#include <vector>

using namespace std;

template <class T>
class Lista
{
private:
	vector<T> listObjs;
	int tam;
public:
	Lista();
	~Lista();
	void addObj(T const pObj);
	
	// retorna o Obj na posição i
	T const objI(const int i);

	// retorna o numero de objetos
	const int numObjs();
	
	T const retirarObj(T const aObj);
};

template <class T>
Lista<T>::Lista()
{
	tam = 0;
}

template <class T>
Lista<T>::~Lista()
{
	listObjs.clear();
	tam = 0;
}

template <class T>
void Lista<T>::addObj(T const pObj)
{
	listObjs.push_back(pObj);
	tam++;
}

template <class T>
T const Lista<T>::objI(const int i)
{
	if (i < tam && i >= 0)
		return listObjs[i];
	else
		return nullptr;
}

template <class T>
const int Lista<T>::numObjs()
{
	return tam;
}

template <class T>
T const Lista<T>::retirarObj(T const aObj)
{
	for (int i = 0; i < (int)listObjs.size(); i++)
	{
		if (listObjs[i] == aObj)
		{
			T aux = listObjs[i];
			tam--;
			listObjs.erase(listObjs.begin() + i);
			return aux;
		}
	}
	return nullptr;
}