#include <iostream>
#include "Request.hpp"

std::ostream &operator<<(std::ostream &os, const Request &rhs) {
    os << "_apiEndPointUrl: " << rhs._apiEndPointUrl;
    return os;
}

Request::Request(std::string url, std::shared_ptr<CURL> session)
    : _apiEndPointUrl{url}, _curlSession{session} {

    // write function to write response
    auto fn =  [](void *ptr, size_t size, size_t nmemb, std::string* data) -> size_t {
        data->append((char*) ptr, size * nmemb);
        return size * nmemb;
    };

    // How will I save returning data in my program memory ?
    // pass pointer to a function that contains logic
    // writeFunction is used here
    curl_easy_setopt(
        _curlSession.get(), 
        CURLOPT_WRITEFUNCTION, 
        +fn     // how to convert lambda fn to function ptr ? -> use +: it converts lambda into function ptr
    );

    // option for URL
    curl_easy_setopt(_curlSession.get(), CURLOPT_URL, "https://min-api.cryptocompare.com/data/price?fsym=BTC&tsyms=USD,JPY,EUR,INR");

    // url mapping is here!!
    curl_easy_getinfo(_curlSession.get(), CURLINFO_EFFECTIVE_URL, &_apiEndPointUrl);
}

std::shared_ptr<Response> Request::executeApiCall() {
    std::shared_ptr<Response> resPtr =  std::make_shared<Response>();

    // option to pass pointer to the responce variable
    curl_easy_setopt(
        _curlSession.get(), 
        CURLOPT_WRITEDATA, 
        &resPtr->_responseString
    );

    // Now use this commands to map above Reponse object
    curl_easy_getinfo(_curlSession.get(), CURLINFO_RESPONSE_CODE, &resPtr->_responseStatusCode);
    curl_easy_getinfo(_curlSession.get(), CURLINFO_TOTAL_TIME, &resPtr->_responseTimeElapsed);
    
}
