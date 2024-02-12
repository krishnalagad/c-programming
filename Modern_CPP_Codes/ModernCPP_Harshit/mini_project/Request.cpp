#include <iostream>
#include "Request.hpp"

std::ostream &operator<<(std::ostream &os, const Request &rhs) {
    os << "_apiEndPointUrl: " << rhs._apiEndPointUrl;
    return os;
}

Request::Request(std::string url)   // member list initilization executes before entering into constructor body
    : _apiEndPointUrl{url},  _curlSession{curl_easy_init(), curl_easy_cleanup} {

    // write function to write response
    auto fn =  [](void *ptr, size_t size, size_t nmemb, std::string* data) -> size_t {
        data->append((char*) ptr, size * nmemb);
        return size * nmemb;
    };

    // How will I save returning data in my program memory ?
    // pass pointer to a function that contains logic
    // writeFunction is used here
    curl_easy_setopt(_curlSession.get(), CURLOPT_WRITEFUNCTION, +fn);
    
    // Set url 
    curl_easy_setopt(_curlSession.get(), CURLOPT_URL, _apiEndPointUrl.c_str());
}

std::shared_ptr<Response> Request::executeApiCall() {
    std::shared_ptr<Response> resPtr =  std::make_shared<Response>();
   
   // // option to pass pointer to the responce variable
    curl_easy_setopt(_curlSession.get(), CURLOPT_WRITEDATA, &(resPtr->_responseString));

    // finally execute the api call
    curl_easy_perform(_curlSession.get());

    // Now use this commands to map above Reponse to response code and time variables
    curl_easy_getinfo(_curlSession.get(), CURLINFO_RESPONSE_CODE, &resPtr->_responseStatusCode);
    curl_easy_getinfo(_curlSession.get(), CURLINFO_TOTAL_TIME, &resPtr->_responseTimeElapsed);

    return resPtr;
}






// Request::Request(std::string url)
//     : _apiEndPointUrl{url} {
//     _curlSession = std::shared_ptr<CURL>(curl_easy_init(), curl_easy_cleanup);

//     // write function to write response
//     auto fn =  [](void *ptr, size_t size, size_t nmemb, std::string* data) -> size_t {
//         data->append((char*) ptr, size * nmemb);
//         return size * nmemb;
//     };

//     // How will I save returning data in my program memory ?
//     // pass pointer to a function that contains logic
//     // writeFunction is used here
//     curl_easy_setopt(_curlSession.get(), CURLOPT_WRITEFUNCTION, +fn);
    
//     curl_easy_setopt(_curlSession.get(), CURLOPT_URL, _apiEndPointUrl.c_str());
// }

// std::shared_ptr<Response> Request::executeApiCall() {
//     std::shared_ptr<Response> resPtr =  std::make_shared<Response>();
   
//     curl_easy_setopt(_curlSession.get(), CURLOPT_WRITEDATA, &resPtr->_responseString);

    
//     curl_easy_perform(_curlSession.get());

//     // Now use this commands to map above Reponse object
//     curl_easy_getinfo(_curlSession.get(), CURLINFO_RESPONSE_CODE, &resPtr->_responseStatusCode);
//     curl_easy_getinfo(_curlSession.get(), CURLINFO_TOTAL_TIME, &resPtr->_responseTimeElapsed);

//     return resPtr;
// }






// Request::Request(std::string url)
//     : _apiEndPointUrl{url}{

//     _curlSession = std::shared_ptr<CURL*> ();
//     // _curlSession = std::shared_ptr<CURL>(curl_easy_init(), curl_easy_cleanup);

//     _curlSession = std::make_shared<CURL*>(curl_easy_init());

//     // write function to write response
//     auto fn =  [](void *ptr, size_t size, size_t nmemb, std::string* data) -> size_t {
//         data->append((char*) ptr, size * nmemb);
//         return size * nmemb;
//     };

    // How will I save returning data in my program memory ?
    // pass pointer to a function that contains logic
    // writeFunction is used here
//     curl_easy_setopt(
//         _curlSession.get(), 
//         CURLOPT_WRITEFUNCTION, 
//         +fn     // how to convert lambda fn to function ptr ? -> use +: it converts lambda into function ptr
//     );

//     // option for URL
//     curl_easy_setopt(_curlSession.get(), CURLOPT_URL, _apiEndPointUrl);

//     // url mapping is here!!
//     curl_easy_getinfo(_curlSession.get(), CURLINFO_EFFECTIVE_URL, &_apiEndPointUrl);
// }

// std::shared_ptr<Response> Request::executeApiCall() {
//     std::shared_ptr<Response> resPtr =  std::make_shared<Response>();

//     // option to pass pointer to the responce variable
//     curl_easy_setopt(
//         _curlSession.get(), 
//         CURLOPT_WRITEDATA, 
//         &resPtr->_responseString
//     );

//     // Now use this commands to map above Reponse object
//     curl_easy_getinfo(_curlSession.get(), CURLINFO_RESPONSE_CODE, &resPtr->_responseStatusCode);
//     curl_easy_getinfo(_curlSession.get(), CURLINFO_TOTAL_TIME, &resPtr->_responseTimeElapsed);

//     curl_easy_perform(_curlSession.get());

//     return resPtr;
// }

