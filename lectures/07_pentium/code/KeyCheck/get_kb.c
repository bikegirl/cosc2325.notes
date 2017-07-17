// #include "kbhit.h" /* --- self-identity --- */
#include <stdio.h> /* fileno setbuf stdin */
#include <stddef.h> /* NULL */
#include <termios.h> /* termios tcsetattr tcgetattr TCSANOW */
#include <sys/ioctl.h> /* ioctl FIONREAD ICANON ECHO */

static int initialized = 0;
static struct termios original_tty;

int kbhit();
void kbinit();
void kbfini();

int kbhit() {
    if(!initialized) {
        kbinit();
    }

    int bytesWaiting;

    ioctl(fileno(stdin), FIONREAD, &bytesWaiting);
    return bytesWaiting;
}

/* Call this just when main() does its initialization. */
/* Note: kbhit will call this if it hasn't been done yet. */

void kbinit() {
    struct termios tty;
    tcgetattr(fileno(stdin), &original_tty);
    tty = original_tty;
    /* Disable ICANON line buffering, and ECHO. */
    tty.c_lflag &= ~ICANON;
    tty.c_lflag &= ~ECHO;
    tcsetattr(fileno(stdin), TCSANOW, &tty);
    /* Decouple the FILE*'s internal buffer. */
    /* Rely on the OS buffer, probably 8192 bytes. */
    setbuf(stdin, NULL);
    initialized = 1;
}

/* Call this just before main() quits, to restore TTY settings! */
void kbfini() {
    if(initialized) {
        tcsetattr(fileno(stdin), TCSANOW, &original_tty);
        initialized = 0;
    }
}

char get_kb(void) {
    char c;
    while (!kbhit());
    c = fgetc(stdin);
    fflush(stdin);
    usleep(1000);
    kbfini();
    return c;
}
