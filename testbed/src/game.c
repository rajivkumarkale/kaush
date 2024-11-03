#include "game.h"
#include <containers/darray.h>

#include <core/logger.h>

b8 game_initialize(game* game_inst) {
    KDEBUG("game_initialize() called!");

    u32* arr = (u32*)darray_reserve(u32, 5);
    for (u32 i = 0; i < 5; i++) {
        darray_push(arr, i * 2);
    }

    darray_push(arr, 7);
    darray_push(arr, 9);

    for (u32 i = 0; i < darray_length(arr); i++) {
        KDEBUG("%d", arr[i]);
    }
    KDEBUG("----");

    u32 pop_value;
    darray_pop(arr, &pop_value);
    KDEBUG("%d", pop_value);

    darray_pop_at(arr, 3, &pop_value);
    KDEBUG("%d", pop_value);

    KDEBUG("----");

    for (u32 i = 0; i < darray_length(arr); i++) {
        KDEBUG("%d", arr[i]);
    }

    return TRUE;
}

b8 game_update(game* game_inst, f32 delta_time) {
    return TRUE;
}

b8 game_render(game* game_inst, f32 delta_time) {
    return TRUE;
}

void game_on_resize(game* game_inst, u32 width, u32 height) {
}