/**
// MY MY MY MY MY MY MY MY MY
// MY function test script MY
// MY MY MY MY MY MY MY MY MY
// Created by
// ©️ĥª®Ł¡ē↴ ™️
// MMMMMM       MMMMMM UUUUUU   UUUUUU     SSSSSSSS      TTTTTTTT /T|\TT    ©️
//  MMMMMMM   MMMMMMM   UUUU     UUUU    SSSSS  SSSSS    TTTTTTTTTTT T TT[
//  MMMM MMM MMM MMMM   UUUU     UUUU   SSSSS     SSSS   TT    TTT    T\|
//  MMMM  MMMMM  MMMM   UUUU     UUUU    SSSS        S   T     TTT    L \
//  MMMM   MMM   MMMM   UUUU     UUUU   S    SSSSS    S        TTT   T T
//  MMMM         MMMM   UUUU     UUUU   SS       SSSS  S       TTT  T  /|   |-
//  MMMM         MMMM   UUUU     UUUU   SSS      SSSSS         TTT    T - \    -
//  MMMM         MMMM    UUUUUUUUUUU  SS SSSS   SSSSS         TTTTT     \Z||/-=__I
// MMMMMM       MMMMMM    UUUUUUUUU   S  S SSSSSSSS          TTTTTTTT  TX\_|_T[|_T
//
// 01000011 01101000 01100001 01110010 01101100 01100101 01110011 00100000 01001010 01101111 01110011 01100101 01110000 01101000 00100000 01001101 01110101 01110011 01110100
* AVLTree.h
*/

#ifndef AVLTREE_H
#define AVLTREE_H
#include <string>

using namespace std;

class AVLTree {
public:
    using KeyType = std::string;
    using ValueType = size_t;

protected:
    class AVLNode {
    public:
        KeyType key;
        ValueType value;
        size_t height;
        size_t childCount;
        size_t currentNumChildren = 0;

        AVLNode* left;
        AVLNode* right;

        // 0, 1 or 2
        size_t numChildren() const;
        // true or false
        bool isLeaf() const;
        // number of hops to deepest leaf node
        size_t getHeight() const;


    };

public:

    private:
    AVLNode* root;

    /* Helper methods for remove */
    // this overloaded remove will do the recursion to remove the node
    bool remove(AVLNode*& current, KeyType key);
    // removeNode contains the logic for actually removing a node based on the numebr of children
    bool removeNode(AVLNode*& current);
    // You will implement this, but it is needed for removeNode()
    void balanceNode(AVLNode*& node);

};

#endif //AVLTREE_H
