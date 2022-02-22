//
// Created by dude on 2/21/22.
//

#ifndef HW4_MAP_H
#define HW4_MAP_H
#include <string>
#include <memory>

class Map {
private:
    std::shared_ptr<std::string> key_;
    int val_;
public:
    Map(std::shared_ptr<std::string>, int);
    Map();
    ~Map();

    int compare(const std::shared_ptr<Map>&);
    int compare(const std::shared_ptr<std::string>&);
    std::shared_ptr<std::string> getKey();
    int getVal();
    void setVal(int);
};

#endif //HW4_MAP_H
