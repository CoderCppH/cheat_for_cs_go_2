#pragma once
#include <Windows.h>
namespace msc{
    class unique_handle
    {
    private:
        HANDLE __Handle_ptr;
    public:
        unique_handle() noexcept :unique_handle(nullptr) { }
        unique_handle(HANDLE _OUT_HANDLE) noexcept{
            set(_OUT_HANDLE);
        }
        void reset() inline noexcept {
            this->__Handle_ptr = nullptr;
        }
        HANDLE* get() inline noexcept {
            return &this->__Handle_ptr;
        }
        HANDLE* data() inline noexcept {
            return &this->__Handle_ptr;
        }
        bool close_handle() noexcept{
            BOOL _b_flags = CloseHandle(this->__Handle_ptr);
            this->__Handle_ptr = nullptr;
            return _b_flags;
        }
        void set(HANDLE _OUT_HANDLE) noexcept{
            close_handle();
            this->__Handle_ptr = _OUT_HANDLE;
        }
        ~unique_handle() noexcept {
            close_handle();
        }
    };
}