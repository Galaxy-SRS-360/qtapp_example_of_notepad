#include "mywindow.h"

#include <QApplication>
#include <stdio.h>
#include <stdlib.h>


unsigned long __stack_chk_guard;
void __stack_chk_guard_setup(void)
{
    __stack_chk_guard = 0xBAAAAAAD; // provide some magic numbers
}

void __stack_chk_fail(void)
{
    fprintf(stderr, "Stack smashing detected!\n");
    exit(EXIT_FAILURE);
}



int main(int argc, char *argv[])
{
    __stack_chk_guard_setup();
    QApplication a(argc, argv);
    MyWindow w;
    w.show();
    return a.exec();
}
