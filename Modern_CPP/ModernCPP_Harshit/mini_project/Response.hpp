#ifndef RESPONSE_HPP
#define RESPONSE_HPP

#include <string>
#include <ostream>

class Response {
    private:
        std::string _responseString {""};
        long _responseStatusCode {-1}; 
        double _responseTimeElapsed {0.0};
    public:
        Response() = default;
        Response(const Response&) = delete;
        Response(Response&&) = delete;
        Response& operator=(const Response&) = delete;
        Response& operator=(Response&&) = delete;
        ~Response() = default;

        Response(std::string response, long statusCode, double timeElapsed);

        std::string responseString() const { return _responseString; }

        long responseStatusCode() const { return _responseStatusCode; }

        double responseTimeElapsed() const { return _responseTimeElapsed; }

        friend std::ostream &operator<<(std::ostream &os, const Response &rhs);

        friend class Request;
};

#endif // RESPONSE_HPP
