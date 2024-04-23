#include <windows.h>
#include <stdio.h>
#include <sysinfoapi.h>
#define essay 1024

int main() {
    MEMORYSTATUSEX statex;

    statex.dwLength = sizeof (statex);

    GlobalMemoryStatusEx (&statex);

    printf ("Il y a  %*I64d Go de mémoire physique totale.\n",
            15, statex.ullTotalPhys / essay / 1000000);

    Sleep (2000);

    int time = 0;

    while (time < 10) {
        printf("Virus en cours d'execution\n");
        Sleep(1000);
        time++;
    }

    return 0;
}