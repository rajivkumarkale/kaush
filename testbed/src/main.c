#include <core/logger.h>
#include <core/asserts.h>

int main(void) {
    KFATAL("A test message: %f , %d", 3.14, 6);
    KERROR("A test message: %f , %d", 3.14, 6);
    KWARN("A test message: %f , %d", 3.14, 6);
    KINFO("A test message: %f , %d", 3.14, 6);
    KDEBUG("A test message: %f , %d", 3.14, 6);
    KTRACE("A test message: %f , %d", 3.14, 6);

    KASSERT(1 == 0);
    KASSERT_MSG(2 == 3, "what are you even doing !");    
    KASSERT_DEBUG( 3 == 4);
    
    return 0;
}
