# OpenFrameworks Project Organization

## Root Folder Structure

- README.md
- Apps
	- OF App 1
	- OF App 2
	- OF App 3
- Sketches
	- BaseApp
	- OF Sketch 1
	- OF Sketch 2
	- OF Sketch 3
- openFrameworks (git submodule)
- ExternalAddons
	- addon1 (git submodule)
	- addon2 (git submodule)
	- addon3 (git submodule)
- build.command*
- Configs*
- Documentation
- Deployment*
	- Scripts
	- start.command
	- stop.command
- Scripts*


## openFrameworks and addons

### openFrameworks
openFrameworks is already added as a submodule, pointing at the Local Projects fork. It is checked out to the branch `stable` which corresponds to the most recent release. Feel free to create a project-specific branch that points to a different version of OF (`master`, `0.8.1`, etc.)

### addons
openFrameworks addons should be added as submodules in the ExternalAddons addons folder. Generally, these should be forked into our repo in the event that the original author removes their repository.

	cd ExternalAddons
	git submodule add https://github.com/local-projects/ofxAddonName.git

When adding an addon to a project, make sure a relative path is used. Tools such as Adam Carlucci's [OF Plugin for Xcode](http://) should take care of this automatically, setting the paths to something like `../../ExternalAddons/ofxAddonName...` instead of the normal `../../../addons/ofxAddonName...`. You want to make sure it's not an absolute path such as `/Users/youraccount/Code/Project/ExternalAddons/ofxAddonName...` because everyone will hate you.

### BaseApp
In the sketches folder is a starter project called BaseApp, which serves the same purpose as OF's emptyExample, though the paths inside Xcode's project.pbxproj file have been modified with our file structure since it different from the openFrameworks norm. Copy BaseApp and use it as your starting point for new Apps and Sketches.

*BaseApp is currently working OS X but probably needs the paths set correctly for Windows IDEs.*

## Other Folders

### build.command
This script should build a Release from scratch. The script will create a Release folder, to be copied integrally into the final computer. That folder should include binary + needed configuration files, required assets, and deployment scripts. The deployment scripts are the way to start, stop and report crashes for the installation.
The release binary should include versioning information. Look into CWRU project for an example on how to do this on OSX.

### Configs
Includes configuration files to be used onsite. These will be copied over the Release folder by the build.command when building a release.

### Deployment
includes all scripts needed to start / stop / report crash etc for the installtaion. It should at least include two clear scripts called "start" and "stop", wich might call subscripts.

### Scripts
Random scripts that might help for development / testing (i.e. pull json files and clean, update submodules, etc)