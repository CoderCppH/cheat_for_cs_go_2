#pragma once
#include <Windows.h>
#include "../scripts/unique_handle.h"
namespace msc
{
    class memory_stream
    {
    private:
        msc::unique_handle __smart_handle { };
    public:
        memory_stream(HANDLE _OUT_HANDLE) inline noexcept {
            __smart_handle = { _OUT_HANDLE };
        }
        template<typename t_read>
        t_read read_memory(void* _OUT_BASE_ADDRES) noexcept
        {
            t_read _read_buffer;
	        ReadProcessMemory(&__smart_handle.get(), _OUT_BASE_ADDRES, &_read_buffer, sizeof(_read_buffer), nullptr);
	        return _read_buffer;
        }
        template<typename t_write>
        BOOL write_memory(void* _OUT_BASE_ADDRES, t_write _OUT_VALUE_FOR_WRITING) inline noexcept
        {
            return WriteProcessMemory(&__smart_handle.get(), _OUT_BASE_ADDRES, &_OUT_VALUE_FOR_WRITING, sizeof(_OUT_VALUE_FOR_WRITING), nullptr);
        }
        void close() inline noexcept
        {
            __smart_handle.close_handle();
        }
    };
}