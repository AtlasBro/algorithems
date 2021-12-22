#include <iostream>
using namespace std;
int n,A[1000001];
int partition(int A[], int low, int high)
{
    int pivot = A[low];
    while (low < high)
    {
        while (low < high && A[high] >= pivot)
            --high;
        A[low] = A[high];
        while (low < high && A[low] <= pivot)
            ++low;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}
void quicksort(int A[], int low, int high)
{
    int pivotpos = partition(A, low, high);
    if (low < high)
    {
        quicksort(A, low, pivotpos - 1);
        quicksort(A, pivotpos + 1, high);
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    quicksort(A,0,n-1);
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
}