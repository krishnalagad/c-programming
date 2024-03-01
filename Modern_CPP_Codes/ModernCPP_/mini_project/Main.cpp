#include <curl/curl.h>
#include <string>
#include <memory>
#include <iostream>
#include "Request.hpp"

int main() {
    std::string url = "https://min-api.cryptocompare.com/data/price?fsym=BTC&tsyms=USD,JPY,EUR,INR";

    // request object creation (on heap managed by smart pointer)
    std::shared_ptr<Request> requestPtr = std::make_shared<Request>(url);

    // response object return by fucntion (on heap managed by smart pointer)
    std::shared_ptr<Response> responsePtr = requestPtr->executeApiCall();

    std::cout << "API Returns: " << responsePtr->responseString() << std::endl;
    std::cout << "API Status code: " << responsePtr->responseStatusCode() << std::endl;
    std::cout << "API time taken: " << responsePtr->responseTimeElapsed() << std::endl;

    return 0;
}

// size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string* data) {
//     data->append((char*) ptr, size * nmemb);
//     return size * nmemb;
// }

// int main(int argc, char** argv) {
//     // step 1: initialize session objecct
//     auto curl = curl_easy_init();

//     // step 2: if session object is NOT NULL
//     if (curl) {
//         curl_easy_setopt(curl, CURLOPT_URL, "https://min-api.cryptocompare.com/data/price?fsym=BTC&tsyms=USD,JPY,EUR,INR");
        
//         // curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
//         // curl_easy_setopt(curl, CURLOPT_USERPWD, "user:pass");
//         // curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.42.0");
//         // curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50L);
//         // curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);
        
//         // respoonce data store in this string
//         std::string response_string;

//         // while makking a request, if any extra data need to passed, pass it in this string
//         std::string header_string;

//         // How will I save returning data in my program memory ?
//         // pass pointer to a function that contains logic
//         // writeFunction is used here
//         curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);

//         // option to pass pointer to the responce variable
//         curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);

//         // option to pass pointer to the header variable
//         curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header_string);
        
//         char* url;  // use this url to fetch data
//         long response_code;    // use this variable to store responce api code
//         double elapsed;     // time taken to complete the request

//         // Now use this commands to map above variable
//         curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
//         curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &elapsed);
//         curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &url);
        
//         // finally execute the api call
//         curl_easy_perform(curl);

//         // print the response here
//         std::cout << response_string << std::endl;

//         // end the session, clean memory allocated
//         curl_easy_cleanup(curl);

//         // set curl to NULL to indicate the end of process
//         curl = NULL;
//     }
// }