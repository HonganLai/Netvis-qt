#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(INTERACTIONLIB_LIB)
#  define INTERACTIONLIB_EXPORT Q_DECL_EXPORT
# else
#  define INTERACTIONLIB_EXPORT Q_DECL_IMPORT
# endif
#else
# define INTERACTIONLIB_EXPORT
#endif
