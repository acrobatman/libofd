#include <sstream>
#include <iterator>
#include <iostream>
#include "utils.h"

namespace utils{

    std::vector<std::string> SplitString(const std::string& content){
        std::istringstream iss(content);
        std::vector<std::string> tokens{std::istream_iterator<std::string>{iss}, 
            std::istream_iterator<std::string>{}};
        return tokens;
    }

    void SetStringStreamPrecision(std::stringstream &ss, int precision){
        ss.setf(std::ios::fixed, std::ios::floatfield); \
            ss.precision(precision);
    }
}


