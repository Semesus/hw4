//
// Created by dude on 2/8/22.
//

#include "Node.h"
#include "Index.h"
#include <iostream>

#define COUNT 5

Index::Index() : root_{nullptr} {}

void Index::Insert(std::shared_ptr<std::string> &key, int val) {
    // if root == nullptr
    if(root_ == nullptr) {
        // root = make_shared<Node>(key, val)
        root_ = std::make_shared<Node>(*key, val);
        return;
    }
    // locate leafNode in which newItem belongs
    std::shared_ptr<Node> leafNode = findNode(root_, key);
    // add newItem to leafNode
    //if(leafNode->isTwoVal()) {
        if(leafNode->getSmKey().compare(*key) > 0) {
            leafNode->setLgKey(leafNode->getSmKey());
            leafNode->setLgVal(leafNode->getSmVal());
            leafNode->setSmKey(*key);
            leafNode->setSmVal(val);
        } else {
            leafNode->setLgKey(*key);
            leafNode->setLgVal(val);
        }
    //}
    //if leafNode has 3 items
        //split(leafNode)
}

void Index::split(std::shared_ptr<Node> &node) {
// Splits node n, which contains 2 items (if n not leaf, has 4 children
    // split(n: 2-3Node
    // if n is root
        // create new node p
    //else
        // let p be parent of n

    // replace node n w/ 2 nodes, n1 and n2, so p is their parent
    // give n1 the item in n w/ smallest val
    // give n2 item in n with largest val

    // if n is not leaf
        // n1 becomes parent of n's 2 leftmost children
        // n2 becomes parent of n's 2 rightmost children
    // move the item in n that has mid value up to p
    // if p now has 3 items
        // split(p)
}

void Index::Remove(std::shared_ptr<std::string> &key) {
    // attempt to locate dataItem
    // if dataItem is found
        // if dataItem is not in a leaf
            // swap dataItem with its inorder successor, which will be in a leaf leafNode
            // removal always begins at a leaf
            // if leafNode now has no items
                // fixTree(leafNode)
                // return
            // else
                // return
    // complete removal when node n is empty by either deleting root, redistributing values, or merging nodes
    // note: if n is internal, it has 1 child
    // fixTree(n: 23Node)
        // if n is root
            // delete root
        // else
            // let p be parent of n
            // if some sibling of n has 2 items
                // distribute items appropriately among n, the sibling, and p
            // if n is internal
                // move appropriate child from sibling to n
        // else // merge node
            // choose adjacent sibling s of n
            // bring appropriate item down from p into s
            // if n is internal
                // move n's child to s
            // remove node n
            // if p now empty
                // fixTree(p)
}

int Index::Find(const std::shared_ptr<Node>& root, int target) {
    // if target in root node
    if(root->getSmVal() == target) {
        return root->getSmVal();
    }
    else if(root->getLgVal() == target) {
        return root->getLgVal();
    }
    // else if root is leaf
    else if(root->isLeaf()) { // maybe remove?
        return -1;
    }
    // else if root has 2 data items
    else if(root->isTwoVal()) {
        // if target < smallKey
        if(target < root->getSmVal()) {
            //return find(root->left, target
            return Find(root->getLeftPtr(), target);
        }
        // else if target < lgKey
        else if(target < root->getLgVal()) {
            // return find(root->mid, target
            return Find(root->getMidPtr(), target);
        }
        // else
        else {
            // return find(root->right, target
            return Find(root->getRightPtr(), target);
        }
    }
    // else // root has 1 data item
    else {
        // if target < root data
        if(target < root->getSmVal()) {
            // return find(root->left, target
            return Find(root->getLeftPtr(), target);
        }
        // else
        else {
            // return find(root->right, target
            return Find(root->getRightPtr(), target);
        }
    }
    //return -1;
}

std::shared_ptr<Node> Index::findNode(std::shared_ptr<Node> root, std::shared_ptr<std::string> &key) {
    if(root->isLeaf()) {
        return root;
    }
    // else if root has 2 keys
    else if (root->isTwoVal()) {
        if(root->getSmKey().compare(*key) < 0) {
            root->setParent(root);
            return findNode(root->getLeftPtr(), key);
        } else if(root->getLgKey().compare(*key) < 0) {
            root->setParent(root);
            return findNode(root->getMidPtr(), key);
        } else {
            root->setParent(root);
            return findNode(root->getRightPtr(), key);
        }
    }
    // else root has 1 key
    else {
        if(root->getSmKey().compare(*key) < 0) {
            root->setParent(root);
            return findNode(root->getLeftPtr(), key);
        } else {
            root->setParent(root);
            return findNode(root->getRightPtr(), key);
        }
    }

    return std::shared_ptr<Node>();
}

void Index::printTree(std::shared_ptr<Node> root, int indent) {
    if(root == nullptr) {
        return;
    }
    indent += COUNT;
    printTree(root->getRightPtr(), indent);
    std::cout << std::endl;
    for (int i = COUNT; i < indent; i++) {
        std::cout << " ";
    }
    //std::cout << root->getValue() << "\n"; // fix for multi node
    printTree(root->getLeftPtr(), indent);
}

void Index::print(std::shared_ptr<Node> &root) {
    printTree(root, 1);
}



