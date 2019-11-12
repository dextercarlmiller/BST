#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct node{
node *left;
node *right;
int data;
int height; 
};

class bst
{
public:
//Default constructor
    bst();
//Deconstructor
    void clear(node*n);
    void destroy();
//Print Functions
    void inorderRecursion(node*n);
    void preorderRecursion(node*n);
    void postorderRecursion(node*n);
    void postorderprint();
    void preorderprint();
    void inorderprint();
    void show(int);
    void print(node*,int);

// This creates a node, puts the data in it, and sets the left and right to NULL
    node* createNode(int data);
//This function calls insert function
    void add(int data);
    //insert returns the new root
    node* insert(node*n, int data);
//AVL Tree Functions
   //Balance determins what rotation to use, then rotates
   node* balance(node*n); 
    //BalanceFactor uses height to calculate the balance factor   
    int balanceFactor(node*n);
        int height(node*n);
    
    //Simple left and right rotations
    node* LeftRotate(node*n);
    node* RightRotate(node*n);
private:
node* root;
};
