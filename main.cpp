//main.cpp
//BinarySearchTree
//pepper berry
#include eam>
#include ing>
#include ream>


#include "BST.h"
using namespace std;

void readFile(BST<int> &a,string file);
void readFile(BST<string> &a,string file);
void intBST();
void stringBST();
int main(){
    cout << "Welcome this is a program showing my ability to code a binary search tree!"<<endl<<endl<<endl;
    intBST();
    stringBST();
    cout <<endl<<"Goodbye!";
    return 1;
}
void intBST(){
    string file;
    BST<int> a;
    cout <<"******************************"<<endl<<"* INTEGER BINARY SEARCH TREE *"<<endl<<"******************************"<<endl;
    cout <<endl<<"** CREATE BST **"<<endl;

    //amount of stuff
    cout<<"# of nodes:  "<<a.size()<<endl;
    cout <<"# of leaves: "<<a.getLeafCount()<<endl;//not correct
    cout <<"BST height:  "<<a.getHeight()<<endl;
    cout <<"BST empty?   ";
    bool var = a.empty();
    if(var){
        cout <<"true"<<endl;

    }else{
        cout <<"false"<<endl;
    }


    //read in content
    cout <<endl<< "Enter integer file: ";
    cin >> file;
    cout <<endl<<"** TEST INSERT **"<<endl;
    cout <<"inserting in this order: ";
    readFile(a, file);


    //amount of stuff
    cout <<"# of nodes:  "<<a.size()<<endl;
    cout <<"# of leaves: "<<a.getLeafCount()<<endl;
    cout <<"BST height:  "<<a.getHeight()<<endl;
   cout <<"BST empty?   ";
    var = a.empty();
    if(var){
        cout <<"true"<<endl;

    }else{
        cout <<"false"<<endl;
    }

    //traversals
    cout <<endl<<"** TEST TRAVERSALS **"<<endl;
    cout <<"pre-order:   "<<a.getPreOrderTraversal()<<endl;
    cout <<"in-order:    "<<a.getInOrderTraversal()<<endl;
    cout <<"post-order:  "<<a.getPostOrderTraversal()<<endl;

    //levels and ancestors
    cout <<endl<<"** TEST LEVEL & ANCESTORS **"<<endl;
    cout <<"level(40): "<< a.getLevel(40)<<", ancestors(40): "<<a.getAncestors(40)<<endl;
    cout <<"level(20): "<< a.getLevel(20)<<", ancestors(20): "<<a.getAncestors(20)<<endl;
    cout <<"level(10): "<< a.getLevel(10)<<", ancestors(10): "<<a.getAncestors(10)<<endl;
    cout <<"level(30): "<< a.getLevel(30)<<", ancestors(30): "<<a.getAncestors(30)<<endl;
    cout <<"level(60): "<< a.getLevel(60)<<", ancestors(60): "<<a.getAncestors(60)<<endl;
    cout <<"level(50): "<< a.getLevel(50)<<", ancestors(50): "<<a.getAncestors(50)<<endl;
    cout <<"level(70): "<< a.getLevel(70)<<", ancestors(70): "<<a.getAncestors(70)<<endl;


    //testing contains
    cout <<endl<<"** TEST CONTAINS **"<<endl;
    cout <<"contains(20): "<< a.contains(20)<<endl;
    cout <<"contains(40): "<< a.contains(40)<<endl;
    cout <<"contains(10): "<< a.contains(10)<<endl;
    cout <<"contains(70): "<< a.contains(70)<<endl;
    cout <<"contains(99): "<< a.contains(99)<<endl;
    cout <<"contains(-2): "<< a.contains(-2)<<endl;
    cout <<"contains(59): "<< a.contains(59)<<endl;
    cout <<"contains(43): "<< a.contains(43)<<endl;



    //testing after remove
    cout <<endl<<"** TEST REMOVE **"<<endl;
    cout <<"Removing in this order: 20 40 10 70 99 -2 59 43"<<endl;
    a.remove(40);
    a.remove(10);
    a.remove(70);
    a.remove(99);
    a.remove(-2);
    a.remove(59);
    a.remove(43);
    a.remove(20);

    //amount of stuff
    cout <<"# of nodes:  "<<a.size()<<endl;
    cout <<"# of leaves: "<<a.getLeafCount()<<endl;
    cout <<"BST height:  "<<a.getHeight()<<endl;
    cout <<"BST empty?   ";
    var = a.empty();
    if(var){
        cout <<"true"<<endl;

    }else{
        cout <<"false"<<endl;
    }
    cout <<"pre-order:   "<<a.getPreOrderTraversal()<<endl;
    cout <<"in-order:    "<<a.getInOrderTraversal()<<endl;
    cout <<"post-order:  "<<a.getPostOrderTraversal()<<endl;



    //inserting again
    cout <<endl<<"** TEST INSERT (again) **"<<endl;
    cout <<"Inserting in this order: 20 40 10 70 99 -2 59 43"<<endl;//the insert is not working may be due to r3emove not working
    a.insert(20);
    a.insert(40);
    a.insert(10);
    a.insert(70);
    a.insert(99);
    a.insert(-2);
    a.insert(59);
    a.insert(43);

    //amount of stuff
    cout <<"# of nodes:  "<<a.size()<<endl;
    cout <<"# of leaves: "<<a.getLeafCount()<<endl;
    cout <<"BST height:  "<<a.getHeight()<<endl;
    cout <<"BST empty?   ";
    var = a.empty();
    if(var){
        cout <<"true"<<endl;

    }else{
        cout <<"false"<<endl;
    }

    //traversals
    cout <<"pre-order:   "<<a.getPreOrderTraversal()<<endl;
    cout <<"in-order:    "<<a.getInOrderTraversal()<<endl;
    cout <<"post-order:  "<<a.getPostOrderTraversal()<<endl;


}


void stringBST(){
    string file;
    //string BST
    BST<string> b;
    cout <<endl<<endl<<"*******************"<<endl<<"* test string BST *"<<endl<<"*******************"<<endl;
    cout <<endl<<"** CREATE BST **"<<endl;

    //amount of stuff
    cout <<"# of nodes:  "<<b.size()<<endl;
    cout <<"# of leaves: "<<b.getLeafCount()<<endl;
    cout <<"BST height:  "<<b.getHeight()<<endl;
    cout <<"BST empty?   ";
    bool var = b.empty();
    if(var){
        cout <<"true"<<endl;

    }else{
        cout <<"false"<<endl;
    }

    //read in content
    cout <<endl<< "Enter string file: ";
    cin >> file;
    cout <<endl<<"** TEST INSERT **"<<endl;
    cout <<"inserting in this order: ";
    readFile(b, file);


    //amount of stuff
    cout <<"# of nodes:  "<<b.size()<<endl;
    cout <<"# of leaves: "<<b.getLeafCount()<<endl;
    cout <<"BST height:  "<<b.getHeight()<<endl;
    cout <<"BST empty?   ";
    var = b.empty();
    if(var){
        cout <<"true"<<endl;

    }else{
        cout <<"false"<<endl;
    }

    //traversals
    cout <<endl<<"** TEST TRAVERSALS **"<<endl;
    cout <<"pre-order:   "<<b.getPreOrderTraversal()<<endl;
    cout <<"in-order:    "<<b.getInOrderTraversal()<<endl;
    cout <<"post-order:  "<<b.getPostOrderTraversal()<<endl;



    //levels and ancestors
    cout <<endl<<"** TEST LEVEL & ANCESTORS **"<<endl;

    cout <<"level(mary): "<< b.getLevel("mary")<<", ancestors(mary): "<<b.getAncestors("mary")<<endl;
    cout <<"level(gene): "<< b.getLevel("gene")<<", ancestors(gene): "<<b.getAncestors("gene")<<endl;
    cout <<"level(bea): "<< b.getLevel("bea")<<", ancestors(bea): "<<b.getAncestors("bea")<<endl;
    cout <<"level(jen): "<< b.getLevel("jen")<<", ancestors(jen): "<<b.getAncestors("jen")<<endl;
    cout <<"level(sue): "<< b.getLevel("sue")<<", ancestors(sue): "<<b.getAncestors("sue")<<endl;
    cout <<"level(pat): "<< b.getLevel("pat")<<", ancestors(pat): "<<b.getAncestors("pat")<<endl;
    cout <<"level(uma): "<< b.getLevel("uma")<<", ancestors(uma): "<<b.getAncestors("uma")<<endl;



    //testing contains
    cout <<endl<<"** TEST CONTAINS **"<<endl;
    cout <<"contains(gene):"<< b.contains("gene")<<endl;
    cout <<"contains(mary):"<< b.contains("mary")<<endl;
    cout <<"contains(bea):"<< b.contains("bea")<<endl;
    cout <<"contains(uma):"<< b.contains("uma")<<endl;
    cout <<"contains(yan):"<< b.contains("yan")<<endl;
    cout <<"contains(amy):"<< b.contains("amy")<<endl;
    cout <<"contains(ron):"<< b.contains("ron")<<endl;
    cout <<"contains(opal):"<< b.contains("opal")<<endl;



    //testing after remove
    cout <<endl<<"** TEST REMOVE **"<<endl;
    cout <<"removing in this order: gene mary bea uma yan amy ron opal"<<endl;
    b.remove("mary");
    b.remove("bea");
    b.remove("uma");
    b.remove("yan");
    b.remove("amy");
    b.remove("ron");
    b.remove("opal");
    b.remove("gene");


    //amount of stuff
    cout <<"# of nodes:  "<<b.size()<<endl;
    cout <<"# of leaves: "<<b.getLeafCount()<<endl;
    cout <<"BST height:  "<<b.getHeight()<<endl;
    cout <<"BST empty?   ";
    var = b.empty();
    if(var){
        cout <<"true"<<endl;

    }else{
        cout <<"false"<<endl;
    }
    cout <<"pre-order:   "<<b.getPreOrderTraversal()<<endl;
    cout <<"in-order:    "<<b.getInOrderTraversal()<<endl;
    cout <<"post-order:  "<<b.getPostOrderTraversal()<<endl;


    //inserting again
    cout <<endl<<"** TEST INSERT (again) **"<<endl;
    cout<<"inserting in this order: gene mary bea uma yan amy ron opal "<<endl;
    b.insert("gene");
    b.insert("mary");
    b.insert("bea");
    b.insert("uma");
    b.insert("yan");
    b.insert("amy");
    b.insert("ron");
    b.insert("opal");

    //amount of stuff
    cout <<"# of nodes:  "<<b.size()<<endl;
    cout <<"# of leaves: "<<b.getLeafCount()<<endl;
    cout <<"BST height:  "<<b.getHeight()<<endl;
    cout <<"BST empty?   ";
    var = b.empty();
    if(var){
        cout <<"true"<<endl;

    }else{
        cout <<"false"<<endl;
    }

    //traversals
    cout <<"pre-order:   "<<b.getPreOrderTraversal()<<endl;
    cout <<"in-order:    "<<b.getInOrderTraversal()<<endl;
    cout <<"post-order:  "<<b.getPostOrderTraversal()<<endl;


}


void readFile(BST<int> &a,string file){
    string line;
    string FILENAME;



    //gets file

    FILENAME = file;
    ifstream inputFile(FILENAME);

    //opening and reading the file

    if(inputFile){
        while(getline(inputFile, line)) {
            cout <<line<<" ";
            a.insert(stoi(line));

        }
        cout << endl;
    }else{
        cout << "could not read file";

    }


    //closing the file
    inputFile.close();
}

void readFile(BST<string> &b,string file){
    string line;
    string FILENAME;


    //gets file

    FILENAME = file;
    ifstream inputFile(FILENAME);

    //opening and reading the file

    if(inputFile){
        while(getline(inputFile, line)) {
            cout <<line<<" ";
            b.insert(line);
        }
        cout << endl;
    }else{
        cout << "could not read file";

    }


    //closing the file
    inputFile.close();
}

