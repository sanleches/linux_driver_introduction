/*
 * =============================================================================
 * hello_kernel_07 - Character Device Open Test
 * =============================================================================
 *
 * User-space helper for the open/release lesson. It opens the supplied device
 * node three times with different flags so the kernel module can print the
 * resulting struct file metadata.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// -----------------------------------------------------------------------------
// Test Entry Point
// -----------------------------------------------------------------------------

int main(int argc, char **argv) {
    int fd;

    printf("argc: %d \n", argc);
    printf("argv[1]: %s \n", argv[1]);
    if (argc < 2) {
        printf("A file is needed as an argument!\n");
        return 0;
    }

    // First open: plain read-only access.
    fd = open( argv[1], O_RDONLY);

    if (fd < 0) {
        perror("open");
        return fd;
    }

    close (fd);

    // Second open: read/write access with synchronous I/O requested.
    fd = open( argv[1], O_RDWR | O_SYNC);

    if (fd < 0) {
        perror("open");
        return fd;
    }

    close (fd);

    // Third open: write-only access with non-blocking behavior requested.
    fd = open( argv[1], O_WRONLY | O_NONBLOCK);

    if (fd < 0) {
        perror("open");
        return fd;
    }

    close (fd);

    return 0;
}
