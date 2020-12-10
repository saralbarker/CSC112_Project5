#include <iostream>
using namespace std;


void problem4() {
   int x;
   x = 5;
   int *iPtr;
   iPtr = new int();
   *iPtr = x;
   cout << iPtr << endl;
   cout << *iPtr << endl;
   delete iPtr;
}

void problem3() {
    // declare a set of useful variables
    int** friends;
    int peopleCount;
    int i,j;

    // create friendship array
    peopleCount = 3;
    friends = new int*[peopleCount];
    for (i = 0; i < peopleCount; ++i) {
        friends[i] = new int[peopleCount];
    }

    // declare pointer variable for and create popularity array
    int* popularity = new int[peopleCount];

    // initialize all arrays to hold 0 values
    for (i = 0; i < peopleCount; ++i) {
        for (j = 0; j < peopleCount; ++j) {
            friends[i][j] = 0;
        }
        popularity[i] = 0;
    }

    // record friendships [(0,1) and (0,2) are friendship pairs]
    friends[0][1] = 1;
    friends[1][0] = 1;
    friends[0][2] = 1;
    friends[2][0] = 1;

    // use friendship information to compute number of friends
    // per person
    for (i = 0; i < peopleCount; ++i) {
        for (j = 0; j < peopleCount; ++j) {
            if (friends[i][j] == 1)  {
                popularity[i] += 1;
            }
        }
        cout << "Popularity of person " << i << " " << popularity[i] << endl;
    }

    // clean up data
    delete [] popularity;
    for (i = 0; i < peopleCount; ++i) {
        delete [] friends[i];
    }
    delete [] friends;
}

bool problem2Helper(int* anArray, int size) {
    int j;
    int end = size-1;
    bool answer = true;
    for (j = 0; j < end; ++j) {
        if (anArray[j] > anArray[j+1]) {
            answer = false;
            break;
        }
    }
    return answer;
}

void problem2() {
    int* theArray;
    int count;
    int i;
    bool sorted;

    count = 5;
    theArray = new int[count];
    for (i = 0; i < count; ++i) {
        theArray[i] = count-i;
    }

    sorted = problem2Helper(theArray,count);
    delete [] theArray;
    if (sorted == true) {
        cout << "The list is sorted in ascending order." << endl;
    } else {
        cout << "The list is not sorted in ascending order." << endl;
    }
}

void printTypeSizeInformation() {
    cout << "Size of bool: " << sizeof(bool) << endl;
    cout << "Size of int: " << sizeof(int) << endl;
    cout << "Size of double: " << sizeof(double) << endl;
    cout << "Size of pointer to an integer: " << sizeof(int*) << endl;
    cout << "Size of pointer to a double: " << sizeof(double*) << endl;
    cout << "Size of string: " << sizeof(string) << endl;
    cout << "Size of pointer to a string: " << sizeof(string*) << endl;
}

int main() {
    printTypeSizeInformation();
    problem2();
    problem3();
    problem4();
    return 0;
}
