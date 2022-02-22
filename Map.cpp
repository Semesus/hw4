//
// Created by dude on 2/21/22.
//

#include "Map.h"
#include <utility>

Map::Map(std::shared_ptr<std::string> key, int val) : key_(std::move(key)), val_(val) {}

Map::Map() : val_(-1) {}

Map::~Map() = default;

int Map::compare(const std::shared_ptr<Map>& other) {
    if(other == nullptr || other->getKey() == nullptr) {
        throw "error";
    }
    return key_->compare(*(other->getKey()));
}

int Map::compare(const std::shared_ptr<std::string>& other) {
    if(other == nullptr) {
        throw "error";
    }
    return key_->compare(*other);
}

std::shared_ptr<std::string> Map::getKey() {
    return key_;
}

int Map::getVal() {
    return val_;
}

void Map::setVal(int val) {
    val_ = val;
}
