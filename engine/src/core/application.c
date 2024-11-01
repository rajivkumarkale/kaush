#include "application.h"
#include "defines.h"
#include "logger.h"
#include "platform/platform.h"

typedef struct application_state {
    b8 is_running;
    b8 is_suspended;
    platform_state platform;
    i16 width;
    i16 height;
    f64 last_time;
} application_state;

static b8 initialized = FALSE;
static application_state app_state;

b8 application_create(application_config* config) {
    if (initialized) {
        KERROR("application_create called more than once.");
        return FALSE;
    }

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

    if (!platform_startup(
            &app_state.platform,
            config->name,
            config->start_pos_x,
            config->start_pos_y,
            config->start_height,
            config->start_width)) {
        return FALSE;
    }

    initialized = TRUE;
    return TRUE;
}

b8 application_run() {
    while (app_state.is_running) {
        if (!platform_pump_messages(&app_state.platform)) {
            app_state.is_running = FALSE;
        }
    }

    app_state.is_running = FALSE;
    platform_shutdown(&app_state.platform);

    return TRUE;
}