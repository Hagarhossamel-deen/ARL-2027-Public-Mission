# ARL Debugging Challenge: Rover Safety Monitor

An autonomous rover receives obstacle detections in its own local coordinate frame. The safety monitor must reject unreliable data, convert valid detections into world coordinates, identify the nearest obstacle, and decide whether emergency braking is required.

The supplied project does not currently build or behave according to this specification. Diagnose and correct it. You may change the existing source files and CMake configuration, but do not replace the program with hard-coded output.

Internet and documentation are allowed. Read AI Guidelines below.

## Data Model

Each detection contains:

- `forward`: distance in metres in front of the rover. Negative values are behind it.
- `left`: lateral distance in metres; positive values are to the rover's left.
- `confidence`: a value from 0.0 to 1.0.

The rover pose contains a world position and a heading measured in **degrees counter-clockwise from the positive world X-axis**.

A detection is valid when:

- all numeric fields are finite;
- confidence is between the configured minimum and 1.0, inclusive;
- its Euclidean range is greater than 0 and no greater than the configured maximum range.

Emergency braking must engage when at least one valid obstacle:

- is in front of the rover, including exactly zero metres forward;
- is inside the lane corridor, including its boundary; and
- has a forward distance no greater than the stopping distance.

The lane corridor is defined by `abs(left) <= lane_half_width`.

## Expected Output

Once corrected, the supplied telemetry in `main.cpp` must produce exactly:

```text
ARL Rover Safety Monitor
Valid detections: 3
Nearest obstacle: cone
World position: (96.0, 62.0)
Stopping distance: 20.0 m
Emergency brake: ENGAGE
```

Correctness must also hold for other telemetry values, not only the supplied example.

## Build on Windows

From the assignment directory:

```powershell
cmake -S . -B build
cmake --build build --config Release
```

Depending on the CMake generator, run one of:

```powershell
.\build\rover_safety_monitor.exe
.\build\Release\rover_safety_monitor.exe
```

## What to Submit

### Corrected Project

Submit all corrected `.cpp`, `.hpp`, and `CMakeLists.txt` files while preserving the supplied folder structure.

### PDF Report

Name the report `<your_name>_DebugChallenge_Report.pdf`. Include:

- every issue you found;
- the symptom, root cause, and fix for each issue;
- your reasoning and the programming concept involved;
- how the corrected system processes a detection from input to braking decision;
- references and resources you used, including AI tools where applicable.

A short successful build/run log or screenshot is optional but appreciated.

## AI Usage
AI is not forbidden, but you will be evaluated very carefully & thoroughly. You must understand and be able to explain every submitted change AND all the caveats around it during your interview.
