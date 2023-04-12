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

char func(int x) {
    int i, p; bool sorted;
    sorted = false;
    while (sorted == false){
        sorted = true;
    for (i=0; i<x-1; i++){
        if (a[i]>a[i+1]){
            p = a[i];
            a[i] = a[i+1];
            a[i+1] = p;
            sorted = false;
        }
        }
    }

    return 'o';
 }

 int main ( ) {
     int i,kk;
     for (kk=0; kk<10000; kk++){
         a[kk] = 10000 -1 - kk;
     }
     for (i=10; i<10000; i+=10){

 auto begin = std :: chrono :: steady_clock :: now( ) ;
 for ( unsigned cnt = 100; cnt != 0 ; --cnt )
 func(i) ;
 auto end = std :: chrono :: steady_clock :: now ( ) ;
 auto time_span =
 std :: chrono :: duration_cast<std :: chrono :: milliseconds >(end - begin ) ;

 //std :: cout << "\n\n" ;
 std :: cout << time_span.count( ) << ", " ;

 }
 return 0 ;
 }
