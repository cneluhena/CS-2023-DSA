#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left; 
  struct node *right;
};

//creating a node
struct node *createNode(int val) {
   node* newnode = new node;
   newnode->key = val;
   newnode->left = newnode->right = NULL;
   return newnode;
}

// Inorder traversal
void inOrder(struct node *root) {
  if (root != NULL) {
    inOrder(root->left); //traversing left subtree
    cout << root->key << " ";
    inOrder(root->right); // travsersing right subtree
  }
}

struct node *insertNode(struct node *node, int key) {
  
  //if tree is empty create node
  if (node == NULL) 
    return createNode(key);
  
  //insert node in the correct place
  if (key < node->key) {
    node->left = insertNode(node->left, key);
  } else if (key > node->key) {
    node->right = insertNode(node->right, key);
  }

  
  return node;
}



// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  
  
  //if tree is empty no node to delete
  if (root == NULL) {
    return root;
  }


  if (key < root->key) {
    root->left = deleteNode(root->left, key);
  } else if (key > root->key) {
    root->right = deleteNode(root->right, key);
  } else { 

    if (root->left == NULL && root->right == NULL) {
      delete root;
      root = NULL;
    }
    
    else if (root->left == NULL) {
      struct node *temp = root;
      root = root->right;
      delete temp;
    } else if (root->right == NULL) {
      struct node *temp = root;
      root = root->left;
      delete temp;
    }



    else {
      struct node *temp = root->right;
      while (temp->left != NULL) {
        temp = temp->left;
      }
      root->key = temp->key;
      root->right = deleteNode(root->right, temp->key);
    }
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
  
  inOrder(root);
}
