#include <iostream>
using namespace std;

int main() {
    const char *s = "#include <iostream>%cusing namespace std;%c%cint main() {%c    const char *s = %c%s%c;%c    printf(s, 10, 10, 10, 10, 34, s, 34, 10, 10, 10);%c    return 0;%c}%c";
    printf(s, 10, 10, 10, 10, 34, s, 34, 10, 10, 10);
    return 0;
}
