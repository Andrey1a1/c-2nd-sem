
#include <iostream>
#include <chrono>
#include <random>
#include <vector>
int a[10000];
int rand_uns(int min, int max) {
unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
static std::default_random_engine e(seed);
std::uniform_int_distribution<int> d(min, max);
return d(e);
}


using namespace std;

void combSort(int arr[], int n) {
    int gap = n;
    bool swapped = true;
    while (gap > 1 || swapped) {
        gap = max(1, int(gap / 1.3));
        swapped = false;
        for (int i = 0; i + gap < n; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}




 int main ( ) {
     int i,kk;
     for (kk=0; kk<10000; kk++){
         a[kk] = 10000 - kk - 1;

     }
     for (i=10; i<10000; i+=10){

 auto begin = std :: chrono :: steady_clock :: now( ) ;
 for ( unsigned cnt = 100; cnt != 0 ; --cnt )
combSort(a, i) ;
 auto end = std :: chrono :: steady_clock :: now ( ) ;
 auto time_span =
 std :: chrono :: duration_cast<std :: chrono :: milliseconds >(end - begin ) ;

 //std :: cout << "\n\n" ;
 std :: cout << time_span.count( ) << ", " ;

 }
 return 0 ;
 }
