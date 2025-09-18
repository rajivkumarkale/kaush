#include <core/logger.h>
#include <core/asserts.h>

// TODO: test
#include <platform/platform.h>

int main(void) {
    KFATAL("A test message: %f , %d", 3.14, 6);
    KERROR("A test message: %f , %d", 3.14, 6);
    KWARN("A test message: %f , %d", 3.14, 6);
    KINFO("A test message: %f , %d", 3.14, 6);
    KDEBUG("A test message: %f , %d", 3.14, 6);
    KTRACE("A test message: %f , %d", 3.14, 6);

    // KASSERT(1 == 0);
    // KASSERT_MSG(2 == 3, "what are you even doing !");    
    // KASSERT_DEBUG( 3 == 4);
    
    platform_state state;
    if(platform_startup(&state, "Kaush Engine Testbed", 100, 100, 1280, 720)) {
        while(TRUE) {
            platform_pump_messages(&state);
        }
    }
    platform_shutdown(&state);

    return 0;
}
