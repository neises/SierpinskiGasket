#pragma once
#include "glew.h"
#include <cmath>
#include <iostream>

// Define a helpful macro for handling offsets into buffer objects
#define BUFFER_OFFSET( offset )   ((GLvoid*) (offset))

namespace Utility
{



	//  Define M_PI in the case it's not defined in the math header file
#ifndef M_PI
#  define M_PI  3.14159265358979323846
#endif


	const GLfloat	DivideByZeroTolerance = GLfloat(1.0e-07);
	const GLfloat	DegreesToRadians = M_PI / 180.0f;



	static char* readShaderSource(const char* shaderFile)
	{
		FILE* fp = fopen(shaderFile, "rb");

		if (fp == NULL) { return NULL; }

		fseek(fp, 0L, SEEK_END);
		long size = ftell(fp);

		fseek(fp, 0L, SEEK_SET);
		char* buf = new char[size + 1];
		fread(buf, 1, size, fp);

		buf[size] = '\0';
		fclose(fp);

		return buf;
	}


	GLuint InitShader(const char* _vShaderFile, const char* _fShaderFile)
	{
		struct Shader {
			const char*  filename;
			GLenum       type;
			GLchar*      source;
		}  shaders[2] = {
			{ _vShaderFile, GL_VERTEX_SHADER, NULL },
		{ _fShaderFile, GL_FRAGMENT_SHADER, NULL }
		};

		GLuint program = glCreateProgram();

		for (int i = 0; i < 2; ++i) {
			Shader& s = shaders[i];
			s.source = readShaderSource(s.filename);
			if (shaders[i].source == NULL) {
				std::cerr << "Failed to read " << s.filename << std::endl;
				exit(EXIT_FAILURE);
			}

			GLuint shader = glCreateShader(s.type);
			glShaderSource(shader, 1, (const GLchar**)&s.source, NULL);
			glCompileShader(shader);

			GLint  compiled;
			glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
			if (!compiled) {
				std::cerr << s.filename << " failed to compile:" << std::endl;
				GLint  logSize;
				glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logSize);
				char* logMsg = new char[logSize];
				glGetShaderInfoLog(shader, logSize, NULL, logMsg);
				std::cerr << logMsg << std::endl;
				delete[] logMsg;

				exit(EXIT_FAILURE);
			}

			delete[] s.source;

			glAttachShader(program, shader);
		}

		/* link  and error check */
		glLinkProgram(program);

		GLint  linked;
		glGetProgramiv(program, GL_LINK_STATUS, &linked);
		if (!linked) {
			std::cerr << "Shader program failed to link" << std::endl;
			GLint  logSize;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logSize);
			char* logMsg = new char[logSize];
			glGetProgramInfoLog(program, logSize, NULL, logMsg);
			std::cerr << logMsg << std::endl;
			delete[] logMsg;

			exit(EXIT_FAILURE);
		}

		/* use program object */
		glUseProgram(program);

		return program;
	}

}

#include "Vec.h"
