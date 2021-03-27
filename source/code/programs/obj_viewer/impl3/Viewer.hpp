#ifndef _VIEWER_HPP
#define _VIEWER_HPP

#include "Arcball.hpp"
#include "Model.hpp"
#include "Matrix.hpp"

#include <string>

class Viewer {
	public:
		Viewer(std::string name, int width, int height);
		virtual ~Viewer();
		
		void initGlut(int argc, char** argv);
		void initGl();
			void glut_window_setup(int argc, char** argv);
			void x11_glx_window_setup();
		
		void setModel(const ModelPtr& model);
		
		void start();
			void run_glut_loop();
			void run_x11_glx_loop();

		void stop();
		
		void idle();
		void display();
		void resize(int width, int height);
		void keyDown(unsigned char key, int x, int y);
		void specialKey(int key, int x, int y);
		void mouse(int button, int state, int x, int y);
		void mouseMove(int x, int y);
		void mouseWheel(int button, int dir, int x, int y);
		
		static void setInstance(Viewer* instance);
	
		static void idleCallback();
		static void displayCallback();
		static void resizeCallback(int width, int height);
		static void keyDownCallback(unsigned char key, int x, int y);
		static void specialKeyCallback(int key, int x, int y);
		static void mouseCallback(int button, int state, int x, int y);
		static void mouseMoveCallback(int x, int y);
		static void mouseWheelCallback(int button, int dir, int x, int y);
		
	private:
		static Viewer* instance_;
		std::string name_;
		int width_, height_, windowId_;
		bool running_, mouseEnabled_, mouseDown_;
		ModelPtr model_;
		Arcball arcball_;
		Vector2f startPos_;
		Matrix3f arcBallRotation_, xRotation_, yRotation_;
		float farPlane_, modelDistance_, modelRadius_;
		
		void zoomIn();
		void zoomOut();
};



#endif
