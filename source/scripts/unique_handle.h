#pragma once
#include <Windows.h>
class unique_handle
{
private:
    HANDLE __Handle_ptr;
public:
    void reset(){
        this->__Handle_ptr = static_cast<HANDLE>(NULL);
    }
    HANDLE* get(){
        return &this->__Handle_ptr;
    }
};