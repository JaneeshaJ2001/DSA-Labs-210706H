#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root == NULL) return;

  traverseInOrder(root->left);
  cout << root->key << " ";
  traverseInOrder(root->right);
}

//here we create a new node and return it

struct node *getNewNode(int data){
  node* newNode = new node();
  newNode->key = data;
  newNode->right = newNode->left = NULL;
  return newNode;
}

// Insert a node

struct node *insertNode(struct node *root, int key) {
  if (root == NULL){    //if the tree is empty we create a new node and return it
    root = getNewNode(key);
  }
  //here if the key is less or equal to the value of root node then we go and check it's left sub tree and insert it
  else if (key <= root->key){  
    root->left = insertNode(root->left, key);
  }
  //here if the key is less or equal to the value of root node then we go and check it's left sub tree and insert it
  else{
    root->right = insertNode(root->right, key);
  }
  return root;
}

//this function returns the address of node which has the minimum key of a BST by calling recursively

struct node *getMin (struct node *root){
  struct node* temp = root;
  while (temp && temp->left != NULL){
    temp = temp->left;
    }
	return temp;
}


struct node* deleteNode(struct node* root, int key){

	if (root == NULL)  //this is the base case
		return root;
    // if the key to be deleted is lesser than the root we have to travel to the root->left
	if (key < root->key){
        root->left = deleteNode(root->left, key);
    }
    // if the key to be deleted is greater  than the root we have to travel to the root->right
	else if (key > root->key){
        root->right = deleteNode(root->right, key);
    }
    //here we have the node which should be deleted
	else { //key is not the root->left or root->right , then it is same as the root
		// node has no child
		if (root->left == NULL && root->right == NULL)
			return NULL;

		// node with only one child or no child
		else if (root->left == NULL) {
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			struct node* temp = root->left;
			free(root);
			return temp;
		}

		// node with two children: Get the inorder successor
		// (smallest in the right subtree)
		struct node* temp = getMin(root->right);
		root->key = temp->key;
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}


// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}