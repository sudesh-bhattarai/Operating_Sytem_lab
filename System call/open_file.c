#include <stdio.h>      
#include <sys/types.h>  
#include <fcntl.h>      
#include <sys/stat.h>  
#include <unistd.h>    

int main()
{
    const char *filename = "example.txt";
    int flags = O_WRONLY | O_CREAT; // Open for writing and create if it doesn't exist
    mode_t mode = S_IRUSR | S_IWUSR; // User has read and write permissions

    int fd = open(filename, flags, mode);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    // File is open and can be written to or read from using the file descriptor (fd)
    write(fd, "Hello World", 11);

    // Close the file when done
    close(fd);

    return 0;
}
