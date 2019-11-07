#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct node{
node *left;
node *right;
int data;
};

class bst
{
ofstream outFile;

public:
bst();
//Default constructor

void clear(node*n);
void destroy();
//Deconstructor

void inorderRecursion(node*n);

void preorderRecursion(node*n);

void postorderRecursion(node*n);

node* createNode(int data);
// This creates a node, puts the data in it, and sets the left and right to NULL

void insert(node*n, int data);
//This function inserts another number in the search tree

void add(int data);
//This function calls insert function

int maxDepth(node*n);
//this function may work?
void maxDepthRun();

void postorderprint();

void preorderprint();

void inorderprint();

private:
node* root;
};
