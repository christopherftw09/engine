//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Object Loader (Header)
//

#pragma once
#include <vector>
#include <stdio.h>
#include <string>
#include <cstring>

#include "Vector2.h"
#include "Vector3.h"

bool loadOBJ(const char* path, std::vector<Vector3>& out_vertices, std::vector<Vector2>& out_uvs, std::vector<Vector3>& out_normals);
bool loadAssImp(const char* path, std::vector<unsigned short> & indices, std::vector<Vector3> & vertices, std::vector<Vector2> & uvs, std::vector<Vector3> & normals);