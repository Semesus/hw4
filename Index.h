//
// Created by dude on 2/8/22.
//

#ifndef HW4_INDEX_H
#define HW4_INDEX_H

#include <vector>

class Node;
class Map;

class Index {
private:
    std::shared_ptr<Node> root_;

    void split(std::shared_ptr<Node> );
    // from lecture
    //std::shared_ptr<Node> locate(std::shared_ptr<std::string>);
    void fixTree(std::shared_ptr<Node>, std::shared_ptr<Node>);

    // returns node w/ key or node that should have key
    std::shared_ptr<Node> findNode(std::shared_ptr<std::string>&);


public:
    // public ctor
    Index();
    ~Index();

    // insert an element in the index, associate the integer value with the element
    void Insert(std::shared_ptr<std::string> &key, int val);

    // remove an element from the index
    void Remove(std::shared_ptr<std::string> &key);

    // find an element in the index
    int Find(std::shared_ptr<std::string> &key);

    std::shared_ptr<Node> findNode(std::shared_ptr<Node> root, std::shared_ptr<std::string> &key);

    std::shared_ptr<Node> getRoot() const;

    void printTree(std::shared_ptr<Node> root, int indent);

    void print(std::shared_ptr<Node> &root);
};


#endif //HW4_INDEX_H
