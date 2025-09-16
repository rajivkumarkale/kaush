# kaush

Files:
Brief description of files
- .vscode/c_cpp_properties:
    intellisense and code completion in vs code
- .vscode/extensions.json
    recommended extensions to download in vs code
- .vscode/keybindings.json
    press F1 and then type keyborad and copy above files for keyboard shortcut configuration
- .vscode/launch
    vscode debugger configuration
- .vscode/settings.json
    vs code settings for the current project
- .vscode/tasks.json
    Build tasks for compiling and building the project

- engine/src/defines.h
    defines that will be used in almost all other files, like types macro and assertions, platform and import/export macros.
- engine/build.bat 
    windows shell batch script file for building the engine
- engine/src/test.h


- testbed/build.bat
    windows shell batch script file for building the testbed

- build-all.bat
    builds engine and then testbed, so we call this script from our .vscode/tasks.json and it will build the project

