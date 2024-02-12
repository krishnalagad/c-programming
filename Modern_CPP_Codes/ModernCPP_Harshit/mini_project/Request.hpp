#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <string>
#include <curl/curl.h>
#include <ostream>
#include <memory>
#include "Response.hpp"

// This class cannot be used as parent for inheritance
class Request final {
    private:
        std::string _apiEndPointUrl;
        std::shared_ptr<CURL> _curlSession;

    public:
        Request() = delete;
        Request(const Request&) = delete;
        Request(Request&&) = delete;
        Request& operator=(const Request&) = delete;
        Request& operator=(Request&&) = delete;
        ~Request() = default;

        Request(std::string url);

        std::string apiEndPointUrl() const { return _apiEndPointUrl; }

        // setter might be useful to reuse one request object for subsequent api classd!
        void setApiEndPointUrl(const std::string &apiEndPointUrl) { _apiEndPointUrl = apiEndPointUrl; }

        friend std::ostream &operator<<(std::ostream &os, const Request &rhs);

        std::shared_ptr<Response> executeApiCall();
};  

#endif // REQUEST_HPP
