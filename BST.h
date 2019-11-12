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
bst();
//Default constructor

void clear(node*n);
void destroy();
//Deconstructor

void inorderRecursion(node*n);
void preorderRecursion(node*n);
void postorderRecursion(node*n);
void postorderprint();
void preorderprint();
void inorderprint();
void show(int);
void print(node*,int);
node* createNode(int data);
// This creates a node, puts the data in it, and sets the left and right to NULL

node* insert(node*n, int data);
//This function inserts another number in the search tree

void printTree(node*n);

void add(int data);
//This function calls insert function

int height(node*n);
//this function gets the height of a node

int balanceFactor(node*n);
//this function gets the balance factor (left - right)
node* balance(node*n);
//this function performs the correct balance rotation
node* LeftRotate(node*n);
node* RightRotate(node*n);




private:
node* root;
};
