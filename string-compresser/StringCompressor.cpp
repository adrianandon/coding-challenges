#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <sstream>
#include <mutex>
#include <vector>

class StringCompressor{

public:	

	
	static auto  getStringCompressor(){
		std::lock_guard<std::mutex> mutexLock(m_mutex);

		if (!m_StringCompreserSingleton)
			m_StringCompreserSingleton = new StringCompressor();

		return m_StringCompreserSingleton;

	}

auto compressString(std::string str)
{

	std::vector<std::pair<char, int>> charCounts;

	for (auto it = str.begin(); it != str.end(); it++)
	{
		auto count = 1;		
		auto currentChar = *it;
		
		
		while ((it+1)!= str.end() && currentChar == *(it+1))
		{
			count++;
			it++;
		}
		
		charCounts.push_back(std::pair<char, int> { currentChar, count });
				
	}

	std::stringstream compressedStream;

	for (auto it = charCounts.begin(); it != charCounts.end(); it++)
	{
		compressedStream << (*it).first;
		if((*it).second > 1)
			compressedStream << (*it).second;
	}
		

	return compressedStream.str();

}

private: 
	
	StringCompressor() {};
	static std::mutex m_mutex;
	static StringCompressor* m_StringCompreserSingleton;

};

std::mutex StringCompressor::m_mutex;
StringCompressor* StringCompressor::m_StringCompreserSingleton;

int main()
{
	std::string uncompressedStr = "aaaabbbcddaxaa";

	auto compresser = StringCompressor::getStringCompressor();

	auto compressedStr = compresser->compressString(uncompressedStr);

	return 0;
}
