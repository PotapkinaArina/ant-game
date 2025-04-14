#ifndef ANTOBSERVER_H
#define ANTOBSERVER_H

#include <string>

class AntObserver {
public:
    virtual void onEvent(const std::string& event) = 0;
    virtual ~AntObserver() = default;
};

#endif