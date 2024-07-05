#include "modes/FgcMode.hpp"

FgcMode::FgcMode(socd::SocdType horizontal_socd, socd::SocdType vertical_socd) {
    _socd_pair_count = 2;
    _socd_pairs = new socd::SocdPair[_socd_pair_count]{
        socd::SocdPair{&InputState::left,   &InputState::right, horizontal_socd         },
        socd::SocdPair{&InputState::down,   &InputState::mod_x, vertical_socd           },
    };
}

void FgcMode::UpdateDigitalOutputs(InputState &inputs, OutputState &outputs) {
    // Directions
    outputs.dpadLeft = inputs.left;
    outputs.dpadRight = inputs.right;
    outputs.dpadDown = inputs.down;
    outputs.dpadUp = inputs.mod_x;

    // Menu keys
    outputs.start = inputs.start;
    outputs.select = inputs.c_down;
    outputs.home = inputs.a;

    // Right hand bottom row
    outputs.buttonR = inputs.b;
    outputs.leftStickClick = inputs.x;
    //outputs.triggerRDigital = inputs.z;
    outputs.rightStickClick = inputs.up;

    // Right hand top row
    outputs.a = inputs.r;
    outputs.b = inputs.y;
    outputs.x = inputs.lightshield;
    outputs.y = inputs.midshield;
	
	// Other
	outputs.buttonL = inputs.l;
	outputs.triggerRDigital = inputs.c_up;
	outputs.triggerLDigital = inputs.c_left;
}

void FgcMode::UpdateAnalogOutputs(InputState &inputs, OutputState &outputs) {
    outputs.leftStickX = 128;
    outputs.leftStickY = 128;
    outputs.rightStickX = 128;
    outputs.rightStickY = 128;
    outputs.triggerLAnalog = outputs.triggerLDigital ? 255 : 0;
    outputs.triggerRAnalog = outputs.triggerRDigital ? 255 : 0;
}