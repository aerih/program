#include <Windows.h>
#include <Ole2.h>

#include <SDL_opengl.h>
#include <SDL.h>

#include <Kinect.h>

#define width 1920
#define height 1080

// OpenGL Variables
GLuint textureId;              // ID of the texture to contain Kinect RGB Data
GLubyte data[width * height * 4];  // BGRA array containing the texture data

// Kinect variables
IKinectSensor* sensor;         // Kinect sensor
IColorFrameReader* reader;     // Kinect color data source

bool initKinect() {
    if (FAILED(GetDefaultKinectSensor(&sensor))) {
        return false;
    }
    if (sensor) {
        sensor->Open();

        IColorFrameSource* framesource = NULL;
        sensor->get_ColorFrameSource(&framesource);
        framesource->OpenReader(&reader);
        if (framesource) {
            framesource->Release();
            framesource = NULL;
        }
        return true;
    }
    else {
        return false;
    }
}
void getKinectData(GLubyte* dest) {
    IColorFrame* frame = NULL;
    if (SUCCEEDED(reader->AcquireLatestFrame(&frame))) {
        frame->CopyConvertedFrameDataToArray(width * height * 4, data, ColorImageFormat_Bgra);
    }
    if (frame) frame->Release();
}

