#include <unistd.h>

int main()
{
    char buffer[50];
    int count;

    //stores the no of character read from keyboard
    count = read(0, buffer, 50);

    //writes output of read characters on screen
    write(1, buffer, count);

    return 0;
}
