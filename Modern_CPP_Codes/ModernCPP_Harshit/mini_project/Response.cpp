#include <iostream>
#include "Response.hpp"

std::ostream &operator<<(std::ostream &os, const Response &rhs) {
    os << "_responseString: " << rhs._responseString
       << " _responseStatusCode: " << rhs._responseStatusCode
       << " _responseTimeElapsed: " << rhs._responseTimeElapsed;
    return os;
}

Response::Response(std::string response, long statusCode, double timeElapsed)
    : _responseString(response), _responseStatusCode(statusCode), _responseTimeElapsed(timeElapsed) {}
