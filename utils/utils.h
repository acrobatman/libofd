#ifndef __OFDUTILS_H__
#define __OFDUTILS_H__

#include <tuple>
#include <string>

namespace tinyxml2{
    class XMLElement;
}

extern std::string GetChildElements(const tinyxml2::XMLElement *element);
extern std::vector<std::string> SpliteString(const std::string& content);
extern std::tuple<double, double, double, double, bool> parsePhysicalBoxElement(const tinyxml2::XMLElement *physicalBoxElement);

#define GetChildElementText(element, childname, variable) \
    { \
        const XMLElement *childElement = element->FirstChildElement(#childname); \
        if (childElement != NULL ){ \
            variable = childElement->GetText(); \
        } \
    } \
    
#endif // __OFDUTILS_H__ 
