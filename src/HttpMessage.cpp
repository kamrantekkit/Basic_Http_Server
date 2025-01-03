//
// Created by mdkam on 01/01/2025.
//

#include "HttpMessage.h"

#include <sstream>


void HttpMessage::setHttpVersion(HttpVersion httpVersion) {
    this->httpVersion = httpVersion;
}

void HttpMessage::setHttpStatusCode(HttpStatusCode httpStatusCode) {
    this->httpStatusCode = httpStatusCode;
}

void HttpMessage::setHeader(const std::string &header) {
    this->header = header;
}

const std::string HttpMessage::getHeader() {
    return header;
}

void HttpMessage::setBody(const std::string &body) {
    this->body = body;
}

const std::string HttpMessage::createPayload() {
    std::ostringstream payload;

    payload << "HTTP/1.1" << static_cast<int>(httpStatusCode) << "OK" << "\r\n";
    payload << "Server: LTDU" << "\r\n";
    payload << "Content-Length: " << body.size() << "\r\n";
    payload << "Content-Type: text/plain" << "\r\n\n";

    payload << body;

    return payload.str();
}

