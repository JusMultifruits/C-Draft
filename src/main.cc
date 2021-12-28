#include <iostream>

struct node {
  int value;
  node* left;
  node* right;
};

node* newNode(int data){
  struct node* node = (struct node*) malloc(sizeof(node));
  node->value = data;
  node->left = NULL;
  node->right = NULL;

  return node;
}

void showTree(node* root){
  if (root != NULL){
    std::cout << root->value << std::endl;
    showTree(root->left);
    showTree(root->right);
  }
}

void freeTree(node* n){
  if (n != NULL){
    freeTree(n->left);
    freeTree(n->right);
    free(n);
  }
}

int main(int argc, char* argv[]){
  std::cout << "Hello, World!" << std::endl;
  std::cout << argc << std::endl;
  std::cout << argv[0] << std::endl;

  struct node* node = newNode(1);
  node->left = newNode(2);
  node->right = newNode(3);
  node->left->right=newNode(4);

  showTree(node);
  freeTree(node);
  return 0;
}
