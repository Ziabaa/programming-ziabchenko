#ifndef __LIST_H__
#define __LIST_H__


#include <iostream>
#include <fstream>
#include <algorithm>
using std::cout;
using std::endl;
using std::sort;
using std::ofstream;
using std::ifstream;
using std::string;



template<class T>
struct Element{
	T data; //значення поточного елемента
	Element<T>* next; //наступний елемент
	Element<T>* prev; //попередній елемент
};

template<class T>
class List{
	Element<T>* begin; //початок списку
	Element<T>* end; //кінець спиксу
	size_t count; //кількість елементів

	Element<T>* Move(size_t position){
	    Element<T>* t = begin;
	    for (size_t i = 0; i < position; ++i) {
		t = t->next;
	    }
	    return t;
	} //бере показчик на елемент за позицією
public:
    /**
     * значення елемента по позиции
     */
    T getElement(size_t pos){
	    Element<T>* t = Move(pos);
	    return t->data;
    }
    /**
     * виводить до консолі
     */
    void print() const{
	Element<T>* t = begin;

	for(size_t i = 0; i < count; i++){
	    cout << t->data << "    ";
	    t = t->next;

	}
	cout << endl;
    }
    /**
     * індекс потрібного елемента
     */
    size_t getIndex(T val){
	Element<T>* t = begin;
	size_t pos = 0;
	for(size_t i = 0; i < count; i++){
	    if(val == t->data){
		return pos;
	    }else{
		pos++;
	    }
	    t = t->next;
	}
	return pos;
    }
    /**
     * додає до кінця списку
     */
    void addToEnd(T pole)
    {
	Element<T> *t = new Element<T>;
	t->next = nullptr;
	t->prev = end;
	t->data = pole;

	if (end != nullptr) {
	    end->next = t;
	}

	if (count == 0) {
	    begin = end = t;
	} else {
	    end = t;
	}
	count++;
    }
    /**
     * видяляє по позиції
     */
    void delElementPos(size_t pos){
	if(count == 0 or pos > count){
	    return ;
	}
	Element<T>* posElement = Move(pos);

	Element<T>* prevElement = posElement->prev;
	Element<T>* nextElement = posElement->next;


	if(count > 1 and prevElement != nullptr){
	    prevElement->next = nextElement;
	}
	if(count > 1 and nextElement != nullptr){
	    nextElement->prev = prevElement;
	}
	if(pos == 0){
	    begin = nextElement;
	}
	if(pos == count-1){
	    begin = prevElement;
	}

	delete posElement;
	count--;
    }
    /**
     * знаходить позицію мінімального елементу
     */
    size_t minElement() const{
	if (count== 0) return 0;
	Element<T>* t = begin;
	size_t position;

	for (size_t i = 0; i < count - 1; ++i) {
	    if((t->data < (t->next)->data)){
		t = t->next;
		position = i;
	    }else {
		t = t->next;
	    }
	}
	return position;
    }
    /**
     * сортує клас-список
     */
    void sort(){
	for (size_t i = count -1; i > 0; --i) {
	    Element<T>* m = Move(i);
	    for (size_t y = 0; y < i; ++y) {
		Element<T>* x = Move(y);
		if(m->data < x->data){
			std::swap(m->data, x->data);
		}

	    }

//	    cout << "!!!!!min!!!!!" << Move(min)->data << endl;
//	    cout << "!!!!!i!!!!!" << Move(i)->data << endl << endl;
//	    std::swap(Move(i)->data, Move(min)->data);
//	    min = minElement(i);

	}
    }

};

#endif