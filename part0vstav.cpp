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

void InsertSort(int n) //сортировка вставками
{
    int key = 0;
    for (int i = 0; i < n; i++)
    {
        for (int i = 1; i < n; i++) {
            for (int j = i; j > 0 && a[j - 1] > a[j]; j--) {// пока j>0 и элемент j-1 > j, x-массив int
                 //--------- меняем местами элементы j и j-1
                int tmp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = tmp;
            }
        }
    }
}

 int main ( ) {
     int i,kk;
     for (kk=0; kk<10000; kk++){
         a[kk] = 10000-kk-1;
     }
     for (i=10; i<10000; i+=10){

 auto begin = std :: chrono :: steady_clock :: now( ) ;
 for ( unsigned cnt = 1; cnt != 0 ; --cnt )
 InsertSort(i) ;
 auto end = std :: chrono :: steady_clock :: now ( ) ;
 auto time_span =
 std :: chrono :: duration_cast<std :: chrono :: milliseconds >(end - begin ) ;

 //std :: cout << "\n\n" ;
 std :: cout << time_span.count( ) << ", " ;

 }
 return 0 ;
 }
