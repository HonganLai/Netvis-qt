#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(DATADRVLIB_LIB)
#  define DATADRVLIB_EXPORT Q_DECL_EXPORT
# else
#  define DATADRVLIB_EXPORT Q_DECL_IMPORT
# endif
#else
# define DATADRVLIB_EXPORT
#endif
