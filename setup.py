#!/usr/bin/env python3
#
#       setup.py
#       Copyright (C) 2020  Rodrigo Ancavil del Pino
#       Email   rancavil@yinnovaser.cl
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
#
from distutils.core import setup, Extension

module=Extension('simplemaths',sources=['maths.c'])
setup(name='simplemaths',
      version='1.0',
      description='Simple C Maths',
      author='Rodrigo Ancavil del Pino',
      author_email='rancavil@innovaser.cl',
      ext_modules = [module,])
