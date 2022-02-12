//
// Created by dude on 2/8/22.
//

#ifndef HW4_NODE_H
#define HW4_NODE_H
#include <string>
#include <memory>

class Node {
private:
    std::string smKey_, lgKey_;
    int smVal_, lgVal_;
    bool twoVal_ = false;
    std::shared_ptr<Node> left_;
    std::shared_ptr<Node> mid_;
    std::shared_ptr<Node> right_;
    std::shared_ptr<Node> temp_ = nullptr;
    std::shared_ptr<Node> parent_ = nullptr;

public:
    Node();
    explicit Node(const std::string& key, int val);
    Node(const std::string& key, std::shared_ptr<Node> leftPtr, std::shared_ptr<Node> midPtr,
          std::shared_ptr<Node> rightPtr);
    ~Node();

    bool isLeaf() const;
    bool isTwoNode() const;
    bool isThreeNode() const;
    bool isTwoVal() const;

    std::string getSmKey() const;
    std::string getLgKey() const;
    int getSmVal() const;
    int getLgVal() const;

    void setSmKey(const std::string &key);
    void setLgKey(const std::string &key);
    void setSmVal(const int &val);
    void setLgVal(const int &val);

    std::shared_ptr<Node> getLeftPtr() const;
    std::shared_ptr<Node> getMidPtr() const;
    std::shared_ptr<Node> getRightPtr() const;
    std::shared_ptr<Node> getTempPtr() const;
    std::shared_ptr<Node> getParent() const;

    void setLeftPtr(std::shared_ptr<Node> leftPtr);
    void setMidPtr(std::shared_ptr<Node> midPtr);
    void setRightPtr(std::shared_ptr<Node> rightPtr);
    void setTempPtr(std::shared_ptr<Node> tempPtr);
    void setParent(std::shared_ptr<Node> parent);
};

#endif //HW4_NODE_H
