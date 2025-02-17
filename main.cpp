#include <iostream>
#include "source/msc_init.h"
int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "ru");
    auto list = msc::get_last_screen_shot_process();
    printf("%d\n", list.size());
    for(auto i_pi : list) {
        std::wcout << L"EXCE: " << i_pi.pe->szExeFile << std::endl; 
    }
    return EXIT_SUCCESS;
}