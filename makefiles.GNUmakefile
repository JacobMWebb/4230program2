##---------------------------------------------------------------------------
# Replace my_program with the name of the program that you are trying to
# compile.  Do not include the trailing .c

PROGS = JMWP2



##---------------------------------------------------------------------------
## you should not have to change anything below this line


##### MACROS #####

CC = gcc
GL_LIB = libGL.so
GLU_LIB = libGLU.so
GLUT_LIB = libglut.so
GLW_LIB = libGLw.so

CFLAGS = -O3 -pedantic -fPIC -ffast-math -D_SVID_SOURCE -D_BSD_SOURCE -DUSE_XSHM -DPTHREADS -I/usr/X11R6/include

GL_LIB_DEPS = -L/usr/X11R6/lib -lX11 -lXext -lm -lpthread

GLU_LIB_DEPS = -L../lib -lGL -lm

GLUT_LIB_DEPS = -L../lib -lGLU -lGL -L/usr/X11R6/lib -lX11 -lXmu -lXt -lXi -lm

APP_LIB_DEPS = -lm


INCDIR = ../include
LIBDIR = ../lib

GL_LIBS = -L$(LIBDIR) -lglut -lGLU -lGL $(APP_LIB_DEPS)

LIB_DEP = $(LIBDIR)/$(GL_LIB) $(LIBDIR)/$(GLU_LIB) $(LIBDIR)/$(GLUT_LIB)


##### RULES #####

.SUFFIXES:
.SUFFIXES: .c

.c: $(LIB_DEP)
	$(CC) -I$(INCDIR) $(CFLAGS) $< $(GL_LIBS) -o $@



##### TARGETS #####

targets: $(PROGS)
