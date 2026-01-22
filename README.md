# Muert_StateEngine
A c++ GameState Engine that loads state dynamically via dll
## Build Commands

This is a Visual Studio 2022 solution (MSBuild). Open `MuertEngine.slnx` in Visual Studio.

**Build via command line:**
```cmd
msbuild MuertEngine.slnx /p:Configuration=Debug /p:Platform=x64
msbuild MuertEngine.slnx /p:Configuration=Release /p:Platform=x64
```

**Output location:** `x64/Debug/` or `x64/Release/`

**External library dependencies** (paths configured in .vcxproj files):
- GLM: `C:\CPP\glm-master`
- GLFW: `C:\CPP\glfw-master`
- GLEW: `C:\CPP\glew-2.1.0`

## Architecture

This is a C++20 game engine with a **modular DLL plugin architecture** consisting of 6 projects:

```
MuertEngine.exe (main application)
    ├── MuertEngine.State (state management framework)
    │   ├── MuertEngine.State.Sys (system states: QUIT, CLEAN_UP)
    │   └── MuertEngine.Global (shared utilities)
    │       └── MuertEngine.Random (RNG, name generation)
    └── MuertEngine.Enum (header-only enumerations)
```

### Core Pattern: State Stack

The engine uses a **state stack pattern** managed by `STATEHOLDER`:

1. `main.cpp` creates `STATEHOLDER` which initializes with `GAMESTATE_QUIT` and `GAMESTATE_CLEAN_UP`
2. `STATEHOLDER::ProgramLoop()` runs the main loop
3. Each frame: execute current state → optionally pop/push states
4. Game states are DLLs loaded at runtime via `stateHolder.loadStateFromDLL()`

**Every GAMESTATE must implement:**
- `bool Exec(double timeElapsed)` - main update logic
- `void PopCurrentState(bool propagateUp)` - cleanup on exit
- `bool InitSubState(double timeElapsed)` - initialization
- Input handlers for keyboard, mouse, scrolling

### Key Components by Project

**MuertEngine.Global** - Core utilities:
- `point2.h/point3.h` - 2D/3D integer point operations
- `direction.h` - Direction vectors and enumerations
- `qUniCoord.h` - Universal coordinate system
- `globalLogging.h` - `PROGRAMLOG` class for file logging
- `GLPrimitives.h` - OpenGL rendering primitives
- `mathFunctions.h`, `stringManipulation.h`, `coordFunctions.h`

**MuertEngine.Random**:
- `MersenneTwister.h` - MT19937 RNG implementation
- `RandomWrapper.h` - RNG wrapper with sub-generators
- `markover.h` - Markov chain name generator

**MuertEngine.State**:
- `stateHolder.h` - Main state stack manager (`GAME::STATEHOLDER`)
- `gameState.h` - Abstract `GAMESTATE` base class
- `dlfcn.hpp` - DLL loading utilities

### Namespaces

- `GAME::` - Game state and core logic
- `GLOBAL::` - Global utilities (logging, math, geometry)
- `RND::` - Random number generation
- `mFunc::` - Math functions
- `COMM::` - String manipulation utilities
- `TIMER::` - Timing utilities

## Adding New Game States

1. Create a new DLL project or add to `MuertEngine.State.Sys`
2. Inherit from `GAMESTATE` in `gameState.h`
3. Implement required virtual methods
4. Export a factory function: `create_GAMESTATE_YourState()`
5. Load at runtime via `STATEHOLDER::loadStateFromDLL()`

## DLL Export/Import

Projects use macros for DLL boundaries (e.g., `GLOBAL_API`, `RANDOM_API`). When adding exported classes/functions, use the appropriate project's export macro.
