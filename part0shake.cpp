#include <iostream>
#include <chrono>
#include <random>
int a[10000];
int rand_uns(int min, int max) {
unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
static std::default_random_engine e(seed);
std::uniform_int_distribution<int> d(min, max);
return d(e);
}

void ShakerSort(int n) {
    int left, right, i;
    left = 0;
    right= n - 1;
    while (left <= right) {
        for (i = right; i >= left; i--) {
            if (a[i-1] > a[i]) {
                std::swap(a[i-1], a[i]);
            }
        }
        left++;
        for (i = left; i <= right; i++) {
            if (a[i-1] > a[i]) {
                std::swap(a[i-1], a[i]);
            }
        }
        right--;
    }
}

 int main ( ) {
     int i,kk;
     for (kk=0; kk<10000; kk++){
         a[kk] = 10000-kk-1;
     }
     for (i=10; i<10000; i+=10){

 auto begin = std :: chrono :: steady_clock :: now( ) ;
 for ( unsigned cnt = 2; cnt != 0 ; --cnt )
ShakerSort(i) ;
 auto end = std :: chrono :: steady_clock :: now ( ) ;
 auto time_span =
 std :: chrono :: duration_cast<std :: chrono :: milliseconds >(end - begin ) ;

 //std :: cout << "\n\n" ;
 std :: cout << time_span.count( ) << ", " ;

 }
 return 0 ;
 }
