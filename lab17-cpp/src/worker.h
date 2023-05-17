#ifndef __WORKER_H__
#define __WORKER_H__

#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cerrno>
#include <cstdbool>

#include "colleague.h"

class Workers{
	Colleague** colleagues;
	size_t size;
public:

    void print() const;
    void addElement(size_t pos, const Colleague * colleague);
    void delElement(size_t pos);
    void writeToFile(char * filename) const;
    void sort(const char * fieldName);
    size_t findCountColleagueInCompany_WithoutInsurance(const char * company) const;

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
Workers * readColleagueFromFile(const char * filename);



#endif