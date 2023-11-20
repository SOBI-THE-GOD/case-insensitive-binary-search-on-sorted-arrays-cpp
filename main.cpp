#include <iostream>
#include <algorithm> // for sort
#include <cctype>  // for tolower
#include <string>
using namespace std;
int binarySearchHandler(string namesArr[], string searchedName, int arrayLength);
int main() {
    string names[] = {

        "Amir",
        "Sara",
        "Mohammad",
        "Nasrin",
        "Ali",
        "Parisa",
        "Reza",
        "Fatemeh",
        "Mehdi",
        "Leila",
        "Hossein",
        "Zahra",
        "Ahmad",
        "Shirin",
        "Hamid",
        "Maryam",
        "Behzad",
        "Azita",
        "Khosrow",
        "Fariba"
        
    };

    string searchName;

    int arrayLength = sizeof(names) / sizeof(names[0]);

    sort(names, names + arrayLength);

    cout << "Enter a name to search for: ";
    cin >> searchName;

    transform(searchName.begin(), searchName.end(), searchName.begin(), [](unsigned char c) {
        return tolower(c);
    });

    for (int i = 0; i < arrayLength; i++)
    {
        transform(names[i].begin(), names[i].end(), names[i].begin(), [](unsigned char c) {
            return tolower(c);
        });
    }
    
    int resultIndex = binarySearchHandler(names, searchName, arrayLength);
    
    if (resultIndex == -1) 
        cout << "The name " << searchName << " does not exist in the data base" << endl;
    else
        cout << "The name " << searchName << " exists in the data base and it's located in the names array at index : " << resultIndex << endl;

    return 0;
}

int binarySearchHandler(string namesArr[], string searchedName, int arrayLength) {
    int beginBound = 0 ;
    int endBound = arrayLength - 1 ;
    while (beginBound <= endBound)
    {

        int mid = beginBound + (endBound - beginBound) / 2; 

        int result = -7575; 
        if (searchedName == (namesArr[mid])) 
            result = 0; 

        if (result == 0) 
            return mid; 

        if (searchedName > (namesArr[mid])) 
            beginBound = mid + 1; 

        else
            endBound = mid - 1; 
    }
    return -1;
}