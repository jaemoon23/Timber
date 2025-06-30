#include "stdafx.h"
#include "Framework.h"

int main()
{
    FRAMEWORK.Init(1920.f, 1020.f, "TimBer!");
    FRAMEWORK.Do();
    FRAMEWORK.Release();

    return 0;
}