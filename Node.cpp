//
// Created by dude on 2/8/22.
//

#include "Node.h"

#include <utility>

Node::Node() = default;

Node::Node(const std::string &key, int val) : smKey_{key}, smVal_{val},
           left_{nullptr}, mid_{nullptr}, right_{nullptr} {}

Node::Node(const std::string &key, std::shared_ptr<Node> leftPtr, std::shared_ptr<Node> midPtr,
           std::shared_ptr<Node> rightPtr) : smKey_{key}, left_{std::move(leftPtr)},
           mid_{std::move(midPtr)}, right_{std::move(rightPtr)} {}

Node::~Node() = default;

bool Node::isLeaf() const {
    if(left_ == nullptr && mid_ == nullptr && right_ == nullptr) {
        return true;
    }
    return false;
}

bool Node::isTwoNode() const {
    if(right_ == nullptr) {
        return true;
    }
    return false;
}

bool Node::isThreeNode() const {
    if(right_ != nullptr) {
        return true;
    }
    return false;
}

bool Node::isTwoVal() const {
    return twoVal_;
}

std::string Node::getSmKey() const {
    return smKey_;
}

std::string Node::getLgKey() const {
    return lgKey_;
}

int Node::getSmVal() const {
    return smVal_;
}

int Node::getLgVal() const {
    return lgVal_;
}

void Node::setSmKey(const std::string &key) {
    smKey_ = key;
}

void Node::setLgKey(const std::string &key) {
    lgKey_ = key;
}

void Node::setSmVal(const int &val) {
    smVal_ = val;
}

void Node::setLgVal(const int &val) {
    twoVal_ = true;
    lgVal_ = val;
}

std::shared_ptr<Node> Node::getLeftPtr() const {
    return left_;
}

std::shared_ptr<Node> Node::getMidPtr() const {
    return mid_;
}

std::shared_ptr<Node> Node::getRightPtr() const {
    return right_;
}

std::shared_ptr<Node> Node::getTempPtr() const {
    return temp_;
}

std::shared_ptr<Node> Node::getParent() const {
    return parent_;
}

void Node::setLeftPtr(std::shared_ptr<Node> leftPtr) {
    left_ = std::move(leftPtr);
}

void Node::setMidPtr(std::shared_ptr<Node> midPtr) {
    mid_ = std::move(midPtr);
}

void Node::setRightPtr(std::shared_ptr<Node> rightPtr) {
    right_ = std::move(rightPtr);
}

void Node::setTempPtr(std::shared_ptr<Node> tempPtr) {
    temp_ = std::move(tempPtr);
}

void Node::setParent(std::shared_ptr<Node> parent) {
    parent_ = std::move(parent);
}

// from lecture
void Node::replace(std::shared_ptr<Node> n, std::shared_ptr<Node> n1, std::shared_ptr<Node> n2) {
    if(n == left_) {
        temp_ = right_;
        right_ = mid_;
        mid_ = n2;
        left_ = n1;
    }  else if(n == mid_) {
        temp_ = right_;
        right_ = n2;
        mid_ = n1;
        // left_ unchanged
    } else {
        temp_ = n2;
        right_ = n1;
    }
}

bool Node::contains(std::shared_ptr<std::string> &key) {
    if(getSmKey().compare(*key) == 0) {
        return true;
    }
    if(getLgKey().compare(*key) == 0) {
        return true;
    }
    return false;
}

int Node::compare(std::shared_ptr<Node> other) {
    //if(other == nullptr || other->getSmKey() == nullptr)
}

int Node::compare(std::shared_ptr<std::string> other) {
    return 0;
}
