# FLKinectPlugin - Kinect Integration Plugin for Unreal Engine 4.9

This plugin exposes all tracked bodies to Unreal Engine 4.9.

## Usage

Drop the plugin in your project's `\Plugins` folder. When you recompile, "Kinect" will appear as a cateogry in your blueprints.

If you're testing, you can just use "Get First Body":

[[!Get First Body](Resources/Readme/FirstBody.PNG)]

Kinect 2 allows up to 6 bodies tracked, you can see which ones are tracked through the blueprint:

[[!Get First Body](Resources/Readme/Switch.PNG)]

## Changelog

*0.2.2*
Fixes issue with how orientations are drawn.
*0.2.1*
Adds "Debug" features.
*0.2.0*
Removes the kinect component, all features now governed by a static library.
*0.1*
Initial commit



## License
[![Creative Commons License](https://i.creativecommons.org/l/by-nc-sa/3.0/us/88x31.png)](http://creativecommons.org/licenses/by-nc-sa/3.0/us/)

This work is licensed under a [Creative Commons Attribution-NonCommercial-ShareAlike 3.0 United States License](http://creativecommons.org/licenses/by-nc-sa/3.0/us/)