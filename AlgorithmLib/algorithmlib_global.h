#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(ALGORITHMLIB_LIB)
#  define ALGORITHMLIB_EXPORT Q_DECL_EXPORT
# else
#  define ALGORITHMLIB_EXPORT Q_DECL_IMPORT
# endif
#else
# define ALGORITHMLIB_EXPORT
#endif
