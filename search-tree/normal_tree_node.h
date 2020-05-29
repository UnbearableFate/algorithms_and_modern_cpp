#pragma once
#include <memory>
using namespace std;
template<typename T>
class normal_tree_node
{
private:
    using p2n = shared_ptr<normal_tree_node<T>>; // means pointer to tree node;
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
    protected:
    using p2n = shared_ptr<normal_tree_node<T>>; 
    p2n root;
    public:
    baseTree(p2n ro = nullptr) : root(ro) {}
    virtual p2n insert(int key, T value);
    virtual void remove(int key);
    virtual p2n find(int key);
    virtual T get(int key); // return the value of 
};
