//
// Created by dude on 2/10/22.
//

#include "Node.h"

Node::Node() {}

Node::Node(const std::string &key) : smKey_{key}, left_{nullptr}, mid_{nullptr}, right_{nullptr} {}

Node::Node(const std::string &key, std::shared_ptr<Node> leftPtr, std::shared_ptr<Node> midPtr,
           std::shared_ptr<Node> rightPtr) : smKey_{key}, left_{leftPtr},
           mid_{midPtr}, right_{rightPtr} {}

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

void Node::setLeftPtr(std::shared_ptr<Node> leftPtr) {
    left_ = leftPtr;
}

void Node::setMidPtr(std::shared_ptr<Node> midPtr) {
    mid_ = midPtr;
}

void Node::setRightPtr(std::shared_ptr<Node> rightPtr) {
    right_ = rightPtr;
}


