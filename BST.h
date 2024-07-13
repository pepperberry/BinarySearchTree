//BST.h
//2/6/2024
//BinarySearchTree
//pepper berry
#include ream>
#include ing>
#include eam>

using namespace std;


template <typename T>
class BST{
    public:
        BST();
        ~BST();
        void insert(T);
        string contains(T);
        void remove(T);
        bool empty();
        int size();
        int getLeafCount();
        int getHeight();
        int getLevel(T);
        string getInOrderTraversal();
        string getPreOrderTraversal();
        string getPostOrderTraversal();
        string getAncestors(T);
        BST(const BST &obj);
        BST& operator=(const BST &obj);
    private:
        struct Node{
            Node * right;
            Node * left;
            T data;
        };
        Node * root;

        void destructor(Node *&ptr);
        void displayInOrder(Node *ptr, string &str, string var);
        void displayInOrder(Node *ptr, string &str, int var);
        void displayPreOrder(Node *ptr, string &str, int var);
        void displayPreOrder(Node *ptr, string &str, string var);
        void displayPostOrder(Node *ptr, string &str, int var);
        void displayPostOrder(Node *ptr, string &str, string var);
        void insert(Node *& ptr, Node *&newNode);
        bool contains(T num, Node *& ptr);
        void remove(Node *&ptr, T item);
        void makeDeletion(Node *&ptr, T item);
        void size(Node *ptr, int &num);
        void getLeafCount(Node *ptr, int &num);
        void getHeight(Node *ptr, int num, int &height);
        void getLevel(Node *ptr, int num, int &height, T key);
        void getAncestors(Node *ptr, string str, string &ansestors, int key);
        void getAncestors(Node *ptr, string str, string &ansestors, string key);
        void copy(Node *& objPtr);



};
//Constructor - Creates an empty BST of given element types.
template <typename T>
BST<T>::BST(){
    root = nullptr;
}

//Destructor - Removes all elements from the BST.
template <typename T>
BST<T>::~BST() {
   destructor(root);
}


//Copy constructor - Create a copy of the BST passed in as a parameter.
template <typename T>
BST<T>::BST(const BST<T> &obj) {
    this->root = nullptr;
    Node * objroot = obj.root;
    copy(objroot);
}


template <typename T>
void BST<T>::copy(Node *& objPtr) {
    if(objPtr != nullptr) {
        this->insert((objPtr->data));
        copy(objPtr-> left);
        copy(objPtr-> right);
    }
}

//Overloaded assignment operator - Assigns the BST passed in as a parameter to an existing BST.
template <typename T>
BST<T>& BST<T>::operator=(const BST<T> &obj) {
    if (this != &obj) {
        // deallocate memory
        this->~BST();
        this->root = nullptr;
        Node * objroot = obj.root;
        copy(objroot);
    }
    return *this;
}




template <typename T>
void BST<T>::destructor(Node *&ptr) {
    if (ptr != nullptr) {
       destructor(ptr->left);
       destructor(ptr->right);
       delete ptr;
    }
   ptr = nullptr;
}

//Inserts the element passed in as a parameter into the BST. Assume no duplicate datas. Must use recursion.
template <typename T>
void BST<T>::insert(T num){
    Node * newNode = new Node;
    newNode->data = num;
    newNode->left = newNode->right = nullptr;

    // insert the node
    insert(root, newNode);
}

template <typename T>
void BST<T>::insert(Node *& ptr, Node *&newNode) {
   if (ptr == nullptr)
      ptr = newNode;
   else if (ptr->data > newNode->data)
      insert(ptr->left, newNode);
   else
      insert(ptr->right, newNode);
}

//Searches the BST to determine if a given data is present. Returns true if so, else false. Must use recursion.
template <typename T>
string BST<T>::contains(T num){
    if (contains(num, root) == true){
        return "true";
    }else{
        return "false";
    }

}

template <typename T>
bool BST<T>::contains(T num, Node *& ptr){
    if (ptr != nullptr) {
        if (ptr->data == num){
            return true;
        }else if (ptr->data > num){
            return contains(num, ptr->left);
        }else{
            return contains(num, ptr->right);
        }
    }
    return false;

}

//Removes the specified data from the BST.
template <typename T>
void BST<T>::remove(T num){
    remove(root, num);
}

template <typename T>
void BST<T>::remove(Node *&ptr, T item) {
    if (ptr != nullptr) {
        if (ptr->data > item){
            remove(ptr->left, item);
        }else if (ptr->data < item){
            remove(ptr->right, item);
        }else if(ptr->data == item){
            makeDeletion(ptr, item);
        }
    }
}

template <typename T>
void BST<T>::makeDeletion(Node *&ptr, T item) { // note: ptr is the node to delete
   Node *curr = nullptr;
   if (ptr != nullptr) {
        if (ptr->left == nullptr) {
            curr = ptr;
            ptr = ptr->right;
            delete curr;
        } else if (ptr->right == nullptr) {
            curr = ptr;
            ptr = ptr->left;
            delete curr;
        } else {
            curr = ptr->right;                // find inorder successor
            while (curr->left != nullptr){     // go right once; then go left until nullptr
                curr = curr->left;
                ptr->data = curr->data ;         // replace data with inorder successor data
            }
            remove(ptr->right, curr->data);  // call remove again to delete replaced node
        }
   }
}

//checks if BST is empty
template <typename T>
bool BST<T>::empty(){
    return (root == nullptr);
}

//Returns the count of nodes in the BST.
template <typename T>
int BST<T>::size(){
    int num = 0;
    size(root, num);
    return num;

}

template <typename T>
void BST<T>::size(Node *ptr, int &num) {
    if (ptr != nullptr) {
        ++num;
        size(ptr->left, num);
        size(ptr->right, num);
    }
}

//Returns the count of nodes in the BST that do not have any children.
template <typename T>
int BST<T>::getLeafCount(){
    int num = 0;
    getLeafCount(root, num);
    return num;
}

template <typename T>
void BST<T>::getLeafCount(Node *ptr, int &num) {
    if (ptr != nullptr) {
        getLeafCount(ptr->left, num);
        getLeafCount(ptr->right, num);
        if(ptr->left == nullptr && ptr->right == nullptr){
            ++num;
        }
    }
}

// Returns height of the BST. The height is the number of levels it contains.
template <typename T>
int BST<T>::getHeight(){
    int height = 0;
    getHeight(root, 0, height);
    return height;
}


template <typename T>
void BST<T>::getHeight(Node *ptr, int num, int &height) {
    if (ptr != nullptr) {
        ++num;
        getHeight(ptr->left, num, height);
        getHeight(ptr->right, num, height);
    }
    height = num;
}
/*
template <typename T>
void BST<T>::getHeight(Node *ptr, int num, int &height) {
    if (ptr != nullptr) {
        ++num;
        getHeight(ptr->left, num, height);
        getHeight(ptr->right, num, height);
    }
    if(num > height){
        height = num;
    }

}
*/


//Returns the level of a node in the BST. If the node with the given data is not present in the BST, returns -1.
template <typename T>
int BST<T>::getLevel(T num){
    int height = 0;
    getLevel(root, -1, height, num);
    return height;

}


template <typename T>
void BST<T>::getLevel(Node *ptr, int num, int &height, T key){
    if (ptr != nullptr) {
        ++num;
        if(ptr->data == key){
            if(num > height){
                height = num;
            }
        }else{
            getLevel(ptr->left, num, height, key);
            getLevel(ptr->right, num, height, key);
        }

    }


}


//Returns a string of elements in the order specified by the in-order traversal of the BST. Must use recursion.
template <typename T>
string BST<T>::getInOrderTraversal(){
    string str = "";
    T var = root->data;
    displayInOrder(root, str, var);
    return str;

}


template <typename T>
void BST<T>::displayInOrder(Node *ptr, string &str, int var) {
    if (ptr != nullptr) {
        displayInOrder(ptr->left, str, var);
        str += to_string(ptr->data);
        str += " ";
        displayInOrder(ptr->right, str, var);
    }
}

template <typename T>
void BST<T>::displayInOrder(Node *ptr, string &str, string var) {
    if (ptr != nullptr) {
        displayInOrder(ptr->left, str, var);
        str += ptr->data;
        str += " ";
        displayInOrder(ptr->right, str, var);
    }
}

//Returns a string of elements in the order specified by the pre-order traversal of the BST. Must use recursion.
template <typename T>
string BST<T>::getPreOrderTraversal(){
    string str = "";
    T var = root->data;
    displayPreOrder(root, str, var);
    return str;
}

template <typename T>
void BST<T>::displayPreOrder(Node *ptr,string &str, int var) {
    if (ptr != nullptr) {
        str += to_string(ptr->data);
        str += " ";
        displayPreOrder(ptr->left, str, var);
        displayPreOrder(ptr->right, str, var);
    }
}

template <typename T>
void BST<T>::displayPreOrder(Node *ptr,string &str, string var) {
    if (ptr != nullptr) {
        str += ptr->data;
        str += " ";
        displayPreOrder(ptr->left, str, var);
        displayPreOrder(ptr->right, str, var);
    }
}
//Returns a string of elements in the order specified by the post-order traversal of the BST. Must use recursion.
template <typename T>
string BST<T>::getPostOrderTraversal(){
    string str = "";
    T var = root->data;
    displayPostOrder(root, str, var);
    return str;
}


template <typename T>
void BST<T>::displayPostOrder(Node *ptr, string &str, int var) {
    if (ptr != nullptr) {
        displayPostOrder(ptr->left, str, var);
        displayPostOrder(ptr->right, str, var);

        str += to_string(ptr->data);
        str += " ";
    }
}

template <typename T>
void BST<T>::displayPostOrder(Node *ptr, string &str, string var) {
    if (ptr != nullptr) {
        displayPostOrder(ptr->left, str, var);
        displayPostOrder(ptr->right, str, var);

        str += ptr->data;
        str += " ";
    }
}

//Returns a string of elements that are the ancestor(s) of the given node.
//The most immediate ancestor will be the first in the list. If the data is not present in the BST, returns an empty string.
template <typename T>
string BST<T>::getAncestors(T num){
    string str = "";
    string temp;
    getAncestors(root, temp ,str, num);
    return str;

}



template <typename T>
void BST<T>::getAncestors(Node *ptr, string str, string &ansestors, int key){
    if (ptr != nullptr) {
        if(ptr->data == key){
            ansestors = str;
        }else{
            str = to_string(ptr->data) + " " + str;
            getAncestors(ptr->left, str, ansestors, key);
            getAncestors(ptr->right, str, ansestors, key);
        }
    }

}

template <typename T>
void BST<T>::getAncestors(Node *ptr, string str, string &ansestors, string key){
    if (ptr != nullptr) {
        if(ptr->data == key){
            ansestors = str;
        }else{
            str = ptr->data + " " + str;
            getAncestors(ptr->left, str, ansestors, key);
            getAncestors(ptr->right, str, ansestors, key);
        }
    }

}





