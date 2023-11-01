// Binary search- quickly find a target value in a sorted array 
// M= L+(floor(R-L))/2 does not overflow integer bounds

//Summary
//Looking for a target value
//The last/first element that satisfies a certain condition
//Real values

//IMPLEMENTATION

int binarysearch(int L, int R, int arr[n], int target){
int L=0, R=n-1;
while(L<=R){
    int mid= L +(R-L)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            L= mid+1;
        } else {
            R=mid-1;
        }
        
}
return -1;
}