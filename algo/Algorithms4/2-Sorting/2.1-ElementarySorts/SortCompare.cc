/**
 * 比较各种排序算法
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Insertion.h"
#include "Selection.h"
#include "Shell.h"

using std::string;

class SortCompare {
public:
    double timeUseForOnce(string alg, double a[], int size){
        clock_t startTime = clock();
        if(alg == "Insertion"){
            Insertion<double> s;
            s.sort(a, size);    
        }
        if(alg == "Shell"){
            Shell<double> s;
            s.sort(a, size);
        }
        if(alg == "Selection"){
            Selection<double> s;
            s.sort(a, size);
        }
        clock_t endTime = clock();
        double time = static_cast<double>(endTime - startTime)/CLOCKS_PER_SEC;
        // std::cout << time << std::endl;
        return time;
    }

    double timeRandomInput(string alg, int N, int T) {
        srand((unsigned)time((time_t*)NULL));
        double total = 0.0;
        double a[N];
        for(int t = 0; t < T; t++) {
            for(int i = 0; i < N; i++) {
                a[i] = (double)rand();
            }
            total += timeUseForOnce(alg, a, N);
        }
        return total;
    }

};

int main(int argc, char *argv[])
{
    SortCompare s;
    if(argc != 3){
        std::cout << "Usage: <Num> <Time>" << std::endl; 
        return -1;
    }
    int N = atoi(argv[1]);
    int T = atoi(argv[2]);
    std::cout << "N : " << N << "; T : " << T << std::endl;
    std::cout << "Insertion Time: " << 
            s.timeRandomInput("Insertion", N, T) << std::endl;
    std::cout << "Selection Time: " << 
            s.timeRandomInput("Selection", N, T) << std::endl;
    std::cout << "Shell Time: "
             << s.timeRandomInput("Shell", N, T) << std::endl;

}