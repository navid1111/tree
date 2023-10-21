#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node
{
	int data;
	struct node *left , *right;

};

struct node * newNode(int data) {
	struct node * node = (struct node * ) malloc(sizeof(struct node));
	node -> data = data;
	node -> left = NULL;
	node -> right = NULL;

	return (node);
}

int main() {

	struct node * root = newNode(1);
	root -> left = newNode(2);
	root -> left -> left = newNode(4);
	root -> left -> right = newNode(10);
	root -> left -> left -> right = newNode(5);
	root -> left -> left -> right -> right = newNode(6);
	root -> right = newNode(3);
	root -> right -> left = newNode(9);
	root -> right -> right = newNode(10);
	vector < vector < int > > verticalTraversal;


}
