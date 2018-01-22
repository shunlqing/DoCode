#include "BaseSort.h"
#include "Selection.h"
#include "Insertion.h"
#include "Merge.h"
#include "Shell.h"
#include <string>

int main()
{
    Selection<std::string> s;
    std::string a[10] = {
        "x",
        "a",
        "s",
        "j",
        "z",
        "h",
        "l",
        "o",
        "m",
        "g"};
    s.test(a, 10);

    Insertion<int> x;
    int b[5] = {1, 4, 5, 3, 2};
    x.test(b, 5);

    Shell<int> she;
    she.test(b, 5);
}