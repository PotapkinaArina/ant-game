#ifndef ROLE_H
#define ROLE_H

#include <string>


class Ant;  

class Role {
public:
    virtual void onEvent(const std::string& event) = 0;
    virtual ~Role() = default;
};

class SoldierRole : public Role {
public:
    void onEvent(const std::string& event) override;
};

class BuilderRole : public Role {
public:
    void onEvent(const std::string& event) override;
};

class HarvesterRole : public Role {
public:
    void onEvent(const std::string& event) override;
};

class NannyRole : public Role {
public:
    void onEvent(const std::string& event) override;
};

class CleanerRole : public Role {
public:
    void onEvent(const std::string& event) override;
};

#endif