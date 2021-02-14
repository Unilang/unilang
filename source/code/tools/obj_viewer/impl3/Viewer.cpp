#include "Viewer.hpp"

#include "Matrix.hpp"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <GL/glx.h>

#define _USE_MATH_DEFINES
#include <cmath>

#include <stdio.h>

#include "code/utilities/graphics/x11/main_state/setup_display_settings.hpp"
#include "code/utilities/graphics/x11/main_state/x11_main_state_creator.hpp"
#include "code/utilities/graphics/glx/x11_to_opengl_binder.hpp"

static float degToRad(float x) {
	return (x * (M_PI / 180.0));
}

Viewer* Viewer::instance_ = NULL;
Main_X11_State x11;

static bool use_glut = false;

Viewer::Viewer(std::string name, int width, int height) : name_(name), width_(width), height_(height), 
	running_(false), mouseEnabled_(false), mouseDown_(false) {
	arcBallRotation_ = Matrix3f::identity();
	xRotation_ = Matrix3f::identity();
	yRotation_ = Matrix3f::identity();
}

Viewer::~Viewer() {
}

void Viewer::glut_window_setup(int argc, char** argv){
	//create window the GLUT way
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);
	glutInitWindowSize(width_, height_);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - width_) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - height_) / 2);
	glutCreateWindow(name_.c_str());
}

void Viewer::x11_glx_window_setup(){
	//create window the screensaver way
    Setup_Display_Settings settings;
    settings.window.use_root = true;
    settings.window.pos.x = 0;
    settings.window.pos.y = 0;
    settings.window.dim.width = 860;
    settings.window.dim.height = 640;
    settings.window.border_width = 1;
    settings.window.border = 0;
    settings.window.background = 0;
    
    settings.use_glx = true;
    settings.glx_settings.visual_impl = 2;
    settings.glx_settings.context_impl = 2;
    x11 = X11_Main_State_Creator::Create(settings);
}

void Viewer::initGlut(int argc, char** argv) {
	
	if (use_glut){
		glut_window_setup(argc,argv);
	}else{
		x11_glx_window_setup();
	}
}

void Viewer::initGl() {
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

void Viewer::setModel(const ModelPtr& model) {
	model_ = model;
	modelRadius_ = model->radius();
	modelDistance_ = modelRadius_ * 2.0f;
	arcball_.setRadius(modelRadius_);
	
	Vector3f v;
	v(0) = 0.0f;
	v(1) = 0.0f;
	v(2) = -modelDistance_;
	arcball_.setCenter(v);
	
	farPlane_ = modelDistance_ + modelRadius_;
}

void Viewer::run_glut_loop() {
	if (!running_) {
		running_ = true;
		glutMainLoop();
	}
}
void Viewer::run_x11_glx_loop() {
	while(true){
		display();
	}
}

void Viewer::start() {
	
	if (use_glut){
		run_glut_loop();
	}else{
		run_x11_glx_loop();
	}
}

void Viewer::stop() {
	if (running_){
		glutLeaveMainLoop();
	}
}

void Viewer::idle() {
	glutPostRedisplay();
}

void Viewer::display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (GLfloat)width_/(GLfloat)height_, 0.1f, farPlane_);
	gluLookAt(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	Matrix3f rotation;
	
	if (mouseEnabled_)
		rotation = arcBallRotation_;
	else
		rotation = xRotation_ * yRotation_;

	Vector3f translation;
	translation(0) = 0.0f;
	translation(1) = 0.0f;
	translation(2) = -modelDistance_;

	Matrix4f transform = isometryMatrix(rotation, translation);
	glMultTransposeMatrixf(transform.data());
	
	model_->render();
	
	if (use_glut){
		glutSwapBuffers();
	}else{
		
		glXSwapBuffers(x11.d, x11.root);
	}
	
	//spin automatically
	Vector3f xAxis = Vector3f::zero();
	xAxis(0) = 1.0f;
	xRotation_ = xRotation_ * rotationMatrix(xAxis, degToRad(1.0f));
}

void Viewer::resize(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (GLfloat)width_/(GLfloat)height_, 0.1f, farPlane_);
	glMatrixMode(GL_MODELVIEW);
}

void Viewer::keyDown(unsigned char key, int x, int y) {
	switch (key) {
		case 27:	//escape
			stop();
			break;
		
		case 'm':
			mouseEnabled_ = !mouseEnabled_;
			break;
			
		case '+':
			zoomOut();
			break;
			
		case '-':
			zoomIn();
			break;
	}
}

void Viewer::specialKey(int key, int x, int y) {
	Vector3f xAxis = Vector3f::zero();
	Vector3f yAxis = Vector3f::zero();
	
	xAxis(0) = 1.0f;
	yAxis(1) = 1.0f;
	switch(key)	{
		case GLUT_KEY_UP:		
			xRotation_ = xRotation_ * rotationMatrix(xAxis, degToRad(-5.0f));
			break;

		case GLUT_KEY_DOWN:
			xRotation_ = xRotation_ * rotationMatrix(xAxis, degToRad(5.0f));
			break;
		
		case GLUT_KEY_LEFT:
			yRotation_ = yRotation_ * rotationMatrix(yAxis, degToRad(-5.0f));
			break;
		
		case GLUT_KEY_RIGHT:
			yRotation_ = yRotation_ * rotationMatrix(yAxis, degToRad(5.0f));
			break;
	}
}

void Viewer::mouse(int button, int state, int x, int y) {
	if (mouseEnabled_) {
		float v[] = {(float)x, (float)(height_ - y - 1)};
		Vector2f currentPos(v);
		
		if (GLUT_LEFT_BUTTON == button && GLUT_DOWN == state) {		
			startPos_ = currentPos;
			mouseDown_ = true;
		} else if (GLUT_LEFT_BUTTON == button && GLUT_UP == state) {
			if (startPos_.distance(currentPos) > 5.0f)
				arcBallRotation_ = arcball_.rotation(startPos_, currentPos) * arcBallRotation_;
			
			mouseDown_ = false;
		} else if (3 == button) {	//hack for mousewheel down
			zoomIn();
		} else if (4 == button) {	//hack for mousewheel up
			zoomOut();
		}
	}
}

void Viewer::mouseMove(int x, int y) {
	if (mouseEnabled_ && mouseDown_) {
		Vector2f currentPos;
		currentPos(0) = (float)x;
		currentPos(1) = (float)(height_ - y - 1);
		
		if (startPos_.distance(currentPos) > 5.0f) {
			arcBallRotation_ = arcball_.rotation(startPos_, currentPos) * arcBallRotation_;
			startPos_ = currentPos;
		}
	}
}

void Viewer::mouseWheel(int button, int dir, int x, int y) {
	if (mouseEnabled_) {
		if (dir > 0)
			zoomOut();
		else
			zoomIn();
	}
}

void Viewer::zoomIn() {
	if (modelDistance_ - modelRadius_ > 0.0f) {
		modelDistance_ -= modelRadius_ / 10.0f;
		farPlane_ = modelDistance_ + modelRadius_;
		
		Vector3f center;
		center(0) = 0.0f;
		center(1) = 0.0f;
		center(2) = -modelDistance_;
		arcball_.setCenter(center);
	}
}

void Viewer::zoomOut() {	
	modelDistance_ += modelRadius_ / 10.0f;
	farPlane_ = modelDistance_ + modelRadius_;
	
	Vector3f center;
	center(0) = 0.0f;
	center(1) = 0.0f;
	center(2) = -modelDistance_;
	arcball_.setCenter(center);
}

/*
 * Static callbacks
 */
void Viewer::setInstance(Viewer* instance) {
	instance_ = instance;
	
	if (use_glut){
		glutIdleFunc(idleCallback);
		glutDisplayFunc(displayCallback);
		glutKeyboardFunc(keyDownCallback);
		glutSpecialFunc(specialKeyCallback);
		glutMouseFunc(mouseCallback);
		glutMotionFunc(mouseMoveCallback);
		glutMouseWheelFunc(mouseWheelCallback);
	}
}

void Viewer::idleCallback() {
	instance_->idle();
}

void Viewer::displayCallback() {
	instance_->display();
}

void Viewer::resizeCallback(int width, int height) {
	instance_->resize(width, height);
}

void Viewer::keyDownCallback(unsigned char key, int x, int y) {
	instance_->keyDown(key, x, y);
}

void Viewer::specialKeyCallback(int key, int x, int y) {
	instance_->specialKey(key, x, y);
}

void Viewer::mouseCallback(int button, int state, int x, int y) {
	instance_->mouse(button, state, x, y);
}

void Viewer::mouseMoveCallback(int x, int y) {
	instance_->mouseMove(x, y);
}

void Viewer::mouseWheelCallback(int button, int dir, int x, int y) {
	instance_->mouseWheel(button, dir, x, y);
}
