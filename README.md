# simplemaths

**simplemaths** is a C module extension that implements the basic maths operation (sum, subs, mult and div).

The aim of this module is to show how to write an extension in C to extend the Power of Python.

Just enjoy.

## Instaling simplemaths

  $ pip3 install git+https://github.com/rancavil/simplemaths.git

or

 $ git clone https://github.com/rancavil/simplemaths.git
 $ cd simplemaths
 $ sudo python3 setup.py install

**Note:** The module is compatible with Python version 2 and 3.

## Example

The module implements the four basic maths operations.

      $ python3
      [GCC 6.4.1 20170727 (Red Hat 6.4.1-1)] on linux
      Type "help", "copyright", "credits" or "license" for more information.
      >>> import simplemaths as maths
      >>> maths.add(10,10)
      20
      >>> maths.sub(10,11)
      -1
      >>> maths.mult(10,10)
      100
      >>> maths.div(10,2)
      5
      >>>


