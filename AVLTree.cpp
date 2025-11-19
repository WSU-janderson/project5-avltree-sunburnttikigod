/***
   * MY MY MY MY MY MY MY MY MY MY
   * MY AVLTree.cpp [c source]  MY
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
   * AVLTree.cpp
****/

#include "AVLTree.h"

#include <memory>
#include <string>
#include <vector>
#include <optional>
/*My biggest hold up here was trying to figure out the recursive logic,
 *not the base case, but rather the initial check and creation of my tree and
 *travesal node I finally think i found the structure that works, did some rucursion practice
 *on coding bat, and remembered what one of the kids asked in class about
 *using a helper function for the recursion.  so I will verify my traveler and
 *create/assign if needed then isolate the recursion to it's own function, so
 *I don't have to worry about 'stacking' nodes
 *
 */

bool AVLTree::insert(const std::string &key, size_t value) {
    // check's for root nodes existence / contents not assigned
    // this is for the first value in the tree
    if (!root) {
        root = new AVLNode(key, value); // assign root's key/value
        return true; //return type bool - successful insert = true
    }
    recursivelyInsert(root, key, value);
}

bool AVLTree::recursivelyInsert(AVLNode *&nodeIn, const std::string &key, size_t value) {
    //Since the other function takes care of the initial value situation
    //this one can headline with the base case
    if (!nodeIn) {
        //if node is null make new node and assign key&value
        nodeIn = new AVLNode(key, value);
        return true; //return true
    }
    //if key is less than, fall left
    if (key < nodeIn->key) {
        recursivelyInsert(nodeIn->left, key, value);
    }
    //if key is greater than fall right
    else if (key > nodeIn->key) {
        recursivelyInsert(nodeIn->left, key, value);
    }
    // This means theres a dupe so return false
    else {
        nodeIn->value = value;
        return false;
    }
    keyList.push_back(key);
    balanceNode(nodeIn);
}

//now to redo this mess with the same technique i used with insert
// i guess like a init and a recurse function

vector<std::string> AVLTree::findRange(const std::string &lowKey, const std::string &highKey) {
    vector<std::string> *rangeList = new vector<std::string>;
    rangingRecursively(root, lowKey, highKey, rangeList);
    return *rangeList;
}

void AVLTree::rangingRecursively(AVLNode *ranger, std::string &lowKey,
             const std::string &highKey, vector<std::string> *&rangeList) {

    //base case -> if it's at the end of the branch !//HOPPING_NODE_NAME// then return
    if (!ranger) {
        return;
    }        //if key is greater than fall right

    //if travelling node key is greater than lowKey add and higher than highKey
    if (ranger->key > lowKey && ranger->key < highKey) {
        rangeList->push_back(ranger->value);      //add it to the node list
    }
    //traversal logic
    if (ranger->key < lowKey) {
        rangingRecursively(ranger->left,lowKey, highKey, rangeList);
    }
    else if (ranger->key < highKey) {
        rangingRecursively(ranger->left,lowKey, highKey, rangeList);
    }
}


std::optional<size_t> AVLTree::get(const std::string &key) const {
    //key in hand 🎶🎶skip the the node my darling🎵🎵
    if (AVLNode *current = root; current == nullptr) {
        current = root;
    } else {
        if (current->isLeaf()) {
            return nullopt;
        }
        if (current->key == key) {
            return current->value;
        } else if (key < current->key && current->left != nullptr) {
            current = current->left;
            get(&key);
        } else if (key > current->key && current->right != nullptr) {
            current = current->right;
            get(&key);
        } else {
            return nullopt;
        }
    }
}


size_t AVLTree::size() const {
    return this->keys().size();
}

//uses math.h log2(n) and ceil to round up to get the ideal max height of the tree
size_t AVLTree::getMaxBalancedHeight() {
    AVLTree::maxBalancedHeight = ceil(log2(size()));
    return maxBalancedHeight;
}

//but this was interesting in 2917 - 2920 some DR really
//wanted credit for it, i didn't think Euler new C++ lol
/*   ------
// DR 568.          <-this line specifically
constexpr _Float32
log2(_Float32 __x)
{ return __builtin_log2f(__x); }
*  ------
*/

size_t &AVLTree::operator[](const std::string &key);

bool AVLTree::contains(const std::string &key) const {
}

size_t AVLTree::AVLNode::numChildren() const {
    return (this->isLeaf() ? 0 : (this->right && this->left) ? 2 : 1);
    // if is leaf return zero else if right exists and left exists, return 2 else return 1
}

bool AVLTree::AVLNode::isLeaf() const {
    return (!this->left && !this->right);
}

size_t AVLTree::AVLNode::getHeight() const {
    return this->height;
}

vector<std::string> AVLTree::keys() const {
    return this->keyList;
}

bool AVLTree::removeNode(AVLNode *&current) {
    if (!current) {
        return false;
    }

    AVLNode *toDelete = current;
    auto nChildren = current->numChildren();
    if (current->isLeaf()) {
        current = nullptr;
    } else if (current->numChildren() == 1) {
        // case 2 - replace current with its only child
        if (current->right) {
            current = current->right;
        } else {
            current = current->left;
        }
    } else {
        // case 3 - we have two children,
        // get smallest key in right subtree by
        // getting right child and go left until left is null
        AVLNode *smallestInRight = current->right;
        // I could check if smallestInRight is null,
        // but it shouldn't be since the node has two children
        while (smallestInRight->left) {
            smallestInRight = smallestInRight->left;
        }
        std::string newKey = smallestInRight->key;
        int newValue = smallestInRight->value;
        remove(root, smallestInRight->key); // delete this one
        //remove will start the thread from root with 'smallest in Right' key in hand
        //hop down ask is greater or less than each node and respond accordingly left or right,
        //to my understanding, return false if never found, so is removeNode supposed to be a
        //public function with remove used under the hood as a privbate function
        //here or should i just ignore those details, also with the vector representation available to
        //us ...nvm
        current->key = newKey;
        current->value = newValue;

        current->height = current->getHeight();
        balanceNode(current);

        return true; // we already deleted the one we needed to so return
    }
    delete toDelete;

    return true;
}

/*bool AVLTree::remove(AVLNode *&current, KeyType key) {
    return false;
}*/

void AVLTree::balanceNode(AVLNode *&node) {
    //Goin fishin
    //I keep thinking that if i could use one complete traversal to count the size of the tree, I could then set a goal
    //height for each branch by using a root 2 on the size to get the target height. following this any branch that is
    //larger than the target you stop at the target height for the branch and go fishing until you've got nothing left
    //to hook (null pointer) using inorder to count (left to right) and postorder(right to left) so it's one natural
    //traversal to balance, remove and insert as your operations for balancing.
    AVLNode *highestNode;

    //this serves as the search function, holding on to the pointer for the most out of balance node (highest)
    !node->isLeaf()
        ? (node->getHeight() > highestNode->getHeight()
               ? highestNode = node
               : (node->right ? node = node->right : node = node->left))
        : els
    else
    if () {
        //
        //current!=lastRemovedNode ?
        //      lastRemovedNode = current
        //      insert(remove(lastRemovedNode) : insert(remove(N;
    }


    void operator=(const AVLTree &other)
    {
    }

    ~AVLTree();

    friend std::ostream &operator<<(ostream &os, const AVLTree &avlTree);
}
