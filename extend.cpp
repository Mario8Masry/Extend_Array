#include <iostream>
#include <cstring>

using namespace std;
class ourarray{
public:
    template <typename T> void Resize(T *&source, int newSize){
    if(source == nullptr)
        return;
    if(newSize <= 0)
        return;
    if(newSize == static_cast<int>(sizeof(source)))
        return;
    //Process
    /*1-Create new empty array from the same type of the source array with the new size
    2-Move all elements from source array to the new array
    3-Assign the address of the new array for the source array
    */
    T *newArray = new T[newSize];
    memcpy(newArray, source, sizeof(T) * newSize);
    // "memcpy" copies data from memory and it takes three arguments destination pointer , source pointer , number of bytes to copy
    delete[]source;
    source = newArray;
    }
};
    int main(){
        int *arr = new int[3]{1, 2, 3};
        ourarray our;
        our.Resize<int>(arr, 5);
        for(int i = 0; i<5; i++){
            cout<<arr[i] <<" ";
        }
        cout<<endl;
    }








