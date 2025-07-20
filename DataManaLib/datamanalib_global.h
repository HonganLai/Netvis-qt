#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(DATAMANALIB_LIB)
#  define DATAMANALIB_EXPORT Q_DECL_EXPORT
# else
#  define DATAMANALIB_EXPORT Q_DECL_IMPORT
# endif
#else
# define DATAMANALIB_EXPORT
#endif
