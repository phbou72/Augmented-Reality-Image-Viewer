Augmented Reality Image Viewer
================
This project is a prototype of an image viewer application that use AR, hand gesture and a camera to trigger its action.

Possible actions include :
- Swiping right or left to change the picture
- Zoom in/out by swiping top or bottom
- Control picture brightness by approaching a closed fist in front of a camera 


Technology :
- OpenCV for image processing
- HAAR for hand recognition
- C++

Performance :
The algorithm has been optimised to at least support a framerate of 15 fps without jittering or slowdown. Under good lightning it can perform better. It could also use CUDA to boost performance even more.
