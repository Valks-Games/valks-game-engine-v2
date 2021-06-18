## GLFW
1. Download GLFW source from their [website](https://www.glfw.org)
2. Build GLFW source with CMake
3. Build GLFW solution
4. Copy `glfw3.lib` from `glfw/build/src/Debug` to `valks-engine/lib`
5. Copy contents of `glfw/include` to `valks-engine/include`

## GLM
1. Download the latest version of glm from [here](https://github.com/g-truc/glm/tags)
2. Copy contents of `glm/glm` to `valks-engine/include/glm`

## GLAD
1. Go to [GLAD web service](https://glad.dav1d.de)
2. Set language to `C++`, specification to `OpenGL`, API gl to `Version 4.6`, profile to `Core` and make sure `Generate a loader` is checked
3. Click `Generate`, download `glad.zip`
4. Copy contents of `glad/include` to `valks-engine/include`
5. Copy `glad/src/glad.c` to `valks-engine/include`
6. Make sure `glad.c` is included in the project
