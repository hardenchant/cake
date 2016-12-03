#pragma once

#include <curl\curl.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


namespace mr {
	size_t read_request_data(char *ptr, size_t size, size_t nmemb, void *userdata);
	size_t write_response_data(char *ptr, size_t size, size_t nmemb, void *userdata);
	std::string recognize(const std::string path);
	std::vector<std::string> parseRequest(std::string request);
}