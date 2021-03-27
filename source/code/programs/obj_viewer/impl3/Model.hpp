#ifndef _MODEL_HPP
#define _MODEL_HPP

#include "Shaders.hpp"
#include "SmartPtr.hpp"

#include "Vector.hpp"

#include <GL/gl.h>
#include <SDL/SDL.h>

#include <string>
#include <vector>

class Texture {
	public:
		Texture(const std::string& file);
		virtual ~Texture();
		
		void load();
		void bind();
		
	private:
		std::string file_;
		bool loaded_;
		GLuint id_;
};

typedef SmartPtr<Texture> TexturePtr;

class Material {
	friend class Model;
	
	public:
		Material(const std::string& name);
		Material(const Material& material);
		Material& operator = (const Material& material);

		std::string name() const;

		void setKa(float a1, float a2, float a3);
		void setKd(float d1, float d2, float d3);
		void setKs(float s1, float s2, float s3);
		void setKe(float e1, float e2, float e3);
		
		void setTexture(const TexturePtr& texture);
		
	private:
		std::string name_;
		float ka_[4];
		float kd_[4];
		float ks_[4];
		float ke_[4];
		TexturePtr texture_;
};

typedef SmartPtr<Material> MaterialPtr;

class Face {
	friend class Model;
	
	public:
		Face();
		Face(const MaterialPtr& material);
		
		void addVertexIndex(unsigned int index);
		void addNormalIndex(unsigned int index);
		void addTexCoordIndex(unsigned int index);
		
	private:
		MaterialPtr material_;
		std::vector<unsigned int> vertexIndices_;
		std::vector<unsigned int> normalIndices_;
		std::vector<unsigned int> texCoordIndices_;
};

typedef SmartPtr<Face> FacePtr;

class Group {
	friend class Model;
	
	public:
		Group(unsigned int id, const MaterialPtr& material);
		
		void addFace(const FacePtr& face);
		
	private:
		int id_;
		std::string name_;
		std::vector<FacePtr> faces_;
		MaterialPtr material_;
};

typedef SmartPtr<Group> GroupPtr;

class Model {
	public:
		Model();
		
		void setUseParams(bool useParams);
		
		//adds vertices, normals, and texture coordinates
		void addVertex(const Point3f& vertex);
		void addNormal(const Point3f& normal);
		void addTexCoord(const Point2f& coord);
		
		//computes the model's centroid
		void centroid();
		
		//computes the maximum distance of all points from the centroid
		float radius();
		
		//centers the model on it's centroid
		void center();
		
		//adds a group of faces (determined by 'usemtl' directives) to the model
		void addGroup(const GroupPtr& group);
		
		//loads all textures associated with the model
		void loadTextures();
		
		//compiles all display lists associated with the model
		void compileLists();
		
		//sets vertex/fragment shaders
		void setShaders(ShadersPtr shaders);
		
		//renders the model
		void render();
		
	private:
		bool useParams_;
		Vector3f centroid_;
		std::vector<Point3f> vertices_;
		std::vector<Point3f> normals_;
		std::vector<Point2f> texCoords_;
		std::vector<GroupPtr> groups_;
		ShadersPtr shaders_;
};

typedef SmartPtr<Model> ModelPtr;

#endif
