#include <stdio.h>

typedef struct
{
    int status;
    void (*statusChange)();

} T_Devices;

T_Devices g_Device;

/* regedit function */
void addCallbackeFunction(void (*pstatusChange)(int status))
{
    g_Device.statusChange = pstatusChange;
}

void run()
{

    g_Device.status = 10;
    if (g_Device.status == 10)
    {
        if (g_Device.statusChange != NULL)
        {
            g_Device.statusChange(g_Device.status);
        }
        {
            /* code */
        }
    }
}

void callBack(int status)
{
    printf("stauts = %d\n", status);
}

int main()
{

    addCallbackeFunction(callBack);
    run();
    return 0;
}
