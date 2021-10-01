
#include <habit-tracker-app.h>

using finalproject::HabitTrackerApp;

void prepareSettings(HabitTrackerApp::Settings* settings) {
  settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(HabitTrackerApp, ci::app::RendererGl, prepareSettings);
