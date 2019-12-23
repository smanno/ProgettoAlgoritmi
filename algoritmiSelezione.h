//
// Created by stefano on 23/12/2019.
//

#ifndef PROGETTOALGORITMI_ALGORITMISELEZIONE_H
#define PROGETTOALGORITMI_ALGORITMISELEZIONE_H

/** QUICK SELECT */
int partition(vector<int> &arrayOfNumbers, int start, int end){
    int key = arrayOfNumbers[end];
    int i = start-1;
    for(int j=start; j<=end; j++){                  // con j<end non fa l'ultima iterazione e continua all'infinito
        if(arrayOfNumbers[j]<=key){
            i++;
            swap(arrayOfNumbers[i],arrayOfNumbers[j]);
        }
    }
    return i;
}

void quickSelectRec(vector<int> &arrayOfNumbers, int start, int end, int index){
    if(start>=end) return;
    if(index<start || index>end) return;
    int partitionIndex = partition(arrayOfNumbers,start,end);
    quickSelectRec(arrayOfNumbers, start, partitionIndex - 1, index);
    quickSelectRec(arrayOfNumbers, partitionIndex + 1, end, index);
}

int quickSelect(vector<int> &arrayOfNumbers, int number){
    int len = arrayOfNumbers.size();
    quickSelectRec(arrayOfNumbers, 0, len - 1, number - 1);
    cout<<arrayOfNumbers[number-1]<<endl;
    return 0;
}

/** HEAP SELECT */
struct greater1{
    bool operator()(const long& a,const long& b) const{
        return a>b;
    }
};

int heapSelect(vector<int> &arrayOfNumbers, int number){
    std::make_heap(arrayOfNumbers.begin(), arrayOfNumbers.end(), greater1()); // minHeap

    DoubleMinHeap heapB;
    heapB.insert(arrayOfNumbers[0],0);
    valueIndex root;

    for(int i=1; i<number; i++){
        root = heapB.getRoot();
        int left = (root.index*2)+1;
        int right = (root.index*2)+2;
        heapB.extract();
        if(left<arrayOfNumbers.size()) {
            heapB.insert(arrayOfNumbers[left], left);
        }
        if(right<arrayOfNumbers.size()) {
            heapB.insert(arrayOfNumbers[right], right);
        }
    }

    root = heapB.getRoot();
    cout<<root.value<<endl;

    return 0;
}

#endif //PROGETTOALGORITMI_ALGORITMISELEZIONE_H
