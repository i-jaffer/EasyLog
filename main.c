#include "stdio.h"
#include "unistd.h"
#include "log.h"

#define TAG "main"

int main()
{
        int ret = 0;
        LOGE(TAG, "hello %d", ret);
        return 0;
}