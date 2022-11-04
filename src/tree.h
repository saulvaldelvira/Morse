#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <concepts>
#include <string>
using std::string;
using std::is_base_of;
template<class T, class Q>
concept Is_Base = is_base_of<T, Q>::value;
#endif 

#ifndef TREESTACKABLE_H
#define TREESTACKABLE_H
#include <string>
using std::string;
template<class T>
class TreeStackable
{
public:
	virtual int compareTo(T) = 0;
	virtual string toString() = 0;
};
#endif

#ifndef BSTREE_H
#define BSTREE_H

template <class T>
	requires Is_Base<TreeStackable<T>, T>
class BSTree
{
	//Struct for the node
	struct BSNode
	{
		T info;
		BSNode* left;
		BSNode* right;
		~BSNode() { //destructor
			delete left;
			delete right;
		}
	};

public:
	BSTree() : root(nullptr) {
	}
	~BSTree() {
		delete_tree(root);
	}

	void add(T element) {
		root = addR(root, element);
	}

	void remove(T element) {
		root = removeR(root, element);
	}

	bool exists(T element) {
		return existsR(element, root);
	}

	T get(T element) {
		return getR(root, element);
	}

	T getMax() {
		return getMaxR(root)->info;
	}

	T getMin() {
		return getMinR(root)->info;
	}

	//Recorridos
	string inOrder() {
		return inOrderR(root);
	}

	string preOrder() {
		return preOrderR(root);
	}

	string postOrder() {
		return postOrderR(root);
	}

private:
	BSNode* root;

	void delete_tree(BSNode* node) {
		delete root;
		root = nullptr;
	}

	BSNode* addR(BSNode* node, T element) {
		if (node == nullptr) {
			return new BSNode{ element, nullptr, nullptr };
		}
		int c = element.compareTo(node->info);
		if (c > 0)
			node->right = addR(node->right, element);
		else if (c < 0)
			node->left = addR(node->left, element);
		else
			return node;
		return node;
	}

	BSNode* removeR(BSNode* node, T element) {
		int c = element.compareTo(node->info);
		if (c > 0)
			node->right = removeR(node->right, element);
		else if (c < 0)
			node->left = removeR(node->left, element);
		else { //if we found the node to delete
			if (node->left != NULL) {//if exists left son
				BSNode* aux = getMaxR(node->left); //gets the highest node from the left
				T max = aux->info; //saves the info
				remove(aux->info); //removes that node
				node->info = max; //and overwrites the info from the node we are deleting with thas node's info
				return node;
			}
			else if (node->left != NULL) { //the same that we do with the left son, but with the smallest of the right nodes (only if there's no nodes to the left)
				BSNode* aux = getMinR(node->right);
				T min = aux->info;
				remove(aux->info);
				node->info = min;
				return node;
			}
			else { // if the node has no sons, just delete that node and return null
				delete node;
				return NULL;
			}
		}
		return node;
	}

	T getR(BSNode* node, T element) {
		if (node == NULL)
			return NULL;
		int c = element.compareTo(node->info);
		if (c > 0)
			return getR(node->right, element);
		else if (c < 0)
			return getR(node->left, element);
		else
			return node->info;
	}

	BSNode* getMaxR(BSNode* node) {
		if (node->right == NULL)
			return node;
		else return getMaxR(node->right);
	}

	BSNode* getMinR(BSNode* node) {
		if (node->left == NULL)
			return node;
		else return getMinR(node->left);
	}

	bool existsR(T element, BSNode* node) {
		if (node == nullptr)
			return false;
		int c = element.compareTo(node->info);
		if (c > 0)
			return existsR(element, node->right);
		else if (c < 0)
			return existsR(element, node->left);
		else
			return true;
	}

	//Recorridos
	string inOrderR(BSNode* node) {
		if (node == NULL)
			return "";
		return inOrderR(node->left) + "\t" + (node->info).toString() + "\t" + inOrderR(node->right);
	}

	string preOrderR(BSNode* node) {
		if (node == NULL)
			return "";
		return (node->info).toString() + "\t" + preOrderR(node->left) + "\t" + preOrderR(node->right);
	}

	string postOrderR(BSNode* node) {
		if (node == NULL)
			return "";
		return postOrderR(node->left); +"\t" + postOrderR(node->right) + "\t" + (node->info).toString();
	}

};
#endif

#ifndef AVLTREE_H
#define AVLTREE_H

template<class T>
	requires Is_Base<TreeStackable<T>, T>
class AVLTree {
	struct AVLNode {
		T info;
		int balanceFactor;
		int height;
		AVLNode* left;
		AVLNode* right;
		~AVLNode() { //destructor
			delete left;
			delete right;
		}
		void updateBFHeight() {
			int lHeight;
			if (left != NULL) lHeight = left->height;
			else lHeight = -1;

			int rHeight;
			if (right != NULL) rHeight = right->height;
			else rHeight = -1;

			balanceFactor = rHeight - lHeight;
			height = 1 + max(rHeight, lHeight);
		}
		int max(int r, int l) {
			if (r > l) return r;
			else return l;
		}
	};

public:
	AVLTree() : root(nullptr) {

	}

	~AVLTree() {
		delete_tree(root);
	}

	void add(T element) {
		root = addR(root, element);
	}

	void remove(T element) {
		root = removeR(root, element);
	}

	bool exists(T element) {
		return existsR(element, root);
	}

	T get(T element) {
		return getR(root, element);
	}

	T getMax() {
		return getMaxR(root)->info;
	}

	T getMin() {
		return getMinR(root)->info;
	}

	//Recorridos
	string inOrder() {
		return inOrderR(root);
	}

	string preOrder() {
		return preOrderR(root);
	}

	string postOrder() {
		return postOrderR(root);
	}

private:
	AVLNode* root;

	void delete_tree(AVLNode* node) {
		delete root;
		root = NULL;
	}

	AVLNode* addR(AVLNode* node, T element) {
		if (node == nullptr) {
			return new AVLNode{ element, 0, 0, nullptr, nullptr };
		}
		int c = element.compareTo(node->info);
		if (c > 0) {
			node->right = addR(node->right, element);
		}			
		else if (c < 0) {
			node->left = addR(node->left, element);
		}
		node = updateAndBalanceIfNecesary(node);
		return node;
	}

	AVLNode* removeR(AVLNode* node, T element) {
		int c = element.compareTo(node->info);
		if (c > 0)
			node->right = removeR(node->right, element);
		else if (c < 0)
			node->left = removeR(node->left, element);
		else { //if we found the node to delete
			if (node->left != NULL) {//if exists left son
				AVLNode* aux = getMaxR(node->left); //gets the highest node from the left
				T max = aux->info; //saves the info
				remove(aux->info); //removes that node
				node->info = max; //and overwrites the info from the node we are deleting with thas node's info
				return updateAndBalanceIfNecesary(node);
			}
			else if (node->left != NULL) { //the same that we do with the left son, but with the smallest of the right nodes (only if there's no nodes to the left)
				AVLNode* aux = getMinR(node->right);
				T min = aux->info;
				remove(aux->info);
				node->info = min;
				return updateAndBalanceIfNecesary(node);
			}
			else { // if the node has no sons, just delete that node and return null
				delete node;
				return NULL;
			}
		}
		return updateAndBalanceIfNecesary(node);
	}

	T getR(AVLNode* node, T element) {
		if (node == NULL)
			return NULL;
		int c = element.compareTo(node->info);
		if (c > 0)
			return getR(node->right, element);
		else if (c < 0)
			return getR(node->left, element);
		else
			return node->info;
	}

	AVLNode* getMaxR(AVLNode* node) {
		if (node->right == NULL)
			return node;
		else return getMaxR(node->right);
	}

	AVLNode* getMinR(AVLNode* node) {
		if (node->left == NULL)
			return node;
		else return getMinR(node->left);
	}

	bool existsR(T element, AVLNode* node) {
		if (node == nullptr)
			return false;
		int c = element.compareTo(node->info);
		if (c > 0)
			return existsR(element, node->right);
		else if (c < 0)
			return existsR(element, node->left);
		else
			return true;
	}

	//Balancin the tree
	AVLNode* updateAndBalanceIfNecesary(AVLNode* nodo) {
		nodo->updateBFHeight();
		if (nodo->balanceFactor == -2) {
			if (nodo->left->balanceFactor == 1)
				nodo = doubleLeftRotation(nodo);
			else
				nodo = singleLeftRotation(nodo);
		}
		else if (nodo->balanceFactor == 2) {
			if (nodo->right->balanceFactor == -1)
				nodo = doubleRightRotation(nodo);
			else
				nodo = singleRightRotation(nodo);
		}
		return nodo;
	}

	AVLNode* singleLeftRotation(AVLNode* node) {
		AVLNode* aux = node->left;
		node->left = aux->right;
		node->updateBFHeight();
		aux->right = node;
		aux->updateBFHeight();
		return aux;
	}

	AVLNode* doubleLeftRotation(AVLNode* node) {
		node->left = singleRightRotation(node->left);
		return singleLeftRotation(node);
	}

	AVLNode* singleRightRotation(AVLNode* node) {
		AVLNode* aux = node->right;
		node->right = aux->left;
		node->updateBFHeight();
		aux->left = node;
		aux->updateBFHeight();
		return aux;
	}

	AVLNode* doubleRightRotation(AVLNode* node) {
		node->right = singleLeftRotation(node->right);
		return singleRightRotation(node);
	}

	//Recorridos
	string inOrderR(AVLNode* node) {
		if (node == NULL)
			return "";
		return inOrderR(node->left) + "\t" + (node->info).toString() + "\t" + inOrderR(node->right);
	}

	string preOrderR(AVLNode* node) {
		if (node == NULL)
			return "";
		return (node->info).toString()+ "\t" + preOrderR(node->left) + "\t" + preOrderR(node->right);
	}

	string postOrderR(AVLNode* node) {
		if (node == NULL)
			return "";
		return postOrderR(node->left); +"\t" + postOrderR(node->right) + "\t" + (node->info).toString();
	}
};

#endif
