#include <iostream>
#include <string>
#include <cmath>
using namespace std;

template <typename T>
T calcularD(T x1, T y1,T x2, T y2){
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
template <typename A>
A tiempo( A dis, A velo){
    return (dis/velo);
}

int main(){
    cout<<calcularD(2.5,2.0,2.8,3.1)<<endl;
    cout<<tiempo(12.0,100.0);
    return 0;
}