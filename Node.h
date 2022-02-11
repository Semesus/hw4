//
// Created by dude on 2/10/22.
//

#ifndef HW4_NODE_H
#define HW4_NODE_H
#include <string>
#include <memory>

class Node {
private:
    std::string smKey_, lgKey_;
    int smVal_, lgVal_;
    std::shared_ptr<Node> left_;
    std::shared_ptr<Node> mid_;
    std::shared_ptr<Node> right_;

public:
    Node();
    explicit Node(const std::string& key);
    Node(const std::string& key, std::shared_ptr<Node> leftPtr,
         std::shared_ptr<Node> midPtr, std::shared_ptr<Node> rightPtr);
    ~Node();

    bool isLeaf() const;
    bool isTwoNode() const;
    bool isThreeNode() const;

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

    void setLeftPtr(std::shared_ptr<Node> leftPtr);
    void setMidPtr(std::shared_ptr<Node> midPtr);
    void setRightPtr(std::shared_ptr<Node> rightPtr);
};

#endif //HW4_NODE_H
