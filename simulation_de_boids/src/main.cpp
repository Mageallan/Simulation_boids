#include "config/Settings.h"
#include "model/Flock.h"
#include "model/simulation/Simulation.h"
#include "view/SimulationView.h"
#include "controller/Controller.h"

int main() {
    bd::Settings settings;
    bd::Flock flock(settings.initialBoidCount);
    bd::Simulation sim(flock, settings);
    SimulationView view;

    Controller controller(sim, view, settings);
    controller.run();

    return 0;
}

