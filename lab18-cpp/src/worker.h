#ifndef __WORKER_H__
#define __WORKER_H__

#include "colleague.h"

#include <cstring>
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::cerr;
using std::ofstream;
using std::ifstream;


class Workers{
	Colleague** colleagues;
	size_t size;
public:

    void print() const;
    void addElement(size_t pos, const Colleague * colleague);
    void delElement(size_t pos);
    void writeToFile(string filename) const;
    void sort(string fieldName);
    size_t findCountColleagueInCompany_WithoutInsurance(string company) const;

    Workers(): colleagues(nullptr), size(0){   }
    Workers(const Workers& copy): size(copy.size) {
	    new Colleague*[size];
	    for (size_t i = 0; i < size; ++i) {
		    colleagues[i] = new Colleague(*(copy.colleagues[i]));
	    }
    }
    ~Workers(){
	    for (size_t i = 0; i < size; ++i) {
		    delete colleagues[i];
	    }
	    if (size > 0){
		    delete[] colleagues;
	    }

    }
    size_t getSize() const;
    Colleague ** getColleague() const;

};


/**
 * читає робітників з файлу та виделяє пам'ять пд них
 * @param filename назва файлу
 * @return всіх прочитаних робітників
 */
Workers * readColleagueFromFile(string filename);



#endif