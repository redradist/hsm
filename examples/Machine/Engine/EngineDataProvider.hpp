#ifndef _ENGINE_DATA_PROVIDER_HPP_
#define _ENGINE_DATA_PROVIDER_HPP_

#include <string>

struct EngineDataProvider
{
   std::string 					name;
   std::map<int, std::string> 	parameterValue;
};

#endif // _ENGINE_DATA_PROVIDER_HPP_