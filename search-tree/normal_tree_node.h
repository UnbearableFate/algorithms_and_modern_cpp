#pragma once
#include <memory>
#include <vector>
using namespace std;
template<typename T>
class normal_tree_node;

template<typename T>
using p2n = shared_ptr<normal_tree_node<T>>; // means pointer to tree node;

template<typename T>
class normal_tree_node {
private:
    int key;
    shared_ptr<T> value;
    p2n parent, left, right;
public:
    normal_tree_node(/* args */) = default;
    normal_tree_node(p2n pa = nullptr, p2n le = nullptr,
    p2n ri = nullptr): parent(pa), left(le), right(ri) {}
    ~normal_tree_node();
    const int& getKey();
    void setKey(int k);
    const T& getValue();
    shared_ptr<T> getP2Value();
    void setValue(const T& v);
};

template<typename T>
class baseTree {
private:
    
    void recur_walk(shared_ptr<normal_tree_node> x) {
        if (x != nullptr) {
            recur_walk(x->left);
            // do someting
            recur_walk(x->right);
        }
    }
protected:
    p2n root;
public:
    baseTree(p2n ro = nullptr) : root(ro) {}
    vector<T> walk();
    virtual p2n insert(int key, T value);
    virtual void remove(int key);
    virtual p2n find(int key);
    virtual T get(int key); // return the value of 
};
