#include <unistd.h>

int main()
{
    //writes Hello on screen
    write(1, "Hello", 5);

    //writes He on screen
    write(1, "Hello", 2);

    //writes garbages on screen
    write(1, "Hello", 20);

    return 0;
}
