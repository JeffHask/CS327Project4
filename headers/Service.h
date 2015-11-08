//
// Created by jeffrey on 11/7/15.
//

#ifndef CS327PROJECT4_SERVICE_H
#define CS327PROJECT4_SERVICE_H


#include "IService.h"

class Service : public IService {
protected:
    virtual void helperMessage() = 0;
    void h_helperMessage();
    void o_helperMessage();
    void w_helperMessage();
public:
    virtual void run() = 0;
};


#endif //CS327PROJECT4_SERVICE_H
