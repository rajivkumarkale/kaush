#include <core/logger.h>
#include <core/asserts.h>

int main(void) {
    KFATAL("just testing %d ,%d", 42, 17);
    KERROR("just testing %d ,%d", 42, 17);
    KWARN("just testing %d ,%d", 42, 17);
    KINFO("just testing %d ,%d", 42, 17);
    KTRACE("just testing %d ,%d", 42, 17);

    KASSERT(1 == 0);
    KASSERT_MSG(1 == 0, "Testing the assert msg");
    return 0;
}