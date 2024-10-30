#include <core/logger.h>
#include <core/asserts.h>

// TODO: temporary
#include <platform/platform.h>

int main(void) {
    KFATAL("just testing %d ,%d", 42, 17);
    KERROR("just testing %d ,%d", 42, 17);
    KWARN("just testing %d ,%d", 42, 17);
    KINFO("just testing %d ,%d", 42, 17);
    KTRACE("just testing %d ,%d", 42, 17);

    // KASSERT(1 == 0);
    // KASSERT_MSG(1 == 0, "Testing the assert msg");

    platform_state plat_state;
    if (platform_startup(&plat_state, "Kaush Engine Testbed", 100, 100, 1280, 720)) {
        while (TRUE) {
            platform_pump_messages(&plat_state);
        }
    }

    platform_shutdown(&plat_state);

    return 0;
}