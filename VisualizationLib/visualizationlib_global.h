#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(VISUALIZATIONLIB_LIB)
#  define VISUALIZATIONLIB_EXPORT Q_DECL_EXPORT
# else
#  define VISUALIZATIONLIB_EXPORT Q_DECL_IMPORT
# endif
#else
# define VISUALIZATIONLIB_EXPORT
#endif
