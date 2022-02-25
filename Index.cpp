//
// Created by dude on 2/8/22.
//

#include "Map.h"
#include "Node.h"
#include "Index.h"
#include <iostream>

#define COUNT 5

Index::Index() : root_{nullptr} {}

Index::~Index() = default;

void Index::Insert(std::shared_ptr<std::string> &key, int val) {
    std::shared_ptr<Map> newNode = std::make_shared<Map>(key, val);
    if(root_ == nullptr) {
        root_ = std::make_shared<Node>();
        //root_->insert(newNode);
    }
    // locate leafNode in which newItem belongs
    std::shared_ptr<Node> curr = findNode(key);
    // add newItem to leafNode
    if(curr->insert(newNode)) {
        return;
    }
    //if leafNode has 3 items
    if(curr->toSplit()) {
        split(curr);
    }
    //print(root_);
}

void Index::split(std::shared_ptr<Node> node) {
// Splits node n, which contains 2 items (if n not leaf, has 4 children
    // split(n: 2-3Node
    std::shared_ptr<Node> parent;
    // if n is not root
    if(node != root_) {
        // let p be parent of n
        parent = node->getParent();
    } else {
        //else
        // create new node p
        root_ = parent = std::make_shared<Node>();
    }
    // replace node n w/ 2 nodes, n1 and n2, so p is their parent
    std::shared_ptr<Node> n1 = std::make_shared<Node>();
    std::shared_ptr<Node> n2 = std::make_shared<Node>();
    //if(parent != root_) {
    parent->replace(node, n1, n2);
   // }
    n1->setParent(parent);
    n2->setParent(parent);
    // give n1 the item in n w/ smallest val
    n1->setSm(node->getSm());
    // give n2 item in n with largest val
    n2->setSm(node->getLg());
    // if n is not leaf
    if(!node->isLeaf()) {
        // n1 becomes parent of n's 2 leftmost children
        n1->setAlpha(node->getAlpha());
        n1->setBravo(node->getBravo());
        // n2 becomes parent of n's 2 rightmost children
        n2->setAlpha(node->getCharlie());
        n2->setBravo(node->getDelta());
    }
    // move the item in n that has mid value up to p
    parent->insert(node->getMed());
    // if p now has 3 items
    if(parent->toSplit()) {
        // split(p)
        split(parent);
    }
}

std::shared_ptr<Node> Index::findNode(std::shared_ptr<std::string> &key) {
    std::shared_ptr<Node> curr = root_;
    while(!curr->isLeaf() && !curr->contains(key)) {
        if(curr->isThreeNode()) {
            if(curr->getMed()->compare(key) < 0) {
                curr = curr->getCharlie();
                continue;
            }
        }
        // two node, so no C
        if(curr->getSm()->compare(key) < 0) {
            curr = curr->getBravo();
        } else {
            curr = curr->getAlpha();
        }
    }
    // either not in tree or leaf where key should go
    return curr;
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

int Index::Find(std::shared_ptr<std::string> &key) {
    std::shared_ptr<Node> node = findNode(key);
    std::shared_ptr<Map> newMap = node->get(key);
    if(newMap == nullptr) {
        return -1;
    }
    return newMap->getVal();
}

void Index::printTree(std::shared_ptr<Node> root, int indent) {
    if(root == nullptr) {
        return;
    }
    indent += COUNT;
    printTree(root->getBravo(), indent);
    std::cout << std::endl;
    for (int i = COUNT; i < indent; i++) {
        std::cout << " ";
    }
    if(root->isThreeNode()) {
        std::cout << root->getSm() << " | " << root->getMed() << "\n";
    } else {
        std::cout << root->getSm() << "\n"; // fix for multi node
    }
    printTree(root->getAlpha(), indent);
}

void Index::print(std::shared_ptr<Node> &root) {
    printTree(root, COUNT);
}

std::shared_ptr<Node> Index::getRoot() const {
    return root_;
}

void Index::fixTree(std::shared_ptr<Node>, std::shared_ptr<Node>) {
    // if(n == root
        //delete root
    //else
        //let p be parent of n
        //if(some sibling of n has two vals
            // distribute items appropitaely among n, sibling and p
            // if(n != isLeaf
                // move appropriate child from sibling to n
        // else
            //choose adjacent sibling s of n
            // bring appropriate item down from p into s
            // if(n != leafNode
                    // move n's child to s
            // remove node n
            // if(p now empty)
                 // fixTree(p)
}




