
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

void sort_direct_merge(int a[], int siz)
{
    if (siz < 2)return;
    sort_direct_merge(a, siz / 2);
    sort_direct_merge(&a[siz / 2], siz - (siz / 2));
    int* spec = new int[siz];
    int idspec = 0, idl = 0, idr = siz / 2 ;
    while ((idl < siz / 2) && (idr < siz))
        if (a[idl] > a[idr])
            spec[idspec++] = a[idl++];
        else
            spec[idspec++] = a[idr++];
    while (idl < siz / 2) spec[idspec++] = a[idl++];
    while (idr < siz) spec[idspec++] = a[idr++];
    for (idl = 0; idl < siz; idl++)a[idl] = spec[idl];
    delete[]spec;
}


 int main ( ) {
     int i,kk;
     for (kk=0; kk<10000; kk++){
         a[kk] = 10000 -1 - kk;
         //a[kk] = -3;
     }
     for (i=10; i<10000; i+=10){

 auto begin = std :: chrono :: steady_clock :: now( ) ;
 for ( unsigned cnt = 100; cnt != 0 ; --cnt )
    sort_direct_merge(a, i) ;
 auto end = std :: chrono :: steady_clock :: now ( ) ;
 auto time_span =
 std :: chrono :: duration_cast<std :: chrono :: milliseconds >(end - begin ) ;

 //std :: cout << "\n\n" ;
 std :: cout << time_span.count( ) << ", " ;

 }
 return 0 ;
 }
