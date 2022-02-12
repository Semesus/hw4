//
// Created by dude on 2/8/22.
//

#ifndef HW4_INDEX_H
#define HW4_INDEX_H

#include <vector>

class Index {
private:
    std::shared_ptr<Node> root_;
    std::shared_ptr<Node> balance();
    void balance(std::vector<int> &data, int low, int high, std::shared_ptr<Node> &root);

public:
    // public ctor
    Index();

    // insert an element in the index, associate the integer value with the element
    void Insert(std::shared_ptr<std::string> &key, int val);

    // remove an element from the index
    void Remove(std::shared_ptr<std::string> &key);

    // find an element in the index
    int Find(const std::shared_ptr<Node>& root, int target);

    void split(std::shared_ptr<Node> &node);

    void printTree(std::shared_ptr<Node> root, int indent);

    void print(std::shared_ptr<Node> &root);
};


#endif //HW4_INDEX_H
