/*
*       maths.c
*       Copyright (C) 2020  Rodrigo Ancavil del Pino
*       Email   rancavil@yinnovaser.cl
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include <Python.h>
#include <stdio.h>

static PyObject *simplemathsError;

PyObject *add(PyObject *self,PyObject *args)
{
	int a, b, result;

	if(!PyArg_ParseTuple(args,"ii",&a,&b)) {
		PyErr_SetString(simplemathsError,"You have to enter two values");
		return NULL;
	}

	result = a + b;
	return Py_BuildValue("i",result);
}

PyObject *sub(PyObject *self,PyObject *args)
{
	int a, b, result;

	if(!PyArg_ParseTuple(args,"ii",&a,&b)) {
		PyErr_SetString(simplemathsError,"You have to enter two values");
		return NULL;
	}

	result = a - b;
	return Py_BuildValue("i",result);
}

PyObject *mult(PyObject *self,PyObject *args)
{
	int a, b, result;

	if(!PyArg_ParseTuple(args,"ii",&a,&b)) {
		PyErr_SetString(simplemathsError,"You have to enter two values");
		return NULL;
	}

	result = a * b;
	return Py_BuildValue("i",result);
}

PyObject *divide(PyObject *self,PyObject *args)
{
	int a, b, result;

	if(!PyArg_ParseTuple(args,"ii",&a,&b)) {
		PyErr_SetString(simplemathsError,"You have to enter two values");
		return NULL;
	}

	if(b == 0) {
		PyErr_SetString(simplemathsError,"You can't divide by zero");
		return NULL;
	}
	result = a / b;
	return Py_BuildValue("i",result);
}

static PyMethodDef Methods[] = {
        {"add",add,METH_VARARGS,"add two integer numbers"},
        {"sub",sub,METH_VARARGS,"sub two integer numbers"},
        {"mult",mult,METH_VARARGS,"mult integer two numbers"},
        {"div",divide,METH_VARARGS,"divide integer two numbers"},
        {NULL,NULL,0,NULL}
};

struct module_state {
        PyObject *error;
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef moduledef = {
        PyModuleDef_HEAD_INIT,
        "simplemaths",
        NULL,
        sizeof(struct module_state),
        Methods,
        NULL,
        NULL,
        NULL,
        NULL
};
PyMODINIT_FUNC
PyInit_simplemaths(void)
#else
void initsimplemaths(void)
#endif
{
	simplemathsError = PyErr_NewException("simplemaths.simplemathsError",NULL,NULL);

#if PY_MAJOR_VERSION >= 3
        PyObject *mod = PyModule_Create(&moduledef);
        return mod;
#else
        Py_InitModule("simplemaths",Methods);
#endif
}

