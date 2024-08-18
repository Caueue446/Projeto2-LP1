#ifndef CIDADE_H
#define CIDADE_H

#include <string>

class Cidade {
private:
    std::string name;

public:
    Cidade(const std::string& nome);

    std::string getName() const;
};

#endif
