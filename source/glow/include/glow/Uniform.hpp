#pragma once

#include <glow/Uniform.h>

#include <glow/Program.h>
#include <glow/ProgramUniformSetter.h>
#include <glow/UniformSetter.h>

namespace glow
{

template<typename T>
Uniform<T>::Uniform(const std::string & name)
: Uniform(name, T())
{
}

template<typename T>
Uniform<T>::Uniform(const std::string & name, const T & value)
: AbstractUniform(name)
, m_value(value)
{
}

template<typename T>
Uniform<T>::~Uniform()
{
}

template<typename T>
const T & Uniform<T>::value() const
{
	return m_value;
}

template<typename T>
void Uniform<T>::setLocation(GLint location)
{
	set(location, m_value);
}

template<typename T>
void Uniform<T>::setProgramLocation(Program* program, GLint location)
{
    set(program->id(), location, m_value);
}

template<typename T>
void Uniform<T>::set(const T & value)
{
	m_value = value;
	changed();
}

template<typename T>
void Uniform<T>::set(GLint location, const T & value)
{
    UniformSetter::set(location, value);
}

template<typename T>
void Uniform<T>::set(GLuint program, GLint location, const T & value)
{
    ProgramUniformSetter::set(program, location, value);
}

} // namespace glow