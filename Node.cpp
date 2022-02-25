//
// Created by dude on 2/8/22.
//

#include "Map.h"
#include "Node.h"

#include <utility>


Node::Node() = default;

/*
Node::Node(const std::string &key, int val) : sm_{key}, smVal_{val},
           left_{nullptr}, mid_{nullptr}, right_{nullptr} {}
/*
Node::Node(const std::string &key, std::shared_ptr<Node> leftPtr, std::shared_ptr<Node> midPtr,
           std::shared_ptr<Node> rightPtr) : smKey_{key}, left_{std::move(leftPtr)},
           mid_{std::move(midPtr)}, right_{std::move(rightPtr)} {}
*/
Node::~Node() = default;

bool Node::isLeaf() const {
    //return !alpha_ && !bravo_ && !charlie_;
    if(alpha_ == nullptr && bravo_ == nullptr && charlie_ == nullptr) {
        return true;
    }
    return false;
}

bool Node::isTwoNode() const {
    return sm_ && !med_;
}

bool Node::isThreeNode() const {
    return sm_ && med_;
}
/*
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
*/
// from lecture
/*void Node::replace(std::shared_ptr<Node> n, std::shared_ptr<Node> n1, std::shared_ptr<Node> n2) {
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
}*/

void Node::replace(std::shared_ptr<Node> &n, std::shared_ptr<Node> &n1, std::shared_ptr<Node> &n2) {
    //if(n->isLeaf()) {
    //   alpha_ = n1;
    //    bravo_ = n2;
    //}

     if(n == alpha_) {
        delta_ = charlie_;
        charlie_ = bravo_;
        bravo_ = n2;
        alpha_ = n1;
    }  else if(n == bravo_) {
        delta_ = charlie_;
        charlie_ = n2;
        bravo_ = n1;
    } else if(n == charlie_){
        delta_ = n2;
        charlie_ = n1;
    } else {
         alpha_ = n1;
         bravo_ = n2;
     }
}

bool Node::contains(std::shared_ptr<std::string> &key) const {
    if(sm_->compare(key) == 0) {
        return true;
    }
    if(med_ != nullptr && med_->compare(key) == 0) {
        return true;
    }
    return false;
}

bool Node::insert(const std::shared_ptr<Map> &newItem) {
    if(sm_ == nullptr) {
        sm_ = newItem;
        return true;
    }
    if(sm_->compare(newItem) == 0) {
        sm_ = newItem;
        return true;
    }
    if(med_ != nullptr) {
        if(med_->compare(newItem) == 0) {
            med_ = newItem;
            return true;
        }
        if(med_->compare(newItem) < 0) {
            lg_ = newItem;
            return false;
        }
        if(med_->compare(newItem) > 0) {
            lg_ = med_;
            if(sm_->compare(newItem) < 0) {
                med_ = newItem;
            } else {
                med_ = sm_;
                sm_ = newItem;
            }
            return false;
        }
    }
    // med == nullptr
    if(sm_->compare(newItem) > 0) {
        med_ = sm_;
        sm_ = newItem;
    } else {
        med_ = newItem;
    }
    return false;
}

bool Node::toSplit() {
    return sm_ && med_ && lg_;
}

std::shared_ptr<Map> Node::getSm() {
    return sm_;
}

std::shared_ptr<Map> Node::getMed() {
    return med_;
}

std::shared_ptr<Map> Node::getLg() {
    return lg_;
}

void Node::setSm(std::shared_ptr<Map> sm) {
    sm_ = sm;
}

void Node::setMed(std::shared_ptr<Map> med) {
    med_ = med;
}

void Node::setLg(std::shared_ptr<Map> lg) {
    lg_ = lg;
}
std::shared_ptr<Node> Node::getAlpha() {
    return alpha_;
}

std::shared_ptr<Node> Node::getBravo() {
    return bravo_;
}

std::shared_ptr<Node> Node::getCharlie() {
    return charlie_;
}

std::shared_ptr<Node> Node::getDelta() {
    return delta_;
}

std::shared_ptr<Node> Node::getParent() {
    return parent_;
}

void Node::setAlpha(std::shared_ptr<Node> a) {
    alpha_ = std::move(a);
}

void Node::setBravo(std::shared_ptr<Node> b) {
    bravo_ = std::move(b);
}

void Node::setCharlie(std::shared_ptr<Node> c) {
    charlie_ = std::move(c);
}

void Node::setDelta(std::shared_ptr<Node> d) {
    delta_ = std::move(d);
}

void Node::setParent(const std::shared_ptr<Node> &parent) {
    parent_ = std::move(parent);
}

std::shared_ptr<Map> Node::get(std::shared_ptr<std::string> key) {
    if(sm_->compare(key) == 0) {
        return sm_;
    }
    if(med_->compare(key) == 0) {
        return med_;
    }
    return nullptr;
}

