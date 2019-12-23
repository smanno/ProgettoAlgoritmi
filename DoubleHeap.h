//
// Created by stefano on 23/12/2019.
//

#ifndef PROGETTOALGORITMI_DOUBLEHEAP_H
#define PROGETTOALGORITMI_DOUBLEHEAP_H

struct valueIndex {
    int value;
    int index;
};

/**
 * CLASS DoubleHeap
 * has NO order
 */
class DoubleHeap{
protected:
    vector<valueIndex> structNodes;
    int parent(int);
    int left(int);
    int right(int);
public:
    void build(vector<valueIndex>);
    int length();
    bool isEmpty();
    valueIndex getRoot();              // returns the root without deleting it
};

// return parent of vector[index]
int DoubleHeap::parent(int index)  { return (index - 1) / 2; }

// return left child of vector[index]
int DoubleHeap::left(int index) { return (2 * index) + 1; }

// return right child of vector[index]
int DoubleHeap::right(int index) { return (2 * index) + 2; }

// modify a SingleHeap with a new vector
void DoubleHeap::build(vector<valueIndex> input) {
    structNodes = input;
}

// returns number of elements in SingleHeap
int DoubleHeap::length() { return structNodes.size(); }

// true is no elements
bool DoubleHeap::isEmpty() { return structNodes.size() == 0; }

// return root
valueIndex DoubleHeap::getRoot() {
    try {
        if(length()==0){
            throw out_of_range("Vector<X>::at : "
                               "index is out of range(Heap underflow) for DoubleMinHeap::getRoot");
        }
        return structNodes[0];
    }
    catch (const out_of_range oor){
        cout<<"\n"<<oor.what();
        return {-1,-1};
    }
}

/**
 * CLASS DoubleMinHeap
 * every node has a value greater than his parent
 * every node has a value lower than his children
 */


class DoubleMinHeap: public DoubleHeap{
protected:
    void heapify();
    void heapifyDown(int);
    void heapifyUp(int);
public:
    void build(vector<valueIndex>);
    void extract();
    void insert(int,int);
};

// modify and re-heapify a MaxHeap with a new vector
void DoubleMinHeap::build(vector<valueIndex> input) {
    structNodes = input;
    heapify();
}

// heapify all non-leaf nodes
void DoubleMinHeap::heapify() {
    for(int i=(length()/2) -1; i>=0; --i){
        heapifyDown(i);
    }
}

// recursive heapify node[index] and its children
void DoubleMinHeap::heapifyDown(int index) {
    int newIndex;
    int lef = left(index);
    int rig = right(index);
    if(lef < length() && structNodes[lef].value < structNodes[index].value){
        newIndex = lef;
    } else {
        newIndex = index;
    }
    if(rig < length() && structNodes[rig].value < structNodes[newIndex].value){
        newIndex = rig;
    }
    if(newIndex != index){
        swap(structNodes[index], structNodes[newIndex]);
        heapifyDown(newIndex);
    }
}

// recursive heapify node[index] and parent
void DoubleMinHeap::heapifyUp(int index) {
    if(index && structNodes[parent(index)].value > structNodes[index].value){
        swap(structNodes[index], structNodes[parent(index)]);
        heapifyUp(parent(index));
    }
}

// insert number/index as a valueIndex into the SingleHeap
void DoubleMinHeap::insert(int number, int pos) {
    valueIndex input;
    input.value = number;
    input.index = pos;
    structNodes.push_back(input);
    int i = length()-1;
    heapifyUp(i);
}

// remove root element
void DoubleMinHeap::extract() {
    try {
        if(length()==0){
            throw out_of_range("Vector<X>::at() : "
                               "index is out of range(Heap underflow) for MinHeap::extract");
        }
        structNodes[0] = structNodes.back();
        structNodes.pop_back();
        heapifyDown(0);
    }
    catch (const out_of_range& oor){
        cout<<"\n"<<oor.what();
    }
}

#endif //PROGETTOALGORITMI_DOUBLEHEAP_H