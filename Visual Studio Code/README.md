# Introduction

Visual Studio Code / VSCodium related stuff.

## Settings

- [Keyboard shortcuts for macOS](https://code.visualstudio.com/shortcuts/keyboard-shortcuts-macos.pdf)

## Setup and debug C++ project (Linux)

### Create a new project

- Open Visual Studio Code.
- Create a folder in your system.
- Click 'File' -> 'New File' menu.
- Now press 'Ctrl+S' Or click 'File' -> 'Save' menu.
- In 'File Save' dialog, save the file on newly created folder.
- Now click 'File' -> 'Open Folder...' menu and select newly created folder to open. And it will open your newly created VSC project folder.

### Open a VSC Project Folder

- Click 'File' -> 'Open Folder...' menu.
- Select VSC project folder you want to open and work.

### C++ file handling and Makefile

- VSC is a advanced file editor having code intellisence and debugging option. So, you can modify C++ file like other C++ IDE.
- The only thing you have to create is a 'Makefile' to build the VSC project. So, create a Makefile according to your project.

### Build Setting for project

- To build the project you have to create a 'task' (which having setting for build). Do the following steps to create a 'task':
	- Press 'Ctrl+P', a search window will appear at the top of the dashboard.
	- In search window, write '> configure'.
	- Then select 'Tasks: Configure Task Runner' from dropdown menu.
	- Select 'Others' from dropdown menu.
	- A 'task.json' file will open.
	- Delete entire existing code and replace it by following code:

	```json
	{
    "version": "0.1.0",
    "command": "make",
    "isShellCommand": true,
    "tasks": [
      {
        "taskName": "Makefile",
        // Make this the default build command.
        "isBuildCommand": true,
        // Show the output window only if unrecognized errors occur.
        "showOutput": "always",
        // No args
        "args": ["all"],
        // Use the standard less compilation problem matcher.
        "problemMatcher": {
          "owner": "cpp",
          "fileLocation": ["relative", "${workspaceRoot}"],
          "pattern": {
            "regexp": "^(.*):(\\d+):(\\d+):\\s+(warning|error):\\s+(.*)$",
            "file": 1,
            "line": 2,
            "column": 3,
            "severity": 4,
            "message": 5
          }
        }
      }
    ]
	}
	```

	- Now save the 'tasks.json' file.
- Now set the shortcut key for build. Do the following steps to set the shortcut key for build:
	- Click 'File' -> 'Preferences' -> 'Keyboard Shortcuts' menu.
	- A 'Default Keyboard Shortcuts' file will open.
	- In 'Default Keyboard Shortcuts' window (left window), search for 'workbench.action.tasks.build'.
	- If that keyword is present then check corresponding "key" for this command. Default setting is:

	```json
	  {
			"key": "ctrl+shift+b",
			"command": "workbench.action.tasks.build"
		}
	```
	- You can change the "key" or leave as it is and use that keyboard shortcut to build the project.
	- If you change the shortcut then save the file.
	- If 'workbench.action.tasks.build' keyword is not present in the 'Default keyboard shortcut' window then add a new entry for it.
	- Add following line at the end of the array before "]".
	  - Add ',' at the end of the last shortcut command.
	  - Then write:
		```json
		{
		  "key": "<keyborad shortcut>",
			"command": "workbench.action.tasks.build"
		}
		```
	  - Finally save the file.
- Press build keyboard shortcut to build the project.


### Debug

- To Debug the project, Press _Debug_ icon in the most left panel of the VSC window.
- Now debug page will arise.
- Click _Setting_ icon (Beside DEBUG dropdown option).
- Select _C++(GDB)_ from dropdown menu.
- It will open _launch.json_ file.
- Change "program" in both the section "C++ Launch(GDB)" and "C++ Attach(GDB)" with value:
  ```json
  "program": "${workspaceRoot}/<project executable name>"
  ```
- Save the file.
- Now set break points in the source file.
- Then select _C++ Launch(GDB)_ from DEBUG dropdown option.
- Finally press green colored 'Start' button and enjoy the debugging.
