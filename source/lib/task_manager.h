#pragma once
#include "../scripts/unique_handle.h"
#include <Windows.h>
#include <TlHelp32.h>
#include <vector>
#include <iostream>
namespace msc {
    class proces_info {
        public:
        PROCESSENTRY32W* pe;
        std::vector<THREADENTRY32> ths;
        proces_info(PROCESSENTRY32W* processEntry):  pe(processEntry) {}
    };

    std::vector<proces_info> get_last_screen_shot_process(){
        std::vector<proces_info> list_proc_info = std::vector<proces_info>();
        unique_handle __smart_handle = unique_handle(CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS | TH32CS_SNAPTHREAD, NULL));
        PROCESSENTRY32W pe { sizeof(PROCESSENTRY32W) };
        if(Process32FirstW(__smart_handle.get(), &pe)) {
            while(Process32NextW(__smart_handle.get(), &pe)) {
                proces_info _proc_info = proces_info(&pe);
                THREADENTRY32 th { sizeof(THREADENTRY32) };
                if(Thread32First(__smart_handle.get(), &th)) {
                    while (Thread32Next(__smart_handle.get(), &th))
                    {
                        std::vector<THREADENTRY32> ths = std::vector<THREADENTRY32>();
                        ths.push_back(th);
                        _proc_info.ths = ths;
                    }
                }
                list_proc_info.push_back(_proc_info);
            }
        }
        __smart_handle.close_handle();
        return list_proc_info;
    }
}