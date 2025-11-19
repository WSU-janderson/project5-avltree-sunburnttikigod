/***
   * MY MY MY MY MY MY MY MY MY MY
   * MY AVLTree.h [header file] MY
   * MY MY MY MY MY MY MY MY MY MY
   * Created by
   * ©️ĥª®Ł¡ē↴ ™️
   * MMMMMM       MMMMMM UUUUUU   UUUUUU     SSSSSSSS      TTTTTTTT /T|\T /    ©️
   *  MMMMMMM   MMMMMMM   UUUU     UUUU    SSSSS  SSSSS    TTTTTTTTTT/ T T_ T
   *  MMMM MMM MMM MMMM   UUUU     UUUU   SSSSS     SSSS   TT    TTT  -X T\|
   *  MMMM  MMMMM  MMMM   UUUU     UUUU    SSSS        S   T     TTT    L \ X
   *  MMMM   MMM   MMMM   UUUU     UUUU   S    SSSSS    S        TTT   T T  L
   *  MMMM         MMMM   UUUU     UUUU   SS       SSSS  S       TTT  T  /|  T|-
   *  MMMM         MMMM   UUUU     UUUU   SSS      SSSSS         TTT    T - \  | -
   *  MMMM         MMMM    UUUUUUUUUUU  SS SSSS   SSSSS         TTTTT     \Z||/-=__I
   * MMMMMM       MMMMMM    UUUUUUUUU   S  S SSSSSSSS          TTTTTTTT  TX\_|_T[|_T
   *
   * 01000011 01101000 01100001 01110010 01101100 01100101 01110011
   * 01001010 01101111 01110011 01100101 01110000 01101000
   * 01001101 01110101 01110011 01110100
   * AVLTree.h
****/

#ifndef AVLTREE_H
#define AVLTREE_H
#include <string>
#include <vector>
#include <cmath>
#include <optional>

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

        AVLNode *left;
        AVLNode *right;

        // 0, 1 or 2
        size_t numChildren() const;

        // true or false
        bool isLeaf() const;

        // number of hops to deepest leaf node
        size_t getHeight() const;
    };

public:

private:
    AVLNode *root;
    vector<KeyType> keyList;
    size_t maxBalancedHeight;

    /*
     *  insert + its recursive helper declarations
    */
    bool insert(const std::string &key, size_t value);

    bool recursivelyInsert(AVLNode *&nodeIn, const std::string &key, size_t value);

    /*
     *  findRange + its recursive helper declarations
    */
    vector<std::string> findRange(const std::string &lowKey, const std::string &highKey) const;

    static void rangingRecursively(AVLNode *ranger, std::string &lowKey, const std::string &highKey,
                                   vector<std::string> *&tranges);

    /*
     *  get + its recursive helper declarations
    */
    std::optional<size_t> get(const std::string &key) const;

    std::optional<size_t> getRecursively(AVLNode *currentNode, const std::string &key) const;

    /*
     *  balancing function declarations
    */
    void balanceNode(AVLNode *&node);

    int getBalance(AVLNode *&node) const;

    void rotateLeft(AVLNode *&node);

    void rotateRight(AVLNode *&node);

    /* Helper methods for remove */
    // this overloaded remove will do the recursion to remove the node
    bool remove(AVLNode *&current, KeyType key);

    // removeNode contains the logic for actually removing a node based on the numebr of children
    bool removeNode(AVLNode *&current);

    size_t &AVLTree::operator[](const std::string &key);

    bool contains(const std::string &key) const;

    vector<KeyType> keys() const;

    AVLTree(const AVLTree &other);

    size_t size() const;

    size_t getMaxBalancedHeight();

    size_t getHeight() const;

    void operator=(const AVLTree &other);

    ~AVLTree();

    friend std::ostream &operator<<(ostream &os, const AVLTree &avlTree);
};

#endif //AVLTREE_H
