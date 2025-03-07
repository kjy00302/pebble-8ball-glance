#include <pebble.h>
#include "strings.h"

static void prv_update_app_glance(AppGlanceReloadSession *session, size_t limit, void *context) {
  if (limit < 1) return;

  // expires in 5 second
  time_t expire = time(NULL) + 5;

  int idx = rand() % strings_get_cnt();
  const char *str = strings_get(idx);

  uint32_t icon = PUBLISHED_ID_ICON_RESPONSE_YES;
  if (idx >= 15) {
    icon = PUBLISHED_ID_ICON_RESPONSE_NO;
  } else if (idx >= 10) {
    icon = PUBLISHED_ID_ICON_RESPONSE_LATER;
  }

  AppGlanceSlice entry = (AppGlanceSlice) {
    .layout = {
      .icon = icon,
      .subtitle_template_string = str
    },
    .expiration_time = expire
  };

  const AppGlanceResult result = app_glance_add_slice(session, entry);
  if (result != APP_GLANCE_RESULT_SUCCESS) {
    APP_LOG(APP_LOG_LEVEL_ERROR, "AppGlance Error: %d", result);
  }
}

static void prv_deinit(void) {
  if (launch_reason() == APP_LAUNCH_USER)
    app_glance_reload(prv_update_app_glance, NULL);
}

int main(void) {
  // prv_init();
  app_event_loop();
  prv_deinit();
}
