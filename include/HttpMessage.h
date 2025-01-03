//
// Created by mdkam on 01/01/2025.
//

#ifndef HTTPMESSAGE_H
#define HTTPMESSAGE_H
#include <string>


// HTTP methods defined in the following document:
// https://developer.mozilla.org/en-US/docs/Web/HTTP/Methods
enum class HttpMethod {
    GET,
    HEAD,
    POST,
    PUT,
    DELETE,
    CONNECT,
    OPTIONS,
    TRACE,
    PATCH
  };

// Here we only support HTTP/1.1
enum class HttpVersion {
    HTTP_0_9 = 9,
    HTTP_1_0 = 10,
    HTTP_1_1 = 11,
    HTTP_2_0 = 20
};


// HTTP response status codes as listed in:
// https://developer.mozilla.org/en-US/docs/Web/HTTP/Status
// Note that not all of them are present in this enum class
enum class HttpStatusCode {
    Continue = 100,
    SwitchingProtocols = 101,
    EarlyHints = 103,
    Ok = 200,
    Created = 201,
    Accepted = 202,
    NonAuthoritativeInformation = 203,
    NoContent = 204,
    ResetContent = 205,
    PartialContent = 206,
    MultipleChoices = 300,
    MovedPermanently = 301,
    Found = 302,
    NotModified = 304,
    BadRequest = 400,
    Unauthorized = 401,
    Forbidden = 403,
    NotFound = 404,
    MethodNotAllowed = 405,
    RequestTimeout = 408,
    ImATeapot = 418,
    InternalServerError = 500,
    NotImplemented = 501,
    BadGateway = 502,
    ServiceUnvailable = 503,
    GatewayTimeout = 504,
    HttpVersionNotSupported = 505
};

class HttpMessage {
    private: HttpVersion httpVersion = HttpVersion::HTTP_1_1;
    private: HttpStatusCode httpStatusCode = HttpStatusCode::Ok;
    private: std::string header;
    private: std::string body;

    //setters
    public:
    void setHttpVersion(HttpVersion httpVersion);
    void setHttpStatusCode(HttpStatusCode httpStatusCode);

    void setHeader(const std::string &header);
    const std::string getHeader();

    void setBody(const std::string &body);


    const std::string createPayload();


};

#endif //HTTPMESSAGE_H
