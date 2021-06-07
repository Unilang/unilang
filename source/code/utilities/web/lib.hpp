#pragma once
#include <curl/curl.h>
#include <string>
#include <vector>
#include "code/utilities/web/html_fetch_settings.hpp"
#include "code/utilities/web/web_json_extraction_settings.hpp"

nlohmann::json Extract_Web_Json(Html_Fetch_Settings const& settings);
float Extract_Web_Json_Float(Web_Json_Extraction_Settings const& settings);


std::vector<std::string> Get_Each_Line_Of_Html_Site(Html_Fetch_Settings const& settings);
std::string Get_Html_Of_Site(Html_Fetch_Settings const& settings);
std::string Get_HTML_Of_Site_With_Curl_Command(std::string const& website);
std::string Get_HTML_Of_Site_With_Curl_Lib(Html_Fetch_Settings const& settings);



std::vector<std::string> Get_HTML_Of_Site_With_Each_Line_In_Vector(std::string const& website);
void Send_Email(std::string const& message, std::string const& email);

int Website_Response_Code(std::string const& url);
bool Is_Url_Reponse_200(std::string const& url);
