#include "application.h"
#include "defines.h"
#include "logger.h"
#include "platform/platform.h"
#include "core/kmemory.h"
#include "core/event.h"
#include "game_types.h"

typedef struct application_state {
    game* game_inst;
    b8 is_running;
    b8 is_suspended;
    platform_state platform;
    i16 width;
    i16 height;
    f64 last_time;
} application_state;

static b8 initialized = FALSE;
static application_state app_state;

b8 application_create(game* game_inst) {
    if (initialized) {
        KERROR("application_create called more than once.");
        return FALSE;
    }

    app_state.game_inst = game_inst;

    // Initialize subsystems.
    initialize_logging();

    // TODO: remove this later after testing
    KFATAL("just testing %d ,%d", 42, 17);
    KERROR("just testing %d ,%d", 42, 17);
    KWARN("just testing %d ,%d", 42, 17);
    KINFO("just testing %d ,%d", 42, 17);
    KTRACE("just testing %d ,%d", 42, 17);
    // KASSERT(1 == 0);
    // KASSERT_MSG(1 == 0, "Testing the assert msg");

    app_state.is_running = TRUE;
    app_state.is_suspended = FALSE;

    if (!event_initialize()) {
        KERROR("Event system failed initialization. Application cannot continue.");
        return FALSE;
    }

    if (!platform_startup(
            &app_state.platform,
            game_inst->app_config.name,
            game_inst->app_config.start_pos_x,
            game_inst->app_config.start_pos_y,
            game_inst->app_config.start_height,
            game_inst->app_config.start_width)) {
        return FALSE;
    }

    // Initialize the game.
    if (!app_state.game_inst->initialize(app_state.game_inst)) {
        KFATAL("Game failed to initialize.");
        return FALSE;
    }

    app_state.game_inst->on_resize(app_state.game_inst, app_state.width, app_state.height);

    initialized = TRUE;
    return TRUE;
}

b8 application_run() {
    KDEBUG(get_memory_usage_str());

    while (app_state.is_running) {
        if (!platform_pump_messages(&app_state.platform)) {
            app_state.is_running = FALSE;
        }

        if (!app_state.is_suspended) {
            if (!app_state.game_inst->update(app_state.game_inst, (f32)0)) {
                KFATAL("Game update failed, shutting down.");
                app_state.is_running = FALSE;
                break;
            }

            // Call the game's render routine.
            if (!app_state.game_inst->render(app_state.game_inst, (f32)0)) {
                KFATAL("Game render failed, shutting down.");
                app_state.is_running = FALSE;
                break;
            }
        }
    }

    app_state.is_running = FALSE;

    event_shutdown();

    platform_shutdown(&app_state.platform);

    return TRUE;
}