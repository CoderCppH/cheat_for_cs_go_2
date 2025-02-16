#pragma once
#include <Windows.h>
namespace msc{
    class unique_handle
    {
    private:
        HANDLE __Handle_ptr;
    public:
        unique_handle():unique_handle(nullptr) { }
        unique_handle(HANDLE _OUT_HANDLE) {
            set(_OUT_HANDLE);
        }
        void reset() {
            this->__Handle_ptr = nullptr;
        }
        HANDLE* get() {
            return &this->__Handle_ptr;
        }
        HANDLE* data() {
            return &this->__Handle_ptr;
        }
        bool close_handle() {
            BOOL _b_flags = CloseHandle(this->__Handle_ptr);
            this->__Handle_ptr = nullptr;
            return _b_flags;
        }
        void set(HANDLE _OUT_HANDLE) {
            close_handle();
            this->__Handle_ptr = _OUT_HANDLE;
        }
        ~unique_handle()  {
            close_handle();
        }
    };
}