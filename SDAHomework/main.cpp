#include <iostream>

using namespace std;

struct node {
    int node_key;
    node *left;
    node *right;
};

void init_bin_tree(node &*binT) {
    binT = nullptr;
}

node* allocate_data(int key) {
    node *t_data = new node;
    t_data->node_key = key;
    t_data->left = nullptr;
    t_data->right = nullptr;
    return t_data;
}

void insert_key(node &*cur, int key) {
    if(cur == nullptr)
        cur = allocate_data(key);
    if(cur->key > key)
        insert_key(cur->left, key);
    else if(cur->key < key)
        insert_key(cur->right, key);
}

int search_bin_tree(node *cur, int key, node &*found) {
    if(cur == NULL) {
        found = NULL;
        return 0;
    } else if(cur->node_key == key) {
        found = cur;
        return 1;
    }
    if(cur->key > key)
        insert_key(cur->left, key);
    else if(cur->key < key)
        insert_key(cur->right, key);
}

int find_max_key(node *cur) {
    if(cur->right != nullptr) find_max_key(cur->right);
    return cur->node_key;
}

//preordine
void parc_RSD(node *cur){
    if(cur != nullptr) {
        cout << cur->node_key << " ";
        parc_RSD(cur->left);
        parc_RSD(cur->right);
    }
}

//postordine
void parc_SDR(node *cur){
    if(cur != nullptr) {
        parc_SDR(cur->left);
        parc_SDR(cur->right);
        cout << cur->node_key << " ";
    }
}

//inordine
void parc_SRD(node *cur){
    if(cur != nullptr) {
        parc_SRD(cur->left);
        cout << cur->node_key << " ";
        parc_SRD(cur->right);
    }
}

void delete_node(node &*binT) {

}

int main() {

    return 0;
}
