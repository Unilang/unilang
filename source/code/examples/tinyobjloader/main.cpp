#include <iostream>
#include <string>
#include "code/utilities/formats/obj/loaded_obj_reader_getter.hpp"

int main(){

  auto reader = Loaded_Obj_Reader_Getter::Get("/home/luxe/Desktop/glExamples/src/examples/05-hello_mesh/","test_mesh");

  auto& attrib = reader.GetAttrib();
  auto& shapes = reader.GetShapes();
  auto& materials = reader.GetMaterials();

  // Loop over shapes
  for (size_t s = 0; s < shapes.size(); s++) {
    // Loop over faces(polygon)
    size_t index_offset = 0;
    for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++) {
      int fv = shapes[s].mesh.num_face_vertices[f];

      // Loop over vertices in the face.
      for (size_t v = 0; v < fv; v++) {
        // access to vertex
        tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];
        tinyobj::real_t vx = attrib.vertices[3*idx.vertex_index+0];
        tinyobj::real_t vy = attrib.vertices[3*idx.vertex_index+1];
        tinyobj::real_t vz = attrib.vertices[3*idx.vertex_index+2];
        tinyobj::real_t nx = attrib.normals[3*idx.normal_index+0];
        tinyobj::real_t ny = attrib.normals[3*idx.normal_index+1];
        tinyobj::real_t nz = attrib.normals[3*idx.normal_index+2];
        tinyobj::real_t tx = attrib.texcoords[2*idx.texcoord_index+0];
        tinyobj::real_t ty = attrib.texcoords[2*idx.texcoord_index+1];
        
        // Optional: vertex colors
        // tinyobj::real_t red = attrib.colors[3*idx.vertex_index+0];
        // tinyobj::real_t green = attrib.colors[3*idx.vertex_index+1];
        // tinyobj::real_t blue = attrib.colors[3*idx.vertex_index+2];
        
        std::cout << vx << std::endl;
      }
      index_offset += fv;

      // per-face material
      shapes[s].mesh.material_ids[f];
    }
  }
}