#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
namespace msc {
    class log_terminal {
        private:
        bool __is_debug;
        std::vector<std::string> __msg_list;
        public:
        log_terminal() {
            __is_debug = false;
            __msg_list = std::vector<std::string>();
            __msg_list.emplace_back("\t----LOG-TEXT----\n");
        }
        void set_debug(bool debug) {
            __is_debug = debug;
        }
        void send_error(const std::string& msg_error) {
            this->__msg_list.push_back( std::string("\t\t----ERROR----: ") + msg_error + std::string("\n"));
        }
        void send_message(const std::string& msg) {
            this->__msg_list.push_back( std::string("----MSG----: ") + msg + std::string("\n"));
            std::cout << msg << std::endl;
        }
        void send_debug(const std::string& msg_debug) {
            this->__msg_list.push_back( std::string("----DEBUG----: ") + msg_debug + std::string("\n"));
            if(__is_debug)
                  std::cout << "DEBUG: " << msg_debug << std::endl;
        }
        void print_loger() {
            for(const auto& msg : __msg_list) {
                std::cout << msg << std::endl;
            }
        }
        ~log_terminal(){
            std::ofstream _log_file("log_file.txt", std::ios::app);
            _log_file << "##################################################\n##################################################\n##################################################" << std::endl;
            for(const auto& msg : __msg_list) {
                _log_file << msg << std::endl;
            }
        }
    };
}