//
// Created by dude on 2/8/22.
//

#ifndef HW4_NODE_H
#define HW4_NODE_H
#include <string>
#include <memory>
class Map;

class Node {
private:
    //std::string smKey_, lgKey_;
    //int smVal_{}, lgVal_{};
    std::shared_ptr<Map> sm_, med_, lg_;
    std::shared_ptr<Node> alpha_, bravo_, charlie_, delta_, parent_;
    //bool twoVal_ = false;
    //std::shared_ptr<Node> left_, mid_, right_;
    //std::shared_ptr<Node> temp_ = nullptr;
    //std::shared_ptr<Node> parent_ = nullptr;

public:
    Node();
    //explicit Node(const std::string& key, int val);
   // Node(const std::string& key, std::shared_ptr<Node> leftPtr, std::shared_ptr<Node> midPtr,
    //      std::shared_ptr<Node> rightPtr);
    ~Node();

    bool isLeaf() const;
    bool isTwoNode() const;
    bool isThreeNode() const;
    bool isTwoVal() const;

    bool insert(const std::shared_ptr<Map>&);
    bool toSplit();

    std::shared_ptr<Map> getSm();
    std::shared_ptr<Map> getMed();
    std::shared_ptr<Map> getLg();

    std::shared_ptr<Map> get(std::shared_ptr<std::string> key);

    void setSm(std::shared_ptr<Map>);
    void setMed(std::shared_ptr<Map>);
    void setLg(std::shared_ptr<Map>);

    std::shared_ptr<Node> getAlpha();
    std::shared_ptr<Node> getBravo();
    std::shared_ptr<Node> getCharlie();
    std::shared_ptr<Node> getDelta();
    std::shared_ptr<Node> getParent();

    void setAlpha(std::shared_ptr<Node>);
    void setBravo(std::shared_ptr<Node>);
    void setCharlie(std::shared_ptr<Node>);
    void setDelta(std::shared_ptr<Node>);
    void setParent(const std::shared_ptr<Node>&);

    //std::string getSmKey() const;
    //std::string getLgKey() const;
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
    //void setParent(std::shared_ptr<Node> parent);

    void replace(std::shared_ptr<Node>&, std::shared_ptr<Node>&, std::shared_ptr<Node>&);
    bool contains(std::shared_ptr<std::string> &key) const;
};

#endif //HW4_NODE_H
